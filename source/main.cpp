#include "pch.h"

GLFWwindow* Window;
VkInstance Instance;
VkSurfaceKHR Surface;
VkPhysicalDevice Adapter;
VkDevice Device;
VkQueue GraphicsQueue;
VkQueue ComputeQueue;
VkQueue PresentQueue;

uint32_t GraphicsIndex = UINT32_MAX;
uint32_t PresentIndex = UINT32_MAX;
uint32_t ComputeIndex = UINT32_MAX;

VKAPI_ATTR VkBool32 VKAPI_CALL debugCallbackFunc(
	VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
	VkDebugUtilsMessageTypeFlagsEXT messageTypes,
	const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
	void* pUserData
) {

	std::ostringstream message;

	message << string_VkDebugUtilsMessageSeverityFlagBitsEXT(messageSeverity) << ": "
		<< string_VkDebugUtilsMessageTypeFlagsEXT(messageTypes) << ":\n";
	message << std::string("\t") << "messageIDName   = <" << pCallbackData->pMessageIdName << ">\n";
	message << std::string("\t") << "messageIdNumber = " << pCallbackData->messageIdNumber << "\n";
	message << std::string("\t") << "message         = <" << pCallbackData->pMessage << ">\n";
	if (0 < pCallbackData->queueLabelCount)
	{
		message << std::string("\t") << "Queue Labels:\n";
		for (uint32_t i = 0; i < pCallbackData->queueLabelCount; i++)
		{
			message << std::string("\t\t") << "labelName = <" << pCallbackData->pQueueLabels[i].pLabelName << ">\n";
		}
	}
	if (0 < pCallbackData->cmdBufLabelCount)
	{
		message << std::string("\t") << "CommandBuffer Labels:\n";
		for (uint32_t i = 0; i < pCallbackData->cmdBufLabelCount; i++)
		{
			message << std::string("\t\t") << "labelName = <" << pCallbackData->pCmdBufLabels[i].pLabelName << ">\n";
		}
	}
	if (0 < pCallbackData->objectCount)
	{
		message << std::string("\t") << "Objects:\n";
		for (uint32_t i = 0; i < pCallbackData->objectCount; i++)
		{
			message << std::string("\t\t") << "Object " << i << "\n";
			message << std::string("\t\t\t") << "objectType   = " << string_VkObjectType(pCallbackData->pObjects[i].objectType) << "\n";
			message << std::string("\t\t\t") << "objectHandle = " << pCallbackData->pObjects[i].objectHandle << "\n";
			if (pCallbackData->pObjects[i].pObjectName)
			{
				message << std::string("\t\t\t") << "objectName   = <" << pCallbackData->pObjects[i].pObjectName << ">\n";
			}
		}
	}

	std::cerr << message.str() << std::endl;

	return VK_FALSE;
}

