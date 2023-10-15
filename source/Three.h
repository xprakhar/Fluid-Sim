#include <immintrin.h>
#include <stdint.h>

#include <DirectXMath.h>

#if defined(_MSC_VER)
#define CALL_CONV __vectorcall
#else
#define CALL_CONV
#endif  // CALL COnv

namespace Three {

	using Vector = __m128;
	using Matrix = struct {
		Vector r1, r2, r3, r4;
	};

	/*
	----------------------------------------------
	|              Data Types                    |
	----------------------------------------------
	*/
	struct Vec2 {
		float x;
		float y;

		Vec2() = default;

		Vec2(const Vec2&) = default;
		Vec2& operator=(const Vec2&) = default;

		Vec2(Vec2&&) = default;
		Vec2& operator=(Vec2&&) = default;

		constexpr Vec2(float _x, float _y) noexcept : x(_x), y(_y) {}
		explicit Vec2(const float* pArray) noexcept : x(pArray[0]), y(pArray[1]) {}

	};

	struct alignas(16) Vec2_a : public Vec2 {
		using Vec2::Vec2;
	};

	struct Vec2_i {
		int32_t x;
		int32_t y;

		Vec2_i() = default;

		Vec2_i(const Vec2_i&) = default;
		Vec2_i& operator=(const Vec2_i&) = default;

		Vec2_i(Vec2_i&&) = default;
		Vec2_i& operator=(Vec2_i&&) = default;

		constexpr Vec2_i(int32_t _x, int32_t _y) noexcept : x(_x), y(_y) {}
		explicit Vec2_i(const int32_t* pArray) noexcept : x(pArray[0]), y(pArray[1]) {}
	};

	struct Vec2_u {
		uint32_t x;
		uint32_t y;

		Vec2_u() = default;

		Vec2_u(const Vec2_u&) = default;
		Vec2_u& operator=(const Vec2_u& other) = default;

		Vec2_u(Vec2_u&&) = default;
		Vec2_u& operator=(Vec2_u&&) = default;

		constexpr Vec2_u(uint32_t _x, uint32_t _y) noexcept : x(_x), y(_y) {}
		explicit Vec2_u(const uint32_t* pArray) noexcept : x(pArray[0]), y(pArray[1]) {}
	};


	struct Vec3 {
		float x;
		float y;
		float z;

		Vec3() = default;

		Vec3(const Vec3&) = default;
		Vec3& operator=(const Vec3&) = default;

		Vec3(Vec3&&) = default;
		Vec3& operator=(Vec3&&) = default;

		constexpr Vec3(float _x, float _y, float _z) noexcept : x(_x), y(_y), z(_z) {}
		explicit Vec3(const float* pArray) noexcept : x(pArray[0]), y(pArray[1]), z(pArray[2]) {}
	};

	struct alignas(16) Vec3_a : public Vec3 {
		using Vec3::Vec3;
	};

	struct Vec3_i {
		int32_t x; 
		int32_t y;
		int32_t z;

		Vec3_i() = default;

		Vec3_i(const Vec3_i&) = default;
		Vec3_i& operator=(const Vec3_i&) = default;

		Vec3_i(Vec3_i&&) = default;
		Vec3_i& operator=(Vec3_i&&) = default;

		constexpr Vec3_i(int32_t _x, int32_t _y, int32_t _z) noexcept : x(_x), y(_y), z(_z) {}
		explicit Vec3_i(const int32_t* pArray) noexcept : x(pArray[0]), y(pArray[1]), z(pArray[2]) {}
	};

	struct Vec3_u {
		uint32_t x;
		uint32_t y;
		uint32_t z;

		Vec3_u() = default;

		Vec3_u(const Vec3_u&) = default;
		Vec3_u& operator=(const Vec3_u&) = default;

		Vec3_u(Vec3_u&&) = default;
		Vec3_u& operator=(Vec3_u&&) = default;

		constexpr Vec3_u(uint32_t _x, uint32_t _y, uint32_t _z) noexcept : x(_x), y(_y), z(_z) {}
		explicit Vec3_u(const uint32_t* pArray) noexcept : x(pArray[0]), y(pArray[1]), z(pArray[2]) {}
	};


	struct Vec4 {
		float x;
		float y;
		float z;
		float w;

		Vec4() = default;

		Vec4(const Vec4&) = default;
		Vec4& operator=(const Vec4&) = default;

		Vec4(Vec4&&) = default;
		Vec4& operator=(Vec4&&) = default;

		constexpr Vec4(float _x, float _y, float _z, float _w) noexcept : x(_x), y(_y), z(_z), w(_w) {}
		explicit Vec4(const float* pArray) noexcept : x(pArray[0]), y(pArray[1]), z(pArray[2]), w(pArray[3]) {}
	};

