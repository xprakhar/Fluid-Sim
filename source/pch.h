#pragma once

#if !defined(VK_NO_PROTOTYPES)
#define VK_NO_PROTOTYPES
#endif // VK_NO_PROTOTYPES
#include <vulkan/vulkan.h>

#include <vulkan/vk_enum_string_helper.h>

#if !defined(GLFW_INCLUDE_VULKAN)
#define GLFW_INCLUDE_VULKAN
#endif // GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include "../external/volk/volk.h"

#include <array>
#include <vector>
#include <string>
#include <unordered_set>
#include <utility>
#include <iostream>
#include <sstream>
#include <source_location>

#define VK_CHECK(oper) \
do {\
	VkResult result_ = oper; \
	const auto& loc_ = std::source_location::current(); \
	if (result_ != VK_SUCCESS) { \
		std::cerr << #oper << " failed" << std::endl; \
		std::cerr << "Vulkan Error [" << result_ << "]: " << string_VkResult(result_) << std::endl; \
		std::cerr << "at " << loc_.file_name() << ":" << loc_.line() << std::endl; \
		std::terminate(); \
	} \
} while (false)
