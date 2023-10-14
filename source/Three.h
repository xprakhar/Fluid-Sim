#include <immintrin.h>
#include <stdint.h>

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
		float x, y;
	};

	struct alignas(16) Vec2_a : public Vec2 {
		using Vec2::Vec2;
	};

	struct Vec2_i {
		int x, y;
	};

	struct Vec2_u {
		uint32_t x, y;
	};


	struct Vec3 {
		float x, y, z;
	};

	struct alignas(16) Vec3_a : public Vec3 {
		using Vec3::Vec3;
	};

	struct Vec3_i {
		int x, y, z;
	};

	struct Vec3_u {
		uint32_t x, y, z;
	};


	struct Vec4 {
		float x, y, z, w;
	};

	struct alignas(16) Vec4_a : public Vec4 {
		using Vec4::Vec4;
	};

	struct Vec4_i {
		int x, y, z, w;
	};

	struct Vec4_u {
		uint32_t x, y, z, w;
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
	};

	struct Mat3x4 {
	
		union {
			struct {
				float _11, _12, _13, _14;
				float _21, _22, _23, _24;
				float _31, _32, _33, _34;
			};
			float m[3][4];
		};

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
		};

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

}  // namespace Three