	struct alignas(16) Vec4_a : public Vec4 {
		using Vec4::Vec4;
	};

	struct Vec4_i {
		int32_t x;
		int32_t y;
		int32_t z;
		int32_t w;

		Vec4_i() = default;

		Vec4_i(const Vec4_i&) = default;
		Vec4_i& operator=(const Vec4_i&) = default;

		Vec4_i(Vec4_i&&) = default;
		Vec4_i& operator=(Vec4_i&&) = default;

		constexpr Vec4_i(int32_t _x, int32_t _y, int32_t _z, int32_t w) noexcept : x(_x), y(_y), z(_z), w(_w) {}
		explicit Vec4_i(const int32_t* pArray) noexcept : x(pArray[0]), y(pArray[1]), z(pArray[2]), w(pArray[3]) {}

	};

	struct Vec4_u {
		uint32_t x;
		uint32_t y;
		uint32_t z;
		uint32_t w;

		Vec4_u() = default;

		Vec4_u(const Vec4_u&) = default;
		Vec4_u& operator=(const Vec4_u&) = default;

		Vec4_u(Vec4_u&&) = default;
		Vec4_u& operator=(Vec4_u&&) = default;

		constexpr Vec4_u(uint32_t _x, uint32_t _y, uint32_t _z, uint32_t w) noexcept : x(_x), y(_y), z(_z), w(_w) {}
		explicit Vec4_u(const uint32_t* pArray) noexcept : x(pArray[0]), y(pArray[1]), z(pArray[2]), w(pArray[3]) {}
	};

	struct Mat3 {
	
		union {
			struct {
				float _11, _12, _13;
				float _21, _22, _23;
				float _31, _32, _33;
			};
			float m[3][3];
		};

		Mat3() = default;

		Mat3(const Mat3&) = default;
		Mat3& operator=(const Mat3&) = default;

		Mat3(Mat3&&) = default;
		Mat3& operator=(Mat3&&) = default;

		constexpr Mat3(float m00, float m01, float m02,
			float m10, float m11, float m12,
			float m20, float m21, float m22) noexcept
			: _11(m00), _12(m01), _13(m02),
			_21(m10), _22(m11), _23(m12),
			_31(m20), _32(m21), _33(m22) {}

		explicit Mat3(const float* pArray) noexcept
			: _11(pArray[0]), _12(pArray[1]), _13(pArray[2]),
			_21(pArray[3]), _22(pArray[4]), _23(pArray[5]),
			_31(pArray[6]), _32(pArray[7]), _33(pArray[8]) {}

		float operator() (size_t row, size_t col) const noexcept { return m[row][col]; }
		float& operator() (size_t row, size_t col) noexcept { return m[row][col]; }
	};

	struct Mat3x4 {
	
		union {
			struct {
				float _11, _12, _13, _14;
				float _21, _22, _23, _24;
				float _31, _32, _33, _34;
			};
			float m[3][4];
			float f[12];
		};

		Mat3x4() = default;

		Mat3x4(const Mat3x4&) = default;
		Mat3x4& operator=(const Mat3x4&) = default;

		Mat3x4(Mat3x4&&) = default;
		Mat3x4& operator=(Mat3x4&&) = default;

		constexpr Mat3x4(float m00, float m01, float m02, float m03,
			float m10, float m11, float m12, float m13,
			float m20, float m21, float m22, float m23) noexcept
			: _11(m00), _12(m01), _13(m02), _14(m03),
			_21(m10), _22(m11), _23(m12), _24(m13),
			_31(m20), _32(m21), _33(m22), _34(m23) {}
		explicit Mat3x4(const float* pArray) noexcept 
			: _11(pArray[0]), _12(pArray[1]), _13(pArray[2]), _14(pArray[3]),
			_21(pArray[4]), _22(pArray[5]), _23(pArray[6]), _24(pArray[7]),
			_31(pArray[8]), _32(pArray[9]), _33(pArray[10]), _34(pArray[11]) {}

		float operator() (size_t row, size_t col) const noexcept { return m[row][col]; }
		float& operator() (size_t row, size_t col) noexcept { return m[row][col]; }
	};

	struct alignas(16) Mat3x4_a : public Mat3x4 {
		using Mat3x4::Mat3x4;
	};

	struct Mat4x3 {
	
		union {
			struct {
				float _11, _12, _13;
				float _21, _22, _23;
				float _31, _32, _33;
				float _41, _42, _43;
			};
			float m[4][3];
			float f[12];
		};