void initialize() {
	if (glfwInit() != GLFW_TRUE) {
		std::cerr << "Failed to initialize glfw." << std::endl;
		std::terminate();
	}

	if (glfwVulkanSupported() != GLFW_TRUE) {
		std::cerr << "Failed to find a vulkan loader." << std::endl;
		std::terminate();
	}

	VK_CHECK(volkInitialize());

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	Window = glfwCreateWindow(1280, 720, "Fluid-Sim", nullptr, nullptr);
	if (!Window) {
		std::cerr << "Failed to create window." << std::endl;
		std::terminate();
	}
	
	// create instance
	{
		VkApplicationInfo appInfo{};
		appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
		appInfo.pNext = nullptr;
		appInfo.pApplicationName = "BitWave";
		appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
		appInfo.pEngineName = "No Engine";
		appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
		appInfo.apiVersion = VK_API_VERSION_1_3;

		uint32_t extensionCount;
		const char** glfwExtensions = glfwGetRequiredInstanceExtensions(&extensionCount);

		VkInstanceCreateInfo instanceInfo{};
		instanceInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		instanceInfo.enabledExtensionCount = extensionCount;
		instanceInfo.ppEnabledExtensionNames = glfwExtensions;

#ifdef _DEBUG

		VkDebugUtilsMessengerCreateInfoEXT debugMessengerInfo{};
		debugMessengerInfo.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
		debugMessengerInfo.pNext = nullptr;
		debugMessengerInfo.flags = 0;
		debugMessengerInfo.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT |
			VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT |
			VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT |
			VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT;
		debugMessengerInfo.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT |
			VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT |
			VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT |
			VK_DEBUG_UTILS_MESSAGE_TYPE_DEVICE_ADDRESS_BINDING_BIT_EXT;
		debugMessengerInfo.pfnUserCallback = debugCallbackFunc;
		debugMessengerInfo.pUserData = nullptr;

		instanceInfo.pNext = &debugMessengerInfo;

		std::vector<const char*> instanceExtensions{ glfwExtensions, glfwExtensions + extensionCount };
		instanceInfo.enabledExtensionCount = static_cast<uint32_t>(instanceExtensions.size());
		instanceInfo.ppEnabledExtensionNames = instanceExtensions.data();

		std::vector<const char*> instanceLayers{ "VK_LAYER_KHRONOS_validation" };
		instanceInfo.enabledLayerCount = static_cast<uint32_t>(instanceLayers.size());
		instanceInfo.ppEnabledLayerNames = instanceLayers.data();
#endif // _DEBUG

		VK_CHECK(vkCreateInstance(&instanceInfo, nullptr, &Instance));
		volkLoadInstanceOnly(Instance);

		VK_CHECK(glfwCreateWindowSurface(Instance, Window, nullptr, &Surface));
	}

	// create Device
	{
		uint32_t deviceCount;
		VK_CHECK(vkEnumeratePhysicalDevices(Instance, &deviceCount, nullptr));

		if (deviceCount <= 0) {
			std::cerr << "An error occurred while enumerating physical devices." << std::endl;
			std::terminate();
		}

		std::vector<VkPhysicalDevice> physicalDevices{ deviceCount };
		VK_CHECK(vkEnumeratePhysicalDevices(Instance, &deviceCount, physicalDevices.data()));

		for (uint32_t i = 0; i < deviceCount; ++i) {
			uint32_t queueFamilyCount;
			vkGetPhysicalDeviceQueueFamilyProperties(physicalDevices[i], &queueFamilyCount, nullptr);

			if (queueFamilyCount <= 0) {
				std::cerr << "queue family count = 0...skipping" << std::endl;
				continue;
			}

			std::vector<VkQueueFamilyProperties> queueFamilies{ queueFamilyCount };
			vkGetPhysicalDeviceQueueFamilyProperties(physicalDevices[i], &queueFamilyCount, queueFamilies.data());

			bool suitable = false;
			uint32_t graphicsFamily = UINT32_MAX;
			uint32_t presentFamily = UINT32_MAX;
			uint32_t computeFamily = UINT32_MAX;
			for (uint32_t j = 0; j < queueFamilyCount; ++j) {

				if (graphicsFamily == UINT32_MAX && queueFamilies[i].queueFlags & VK_QUEUE_GRAPHICS_BIT) {

					graphicsFamily = j;

				}


				if (computeFamily == UINT32_MAX && queueFamilies[i].queueFlags & VK_QUEUE_COMPUTE_BIT) {

					computeFamily = j;

				}

				VkBool32 support;
				vkGetPhysicalDeviceSurfaceSupportKHR(physicalDevices[i], j, Surface, &support);

				if (presentFamily == UINT32_MAX && support) {
					presentFamily = j;
				}

				if (graphicsFamily != UINT32_MAX && presentFamily != UINT32_MAX 
						&& computeFamily != UINT32_MAX) {
					suitable = true;
					break;
				}

			}

			if (suitable) {
				Adapter = physicalDevices[i];
				GraphicsIndex = graphicsFamily;
				PresentIndex = presentFamily;
				ComputeIndex = computeFamily;
				break;
			}

		}

		float priorities[] = { 1.0f };
		std::vector<VkDeviceQueueCreateInfo> queueInfos;
		std::unordered_set<uint32_t> indices{GraphicsIndex, PresentIndex, ComputeIndex};

		queueInfos.reserve(indices.size());
		for (auto index : indices) {
			VkDeviceQueueCreateInfo queueInfo{};
			queueInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
			queueInfo.queueFamilyIndex = index;
			queueInfo.queueCount = 1;
			queueInfo.pQueuePriorities = priorities;
			queueInfos.push_back(queueInfo);
		}


		std::array<const char*, 1> deviceExtensions{VK_KHR_SWAPCHAIN_EXTENSION_NAME};

		VkDeviceCreateInfo deviceInfo{};
		deviceInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
		deviceInfo.queueCreateInfoCount = static_cast<uint32_t>(queueInfos.size());
		deviceInfo.pQueueCreateInfos = queueInfos.data();
		deviceInfo.enabledExtensionCount = static_cast<uint32_t>(deviceExtensions.size());
		deviceInfo.ppEnabledExtensionNames = deviceExtensions.data();

		VK_CHECK(vkCreateDevice(Adapter, &deviceInfo, nullptr, &Device));
		volkLoadDevice(Device);

		vkGetDeviceQueue(Device, GraphicsIndex, 0, &GraphicsQueue);
		vkGetDeviceQueue(Device, PresentIndex, 0, &PresentQueue);
		vkGetDeviceQueue(Device, ComputeIndex, 0, &ComputeQueue);
	}
}

void cleanup() {
	vkDeviceWaitIdle(Device);
	vkDestroyDevice(Device, nullptr);
	vkDestroySurfaceKHR(Instance, Surface, nullptr);
	vkDestroyInstance(Instance, nullptr);
	glfwDestroyWindow(Window);
	glfwTerminate();
}

int main()
{
	initialize();

	while (!glfwWindowShouldClose(Window)) {
		glfwPollEvents();
	}

	cleanup();

	return 0;
}