		Mat4x3() = default;

		Mat4x3(const Mat4x3&) = default;
		Mat4x3& operator=(const Mat4x3&) = default;

		Mat4x3(Mat4x3&&) = default;
		Mat4x3& operator=(Mat4x3&&) = default;

		constexpr XMFLOAT4X3(float m00, float m01, float m02,
			float m10, float m11, float m12,
			float m20, float m21, float m22,
			float m30, float m31, float m32) noexcept
			: _11(m00), _12(m01), _13(m02),
			_21(m10), _22(m11), _23(m12),
			_31(m20), _32(m21), _33(m22),
			_41(m30), _42(m31), _43(m32) {}
		explicit Mat4x3(const float* pArray) noexcept
			: _11(pArray[0]), _12(pArray[1]), _13(pArray[2]),
			_21(pArray[3]), _22(pArray[4]), _23(pArray[5]),
			_31(pArray[6]), _32(pArray[7]), _33(pArray[8]),
			_41(pArray[9]), _42(pArray[10]), _43(pArray[11]) {}

		float operator() (size_t row, size_t col) const noexcept { return m[row][col]; }
		float& operator() (size_t row, size_t col) noexcept { return m[row][col]; }
	};

	struct alignas(16) Mat4x3_a : public Mat4x3 {
		using Mat4x3::Mat4x3;
	};

	struct Mat4 {
	
		union {
			struct {
				float _11, _12, _13, _14;
				float _21, _22, _23, _24;
				float _31, _32, _33, _34;
				float _41, _42, _43, _44;
			};
			float m[4][4];
		};

		Mat4() = default;

		Mat4(const Mat4&) = default;
		Mat4& operator=(const Mat4&) = default;

		Mat4(Mat4&&) = default;
		Mat4& operator=(Mat4&&) = default;

		constexpr Mat4(float m00, float m01, float m02, float m03,
			float m10, float m11, float m12, float m13,
			float m20, float m21, float m22, float m23,
			float m30, float m31, float m32, float m33) noexcept
			: _11(m00), _12(m01), _13(m02), _14(m03),
			_21(m10), _22(m11), _23(m12), _24(m13),
			_31(m20), _32(m21), _33(m22), _34(m23),
			_41(m30), _42(m31), _43(m32), _44(m33) {}
		explicit Mat4(const float* pArray) noexcept
			: _11(pArray[0]), _12(pArray[1]), _13(pArray[2]), _14(pArray[3]),
			_21(pArray[4]), _22(pArray[5]), _23(pArray[6]), _24(pArray[7]),
			_31(pArray[8]), _32(pArray[9]), _33(pArray[10]), _34(pArray[11]),
			_41(pArray[12]), _42(pArray[13]), _43(pArray[14]), _44(pArray[15]) {}
		
		float operator() (size_t row, size_t col) const noexcept { return m[row][col]; }
		float& operator() (size_t row, size_t col) noexcept { return m[row][col]; }
	};

	struct alignas(16) Mat4_a : public Mat4 {
		using Mat4::Mat4;
	};

	/*
	----------------------------------------------
	|          Conversion Operations             |
	----------------------------------------------
	*/

	Vector CALL_CONV vectorIntToFloat(Vector iVec, uint32_t divExp);
	Vector CALL_CONV vectorFloatToInt(Vector fVec, uint32_t mulExp);
	Vector CALL_CONV vectorUintToFloat(Vector uVec, uint32_t divExp);
	Vector CALL_CONV vectorFloatToUint(Vector fVec, uint32_t mulExp);

	/*
	----------------------------------------------
	|              Load Operations               |
	----------------------------------------------
	*/

	Vector CALL_CONV loadInt(const uint32_t* pSource) noexcept;
	Vector CALL_CONV loadFloat(const float* pSource) noexcept;

	Vector CALL_CONV loadInt2(const uint32_t* pSource) noexcept;
	Vector CALL_CONV loadInt2_a(const uint32_t* pSource) noexcept;
	Vector CALL_CONV loadVec2(const Vec2* pSource) noexcept;
	Vector CALL_CONV loadVec2_a(const Vec2_a* pSource) noexcept;
	Vector CALL_CONV loadVec2_i(const Vec2_i* pSource) noexcept;
	Vector CALL_CONV loadVec2_u(const Vec2_u* pSource) noexcept;

	Vector CALL_CONV loadInt3(const uint32_t* pSource) noexcept;
	Vector CALL_CONV loadInt3_a(const uint32_t* pSource) noexcept;
	Vector CALL_CONV loadVec3(const Vec3* pSource) noexcept;
	Vector CALL_CONV loadVec3_a(const Vec2_a* pSource) noexcept;
	Vector CALL_CONV loadVec3_i(const Vec3_i* pSource) noexcept;
	Vector CALL_CONV loadVec3_u(const Vec3_u* pSource) noexcept;

	Vector CALL_CONV loadInt4(const uint32_t* pSource) noexcept;
	Vector CALL_CONV loadInt4_a(const uint32_t* pSource) noexcept;
	Vector CALL_CONV loadVec4(const Vec3* pSource) noexcept;
	Vector CALL_CONV loadVec4_a(const Vec2_a* pSource) noexcept;
	Vector CALL_CONV loadVec4_i(const Vec3_i* pSource) noexcept;
	Vector CALL_CONV loadVec4_u(const Vec3_u* pSource) noexcept;

	Matrix CALL_CONV loadMat3(const Mat3* pSource) noexcept;
	Matrix CALL_CONV loadMat3x4(const Mat3x4* pSource) noexcept;
	Matrix CALL_CONV loadMat3x4_a(const Mat3x4_a* pSource) noexcept;
	Matrix CALL_CONV loadMat4x3(const Mat4x3* pSource) noexcept;
	Matrix CALL_CONV loadMat4x3_a(const Mat4x3* pSource) noexcept;
	Matrix CALL_CONV loadMat4(const Mat4* pSource) noexcept;
	Matrix CALL_CONV loadMat4_a(const Mat4_a* pSource) noexcept;

	/*
	----------------------------------------------
	|              Store Operations               |
	----------------------------------------------
	*/

	void CALL_CONV storeInt(uint32_t* pDest, Vector v) noexcept;
	void CALL_CONV storeFloat(float* pDest, Vector v) noexcept;

	void CALL_CONV storeInt2(uint32_t* pDest, Vector v) noexcept;
	void CALL_CONV storeInt2_a(uint32_t* pDest, Vector v) noexcept;
	void CALL_CONV storeVec2(Vec2* pDest, Vector v) noexcept;
	void CALL_CONV storeVec2_a(Vec2_a* pDest, Vector v) noexcept;
	void CALL_CONV storeVec2_i(Vec2_i* pDest, Vector v) noexcept;
	void CALL_CONV storeVec2_u(Vec2_u* pDest, Vector v) noexcept;

	void CALL_CONV storeInt3(uint32_t* pDest, Vector v) noexcept;
	void CALL_CONV storeInt3_a(uint32_t* pDest, Vector v) noexcept;
	void CALL_CONV storeVec3(Vec3* pDest, Vector v) noexcept;
	void CALL_CONV storeVec3_a(Vec3_a* pDest, Vector v) noexcept;
	void CALL_CONV store_vec3i(Vec3_i* pDest, Vector v) noexcept;
	void CALL_CONV store_vec3u(Vec3_u* pDest, Vector v) noexcept;

	void CALL_CONV storeInt4(uint32_t* pDest, Vector v) noexcept;
	void CALL_CONV storeInt4_a(uint32_t* pDest, Vector v) noexcept;
	void CALL_CONV storeVec4(Vec4* pDest, Vector v) noexcept;
	void CALL_CONV storeVec4_a(Vec4_a* pDest, Vector v) noexcept;
	void CALL_CONV storeVec4_i(Vec4_i* pDest, Vector v) noexcept;
	void CALL_CONV storeVec4_u(Vec4_u* pDest, Vector v) noexcept;

	void CALL_CONV storeMat3(Mat3* pDest, Matrix m) noexcept;
	void CALL_CONV storeMat3x4(Mat3x4* pDest, Matrix m) noexcept;
	void CALL_CONV storeMat3x4_a(Mat3x4_a* pDest, Matrix m) noexcept;
	void CALL_CONV storeMat4x3(Mat4x3* pDest, Matrix m) noexcept;
	void CALL_CONV storeMat4x3_a(Mat4x3* pDest, Matrix m) noexcept;
	void CALL_CONV storeMat4(Mat4* pDest, Matrix m) noexcept;
	void CALL_CONV storeMat4_a(Mat4_a* pDest, Matrix m) noexcept;


	/*
	----------------------------------------------
	|          General Vector Operations         |
	----------------------------------------------
	*/

	Vector CALL_CONV vectorZero() noexcept;
	Vector CALL_CONV vectorSet(float x, float y, float z, float w) noexcept;
	Vector CALL_CONV vectorSetInt(uint32_t x, uint32_t y, uint32_t z, uint32_t w) noexcept;
	Vector CALL_CONV vectorSplat(float value) noexcept;
	Vector CALL_CONV vectorSplatPtr(const float* value);
	Vector CALL_CONV vectorSplatInt(uint32_t value) noexcept;
	Vector CALL_CONV vecotrSplatIntPtr(const uint32_t* value) noexcept;
	Vector CALL_CONV vecotrSplatX(const Vector) noexcept;
	Vector CALL_CONV vecotrSplatY(const Vector) noexcept;
	Vector CALL_CONV vecotrSplatZ(const Vector) noexcept;
	Vector CALL_CONV vecotrSplatW(const Vector) noexcept;
	Vector CALL_CONV vecotrSplatOne() noexcept;
	Vector CALL_CONV vecotrSplatInf() noexcept;
	Vector CALL_CONV vecotrSplatNan() noexcept;
	Vector CALL_CONV vecotrSplatEpsilon() noexcept;
	Vector CALL_CONV vecotrSplatSignMask() noexcept;

	float CALL_CONV vectorGetByIndex(Vector v, size_t i) noexcept;
	float CALL_CONV vectorGetX(Vector v) noexcept;
	float CALL_CONV vectorGetY(Vector v) noexcept;
	float CALL_CONV vectorGetZ(Vector v) noexcept;
	float CALL_CONV vectorGetW(Vector v) noexcept;

	void CALL_CONV vectorGetByIndexPtr(float* f, Vector v, size_t i) noexcept;
	void CALL_CONV vectorGetXPtr(float* x, Vector v) noexcept;
	void CALL_CONV vectorGetYPtr(float* y, Vector v) noexcept;
	void CALL_CONV vectorGetZPtr(float* z, Vector v) noexcept;
	void CALL_CONV vectorGetWPtr(float* w, Vector v) noexcept;

	uint32_t CALL_CONV vectorGetIntByIndex(Vector v, size_t i) noexcept;
	uint32_t CALL_CONV vectorGetIntX(Vector v) noexcept;
	uint32_t CALL_CONV vectorGetIntY(Vector v) noexcept;
	uint32_t CALL_CONV vectorGetIntZ(Vector v) noexcept;
	uint32_t CALL_CONV vectorGetIntW(Vector w) noexcept;

	void CALL_CONV vectorGetIntByIndexPtr(uint32_t* x, Vector v, size_t i) noexcept;
	void CALL_CONV vectorGetIntXPtr(uint32_t* x, Vector v) noexcept;
	void CALL_CONV vectorGetIntYPtr(uint32_t* y, Vector v) noexcept;
	void CALL_CONV vectorGetIntZPtr(uint32_t* z, Vector v) noexcept;
	void CALL_CONV vectorGetIntWPtr(uint32_t* w, Vector v) noexcept;

	Vector CALL_CONV vectorSetByIndex(Vector v, float f, size_t i) noexcept;
	Vector CALL_CONV vectorSetX(Vector v, float x) noexcept;
	Vector CALL_CONV vectorSetY(Vector v, float y) noexcept;
	Vector CALL_CONV vectorSetZ(Vector v, float z) noexcept;
	Vector CALL_CONV vectorSetW(Vector v, float w) noexcept;

	Vector CALL_CONV vectorSetByIndexPtr(Vector v, const float* f, size_t i) noexcept;
	Vector CALL_CONV vectorSetXPtr(Vector v, const float* x) noexcept;
	Vector CALL_CONV vectorSetYPtr(Vector v, const float* y) noexcept;
	Vector CALL_CONV vectorSetZPtr(Vector v, const float* z) noexcept;
	Vector CALL_CONV vectorSetWPtr(Vector v, const float* w) noexcept;

	Vector CALL_CONV vectorSetIntByIndex(Vector v, uint32_t x, size_t i) noexcept;
	Vector CALL_CONV vectorSetIntX(Vector v, uint32_t x) noexcept;
	Vector CALL_CONV vectorSetIntY(Vector v, uint32_t y) noexcept;
	Vector CALL_CONV vectorSetIntZ(Vector v, uint32_t z) noexcept;
	Vector CALL_CONV vectorSetIntW(Vector w, uint32_t w) noexcept;

	Vector CALL_CONV vectorSetIntByIndexPtr(uint32_t* x, Vector v, size_t i) noexcept;
	Vector CALL_CONV vectorSetIntXPtr(Vector v, const uint32_t* x) noexcept;
	Vector CALL_CONV vectorSetIntYPtr(Vector v, const uint32_t* y) noexcept;
	Vector CALL_CONV vectorSetIntZPtr(Vector v, const uint32_t* z) noexcept;
	Vector CALL_CONV vectorSetIntWPtr(Vector v, const uint32_t* w) noexcept;

}  // namespace Three

