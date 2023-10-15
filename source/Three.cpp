#include "Three.h"

namespace three {
	/*
	----------------------------------------------
	|          Conversion Operations             |
	----------------------------------------------
	*/

	Vector CALL_CONV convertVectorIntToFloat(Vector iVec, uint32_t divExp)
	{
		float div = 1.0f / (1 << divExp);
		Vector floatVec = _mm_cvtepi32_ps(_mm_castps_si128(iVec));
		return _mm_mul_ps(floatVec, _mm_set_ps1(div));
	}
	Vector CALL_CONV convertVectorFloatToInt(Vector fVec, uint32_t mulExp)
	{
		float mul = (float)(1 << mulExp);
		Vector scaledVec = _mm_mul_ps(fVec, _mm_set_ps1(mul));
		return _mm_cvtps_epi32(scaledVec);
	}
	Vector CALL_CONV convertVectorUintToFloat(Vector uVec, uint32_t divExp)
	{
		float div = 1.0f / (1 << divExp);
		Vector floatVec = _mm_cvtepu32_ps(_mm_castps_si128(uVec));
		return _mm_mul_ps(floatVec, _mm_set_ps1(div));
	}
	Vector CALL_CONV covertVectorFloatToUint(Vector fVec, uint32_t mulExp)
	{
		float mul = (float)(1 << mulExp);
		Vector scaledVec = _mm_mul_ps(fVec, _mm_set_ps1(mul));
		return _mm_cvtps_epu32(scaledVec);
	}


	/*
	----------------------------------------------
	|              Load Operations               |
	----------------------------------------------
	*/

	Vector CALL_CONV loadInt(const uint32_t* pSource) noexcept
	{
		return _mm_load_ss(reinterpret_cast<const float*>(pSource));
	}
	Vector CALL_CONV loadFloat(const float* pSource) noexcept
	{
		return _mm_load_ss(pSource);
	}

	Vector CALL_CONV loadInt2(const uint32_t* pSource) noexcept
	{
		return _mm_set_ps(0.0f, 0.0f, static_cast<float>(pSource[0]), static_cast<float>(pSource[1));
	}
	Vector CALL_CONV loadInt2_a(const uint32_t* pSource) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV loadVec2(const Vec2* pSource) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV loadVec2_a(const Vec2_a* pSource) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV loadVec2_i(const Vec2_i* pSource) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV loadVec2_u(const Vec2_u* pSource) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV loadInt3(const uint32_t* pSource) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV loadInt3_a(const uint32_t* pSource) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV loadVec3(const Vec3* pSource) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV loadVec3_a(const Vec2_a* pSource) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV loadVec3_i(const Vec3_i* pSource) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV loadVec3_u(const Vec3_u* pSource) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV loadInt4(const uint32_t* pSource) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV loadInt4_a(const uint32_t* pSource) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV loadVec4(const Vec3* pSource) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV loadVec4_a(const Vec2_a* pSource) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV loadVec4_i(const Vec3_i* pSource) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV loadVec4_u(const Vec3_u* pSource) noexcept
	{
		return Vector CALL_CONV();
	}
	Matrix CALL_CONV loadMat3(const Mat3* pSource) noexcept
	{
		return Matrix CALL_CONV();
	}
	Matrix CALL_CONV loadMat3x4(const Mat3x4* pSource) noexcept
	{
		return Matrix CALL_CONV();
	}
	Matrix CALL_CONV loadMat3x4_a(const Mat3x4_a* pSource) noexcept
	{
		return Matrix CALL_CONV();
	}
	Matrix CALL_CONV loadMat4x3(const Mat4x3* pSource) noexcept
	{
		return Matrix CALL_CONV();
	}
	Matrix CALL_CONV loadMat4x3_a(const Mat4x3* pSource) noexcept
	{
		return Matrix CALL_CONV();
	}
	Matrix CALL_CONV loadMat4(const Mat4* pSource) noexcept
	{
		return Matrix CALL_CONV();
	}
	Matrix CALL_CONV loadMat4_a(const Mat4_a* pSource) noexcept
	{
		return Matrix CALL_CONV();
	}

	/*
	----------------------------------------------
	|              Store Operations               |
	----------------------------------------------
	*/

	void CALL_CONV storeInt(uint32_t* pDest, Vector v) noexcept
	{
		return void CALL_CONV();
	}
	void CALL_CONV storeFloat(float* pDest, Vector v) noexcept
	{
		return void CALL_CONV();
	}
	void CALL_CONV storeInt2(uint32_t* pDest, Vector v) noexcept
	{
		return void CALL_CONV();
	}
	void CALL_CONV storeInt2_a(uint32_t* pDest, Vector v) noexcept
	{
		return void CALL_CONV();
	}
	void CALL_CONV storeVec2(Vec2* pDest, Vector v) noexcept
	{
		return void CALL_CONV();
	}
	void CALL_CONV storeVec2_a(Vec2_a* pDest, Vector v) noexcept
	{
		return void CALL_CONV();
	}
	void CALL_CONV storeVec2_i(Vec2_i* pDest, Vector v) noexcept
	{
		return void CALL_CONV();
	}
	void CALL_CONV storeVec2_u(Vec2_u* pDest, Vector v) noexcept
	{
		return void CALL_CONV();
	}
	void CALL_CONV storeInt3(uint32_t* pDest, Vector v) noexcept
	{
		return void CALL_CONV();
	}
	void CALL_CONV storeInt3_a(uint32_t* pDest, Vector v) noexcept
	{
		return void CALL_CONV();
	}
	void CALL_CONV storeVec3(Vec3* pDest, Vector v) noexcept
	{
		return void CALL_CONV();
	}
	void CALL_CONV storeVec3_a(Vec3_a* pDest, Vector v) noexcept
	{
		return void CALL_CONV();
	}
	void CALL_CONV store_vec3i(Vec3_i* pDest, Vector v) noexcept
	{
		return void CALL_CONV();
	}
	void CALL_CONV store_vec3u(Vec3_u* pDest, Vector v) noexcept
	{
		return void CALL_CONV();
	}
	void CALL_CONV storeInt4(uint32_t* pDest, Vector v) noexcept
	{
		return void CALL_CONV();
	}
	void CALL_CONV storeInt4_a(uint32_t* pDest, Vector v) noexcept
	{
		return void CALL_CONV();
	}
	void CALL_CONV storeVec4(Vec4* pDest, Vector v) noexcept
	{
		return void CALL_CONV();
	}
	void CALL_CONV storeVec4_a(Vec4_a* pDest, Vector v) noexcept
	{
		return void CALL_CONV();
	}
	void CALL_CONV storeVec4_i(Vec4_i* pDest, Vector v) noexcept
	{
		return void CALL_CONV();
	}
	void CALL_CONV storeVec4_u(Vec4_u* pDest, Vector v) noexcept
	{
		return void CALL_CONV();
	}
	void CALL_CONV storeMat3(Mat3* pDest, Matrix m) noexcept
	{
		return void CALL_CONV();
	}
	void CALL_CONV storeMat3x4(Mat3x4* pDest, Matrix m) noexcept
	{
		return void CALL_CONV();
	}
	void CALL_CONV storeMat3x4_a(Mat3x4_a* pDest, Matrix m) noexcept
	{
		return void CALL_CONV();
	}
	void CALL_CONV storeMat4x3(Mat4x3* pDest, Matrix m) noexcept
	{
		return void CALL_CONV();
	}
	void CALL_CONV storeMat4x3_a(Mat4x3* pDest, Matrix m) noexcept
	{
		return void CALL_CONV();
	}
	void CALL_CONV storeMat4(Mat4* pDest, Matrix m) noexcept
	{
		return void CALL_CONV();
	}
	void CALL_CONV storeMat4_a(Mat4_a* pDest, Matrix m) noexcept
	{
		return void CALL_CONV();
	}

	/*
	----------------------------------------------
	|          General Vector Operations         |
	----------------------------------------------
	*/

	Vector CALL_CONV vectorZero() noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorSet(float x, float y, float z, float w) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorSetInt(uint32_t x, uint32_t y, uint32_t z, uint32_t w) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorSplat(float value) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorSplatPtr(const float* value)
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorSplatInt(uint32_t value) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vecotrSplatIntPtr(const uint32_t* value) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vecotrSplatX(const Vector) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vecotrSplatY(const Vector) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vecotrSplatZ(const Vector) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vecotrSplatW(const Vector) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vecotrSplatOne() noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vecotrSplatInf() noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vecotrSplatNan() noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vecotrSplatEpsilon() noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vecotrSplatSignMask() noexcept
	{
		return Vector CALL_CONV();
	}
	float CALL_CONV vectorGetByIndex(const Vector v, size_t i) noexcept
	{
		return 0.0f;
	}
	float CALL_CONV vectorGetX(const Vector v) noexcept
	{
		return 0.0f;
	}
	float CALL_CONV vectorGetY(const Vector v) noexcept
	{
		return 0.0f;
	}
	float CALL_CONV vectorGetZ(const Vector v) noexcept
	{
		return 0.0f;
	}
	float CALL_CONV vectorGetW(const Vector v) noexcept
	{
		return 0.0f;
	}
	void CALL_CONV vectorGetByIndexPtr(float* f, Vector v, size_t i) noexcept
	{
		return void CALL_CONV();
	}
	void CALL_CONV vectorGetXPtr(float* x, const Vector v) noexcept
	{
		return void CALL_CONV();
	}
	void CALL_CONV vectorGetYPtr(float* y, const Vector v) noexcept
	{
		return void CALL_CONV();
	}
	void CALL_CONV vectorGetZPtr(float* z, const Vector v) noexcept
	{
		return void CALL_CONV();
	}
	void CALL_CONV vectorGetWPtr(float* w, const Vector v) noexcept
	{
		return void CALL_CONV();
	}
	uint32_t CALL_CONV vectorGetIntByIndex(Vector v, size_t i) noexcept
	{
		return 0;
	}
	uint32_t CALL_CONV vectorGetIntX(const Vector v) noexcept
	{
		return 0;
	}
	uint32_t CALL_CONV vectorGetIntY(const Vector v) noexcept
	{
		return 0;
	}
	uint32_t CALL_CONV vectorGetIntZ(const Vector v) noexcept
	{
		return 0;
	}
	uint32_t CALL_CONV vectorGetIntW(const Vector w) noexcept
	{
		return 0;
	}
	void CALL_CONV vectorGetIntByIndexPtr(uint32_t* x, Vector v, size_t i) noexcept
	{
		return void CALL_CONV();
	}
	void CALL_CONV vectorGetIntXPtr(uint32_t* x, const Vector v) noexcept
	{
		return void CALL_CONV();
	}
	void CALL_CONV vectorGetIntYPtr(uint32_t* y, const Vector v) noexcept
	{
		return void CALL_CONV();
	}
	void CALL_CONV vectorGetIntZPtr(uint32_t* z, const Vector v) noexcept
	{
		return void CALL_CONV();
	}
	void CALL_CONV vectorGetIntWPtr(uint32_t* w, const Vector v) noexcept
	{
		return void CALL_CONV();
	}
	Vector CALL_CONV vectorSetByIndex(Vector v, float f, size_t i) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorSetX(const Vector v, float x) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorSetY(const Vector v, float y) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorSetZ(const Vector v, float z) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorSetW(const Vector v, float w) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorSetByIndexPtr(Vector v, const float* f, size_t i) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorSetXPtr(const Vector v, const float* x) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorSetYPtr(const Vector v, const float* y) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorSetZPtr(const Vector v, const float* z) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorSetWPtr(const Vector v, const float* w) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorSetIntByIndex(Vector v, uint32_t x, size_t i) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorSetIntX(const Vector v, uint32_t x) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorSetIntY(const Vector v, uint32_t y) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorSetIntZ(const Vector v, uint32_t z) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorSetIntW(const Vector w, uint32_t w) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorSetIntByIndexPtr(uint32_t* x, Vector v, size_t i) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorSetIntXPtr(const Vector v, const uint32_t* x) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorSetIntYPtr(const Vector v, const uint32_t* y) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorSetIntZPtr(const Vector v, const uint32_t* z) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorSetIntWPtr(const Vector v, const uint32_t* w) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorShiftLeft(const Vector v1, const Vector v2, uint32_t elements) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorRotateLeft(const Vector v, uint32_t elements) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorRotateRight(const Vector v, uint32_t elements) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorInsert(const Vector vd, const Vector vs, uint32_t vsLeftRotateElements, uint32_t select0, uint32_t select1, uint32_t select2, uint32_t select3) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorEqual(const Vector V1, const Vector V2) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorEqualR(uint32_t* pCR, const Vector V1, const Vector V2) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorEqualInt(const Vector V1, const Vector V2) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorEqualIntR(uint32_t* pCR, const Vector V, const Vector V2) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorNearEqual(const Vector V1, const Vector V2, const Vector Epsilon) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorNotEqual(const Vector V1, const Vector V2) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorNotEqualInt(const Vector V1, const Vector V2) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorGreater(const Vector V1, const Vector V2) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorGreaterR(uint32_t* pCR, const Vector V1, const Vector V2) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorGreaterOrEqual(const Vector V1, const Vector V2) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorGreaterOrEqualR(uint32_t* pCR, const Vector V1, const Vector V2) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorLess(const Vector V1, const Vector V2) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorLessOrEqual(const Vector V1, const Vector V2) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorInBounds(const Vector V, const Vector Bounds) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorInBoundsR(uint32_t* pCR, const Vector V, const Vector Bounds) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorIsNaN(const Vector V) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorIsInfinite(const Vector V) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorMin(const Vector V1, const Vector V2) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorMax(const Vector V1, const Vector V2) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorRound(const Vector V) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorTruncate(const Vector V) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorFloor(const Vector V) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorCeiling(const Vector V) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorClamp(const Vector V, const Vector Min, const Vector Max) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorSaturate(const Vector V) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorAndInt(const Vector V1, const Vector V2) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorAndCInt(const Vector V1, const Vector V2) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorOrInt(const Vector V1, const Vector V2) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorNorInt(const Vector V1, const Vector V2) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorXorInt(const Vector V1, const Vector V2) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorNegate(const Vector V) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorAdd(const Vector V1, const Vector V2) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorSum(const Vector V) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorAddAngles(const Vector V1, const Vector V2) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorSubtract(const Vector V1, const Vector V2) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorSubtractAngles(const Vector V1, const Vector V2) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorMultiply(const Vector V1, const Vector V2) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorMultiplyAdd(const Vector V1, const Vector V2, const Vector V3) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorDivide(const Vector V1, const Vector V2) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorNegativeMultiplySubtract(const Vector V1, const Vector V2, const Vector V3) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorScale(const Vector V, float ScaleFactor) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorReciprocalEst(const Vector V) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorReciprocal(const Vector V) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorSqrtEst(const Vector V) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorSqrt(const Vector V) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorReciprocalSqrtEst(const Vector V) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorReciprocalSqrt(const Vector V) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorExp2(const Vector V) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorExp10(const Vector V) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorExpE(const Vector V) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorExp(const Vector V) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorLog2(const Vector V) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorLog10(const Vector V) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorLogE(const Vector V) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorLog(const Vector V) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorPow(const Vector V1, const Vector V2) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorAbs(const Vector V) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorMod(const Vector V1, const Vector V2) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorModAngles(const Vector Angles) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorSin(const Vector V) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorSinEst(const Vector V) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorCos(const Vector V) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorCosEst(const Vector V) noexcept
	{
		return Vector CALL_CONV();
	}
	void CALL_CONV vectorSinCos(Vector* pSin, Vector* pCos, const Vector V) noexcept
	{
		return void CALL_CONV();
	}
	void CALL_CONV vectorSinCosEst(Vector* pSin, Vector* pCos, const Vector V) noexcept
	{
		return void CALL_CONV();
	}
	Vector CALL_CONV vectorTan(const Vector V) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorTanEst(const Vector V) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorSinH(const Vector V) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorCosH(const Vector V) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorTanH(const Vector V) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorASin(const Vector V) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorASinEst(const Vector V) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorACos(const Vector V) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorACosEst(const Vector V) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorATan(const Vector V) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorATanEst(const Vector V) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorATan2(const Vector Y, const Vector X) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorATan2Est(const Vector Y, const Vector X) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorLerp(const Vector V0, const Vector V1, float t) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorLerpV(const Vector V0, const Vector V1, const Vector T) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorHermite(const Vector Position0, const Vector Tangent0, const Vector Position1, Vector Tangent1, float t) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorHermiteV(const Vector Position0, const Vector Tangent0, const Vector Position1, Vector Tangent1, Vector T) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorCatmullRom(const Vector Position0, const Vector Position1, const Vector Position2, Vector Position3, float t) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorCatmullRomV(const Vector Position0, const Vector Position1, const Vector Position2, Vector Position3, Vector T) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorBaryCentric(const Vector Position0, const Vector Position1, const Vector Position2, float f, float g) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vectorBaryCentricV(const Vector Position0, const Vector Position1, const Vector Position2, Vector F, Vector G) noexcept
	{
		return Vector CALL_CONV();
	}

	/****************************************************************************
	*
	* 2D vector operations
	*
	****************************************************************************/

	bool CALL_CONV vector2Equal(const Vector V1, const Vector V2) noexcept
	{
		return false;
	}
	uint32_t CALL_CONV vector2EqualR(const Vector V1, const Vector V2) noexcept
	{
		return 0;
	}
	bool CALL_CONV vector2EqualInt(const Vector V1, const Vector V2) noexcept
	{
		return false;
	}
	uint32_t CALL_CONV vector2EqualIntR(const Vector V1, const Vector V2) noexcept
	{
		return 0;
	}
	bool CALL_CONV vector2NearEqual(const Vector V1, const Vector V2, const Vector Epsilon) noexcept
	{
		return false;
	}
	bool CALL_CONV vector2NotEqual(const Vector V1, const Vector V2) noexcept
	{
		return false;
	}
	bool CALL_CONV vector2NotEqualInt(const Vector V1, const Vector V2) noexcept
	{
		return false;
	}
	bool CALL_CONV vector2Greater(const Vector V1, const Vector V2) noexcept
	{
		return false;
	}
	uint32_t CALL_CONV vector2GreaterR(const Vector V1, const Vector V2) noexcept
	{
		return 0;
	}
	bool CALL_CONV vector2GreaterOrEqual(const Vector V1, const Vector V2) noexcept
	{
		return false;
	}
	uint32_t CALL_CONV vector2GreaterOrEqualR(const Vector V1, const Vector V2) noexcept
	{
		return 0;
	}
	bool CALL_CONV vector2Less(const Vector V1, const Vector V2) noexcept
	{
		return false;
	}
	bool CALL_CONV vector2LessOrEqual(const Vector V1, const Vector V2) noexcept
	{
		return false;
	}
	bool CALL_CONV vector2InBounds(const Vector V, const Vector Bounds) noexcept
	{
		return false;
	}
	bool CALL_CONV vector2IsNaN(const Vector V) noexcept
	{
		return false;
	}
	bool CALL_CONV vector2IsInfinite(const Vector V) noexcept
	{
		return false;
	}
	Vector CALL_CONV vector2Dot(const Vector V1, const Vector V2) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vector2Cross(const Vector V1, const Vector V2) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vector2LengthSq(const Vector V) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vector2ReciprocalLengthEst(const Vector V) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vector2ReciprocalLength(const Vector V) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vector2LengthEst(const Vector V) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vector2Length(const Vector V) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vector2NormalizeEst(const Vector V) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vector2Normalize(const Vector V) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vector2ClampLength(const Vector V, float LengthMin, float LengthMax) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vector2ClampLengthV(const Vector V, const Vector LengthMin, const Vector LengthMax) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vector2Reflect(const Vector Incident, const Vector Normal) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vector2Refract(const Vector Incident, const Vector Normal, float RefractionIndex) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vector2RefractV(const Vector Incident, const Vector Normal, const Vector RefractionIndex) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vector2Orthogonal(const Vector V) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vector2AngleBetweenNormalsEst(const Vector N1, const Vector N2) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vector2AngleBetweenNormals(const Vector N1, const Vector N2) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vector2AngleBetweenVectors(const Vector V1, const Vector V2) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vector2LinePointDistance(const Vector LinePoint1, const Vector LinePoint2, const Vector Point) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vector2IntersectLine(const Vector Line1Point1, const Vector Line1Point2, const Vector Line2Point1, GXMVECTOR Line2Point2) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vector2Transform(const Vector V, const Matrix M) noexcept
	{
		return Vector CALL_CONV();
	}
	Vec4* CALL_CONV vector2TransformStream(Vec4* pOutputStream, size_t OutputStride, const Vec2* pInputStream, size_t InputStride, size_t VectorCount, const Matrix M) noexcept
	{
		return Vec4 * CALL_CONV();
	}
	Vector CALL_CONV vector2TransformCoord(const Vector V, const Matrix M) noexcept
	{
		return Vector CALL_CONV();
	}
	Vec2* CALL_CONV vector2TransformCoordStream(Vec2* pOutputStream, size_t OutputStride, const Vec2* pInputStream, size_t InputStride, size_t VectorCount, const Matrix M) noexcept
	{
		return Vec2 * CALL_CONV();
	}
	Vector CALL_CONV vector2TransformNormal(const Vector V, const Matrix M) noexcept
	{
		return Vector CALL_CONV();
	}
	Vec2* CALL_CONV vector2TransformNormalStream(Vec2* pOutputStream, size_t OutputStride, const Vec2* pInputStream, size_t InputStride, size_t VectorCount, const Matrix M) noexcept
	{
		return Vec2 * CALL_CONV();
	}

	/****************************************************************************
	 *
	 * 3D vector operations
	 *
	 ****************************************************************************/

	bool CALL_CONV vector3Equal(const Vector V1, const Vector V2) noexcept
	{
		return false;
	}
	uint32_t CALL_CONV vector3EqualR(const Vector V1, const Vector V2) noexcept
	{
		return 0;
	}
	bool CALL_CONV vector3EqualInt(const Vector V1, const Vector V2) noexcept
	{
		return false;
	}
	uint32_t CALL_CONV vector3EqualIntR(const Vector V1, const Vector V2) noexcept
	{
		return 0;
	}
	bool CALL_CONV vector3NearEqual(const Vector V1, const Vector V2, const Vector Epsilon) noexcept
	{
		return false;
	}
	bool CALL_CONV vector3NotEqual(const Vector V1, const Vector V2) noexcept
	{
		return false;
	}
	bool CALL_CONV vector3NotEqualInt(const Vector V1, const Vector V2) noexcept
	{
		return false;
	}
	bool CALL_CONV vector3Greater(const Vector V1, const Vector V2) noexcept
	{
		return false;
	}
	uint32_t CALL_CONV vector3GreaterR(const Vector V1, const Vector V2) noexcept
	{
		return 0;
	}
	bool CALL_CONV vector3GreaterOrEqual(const Vector V1, const Vector V2) noexcept
	{
		return false;
	}
	uint32_t CALL_CONV vector3GreaterOrEqualR(const Vector V1, const Vector V2) noexcept
	{
		return 0;
	}
	bool CALL_CONV vector3Less(const Vector V1, const Vector V2) noexcept
	{
		return false;
	}
	bool CALL_CONV vector3LessOrEqual(const Vector V1, const Vector V2) noexcept
	{
		return false;
	}
	bool CALL_CONV vector3InBounds(const Vector V, const Vector Bounds) noexcept
	{
		return false;
	}
	bool CALL_CONV vector3IsNaN(const Vector V) noexcept
	{
		return false;
	}
	bool CALL_CONV vector3IsInfinite(const Vector V) noexcept
	{
		return false;
	}
	Vector CALL_CONV vector3Dot(const Vector V1, const Vector V2) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vector3Cross(const Vector V1, const Vector V2) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vector3LengthSq(const Vector V) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vector3ReciprocalLengthEst(const Vector V) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vector3ReciprocalLength(const Vector V) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vector3LengthEst(const Vector V) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vector3Length(const Vector V) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vector3NormalizeEst(const Vector V) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vector3Normalize(const Vector V) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vector3ClampLength(const Vector V, float LengthMin, float LengthMax) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vector3ClampLengthV(const Vector V, const Vector LengthMin, const Vector LengthMax) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vector3Reflect(const Vector Incident, const Vector Normal) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vector3Refract(const Vector Incident, const Vector Normal, float RefractionIndex) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vector3RefractV(const Vector Incident, const Vector Normal, const Vector RefractionIndex) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vector3Orthogonal(const Vector V) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vector3AngleBetweenNormalsEst(const Vector N1, const Vector N2) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vector3AngleBetweenNormals(const Vector N1, const Vector N2) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vector3AngleBetweenVectors(const Vector V1, const Vector V2) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vector3LinePointDistance(const Vector LinePoint1, const Vector LinePoint2, const Vector Point) noexcept
	{
		return Vector CALL_CONV();
	}
	void CALL_CONV vector3ComponentsFromNormal(Vector* pParallel, Vector* pPerpendicular, const Vector V, const Vector Normal) noexcept
	{
		return void CALL_CONV();
	}
	Vector CALL_CONV vector3Rotate(const Vector V, const Vector RotationQuaternion) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vector3InverseRotate(const Vector V, const Vector RotationQuaternion) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vector3Transform(const Vector V, const Matrix M) noexcept
	{
		return Vector CALL_CONV();
	}
	Vec4* CALL_CONV vector3TransformStream(Vec4* pOutputStream, size_t OutputStride, const Vec3* pInputStream, size_t InputStride, size_t VectorCount, const Matrix M) noexcept
	{
		return Vec4 * CALL_CONV();
	}
	Vector CALL_CONV vector3TransformCoord(const Vector V, const Matrix M) noexcept
	{
		return Vector CALL_CONV();
	}
	Vec3* CALL_CONV vector3TransformCoordStream(Vec3* pOutputStream, size_t OutputStride, const Vec3* pInputStream, size_t InputStride, size_t VectorCount, const Matrix M) noexcept
	{
		return Vec3 * CALL_CONV();
	}
	Vector CALL_CONV vector3TransformNormal(const Vector V, const Matrix M) noexcept
	{
		return Vector CALL_CONV();
	}
	Vec3* CALL_CONV vector3TransformNormalStream(Vec3* pOutputStream, size_t OutputStride, const Vec3* pInputStream, size_t InputStride, size_t VectorCount, const Matrix M) noexcept
	{
		return Vec3 * CALL_CONV();
	}
	Vector CALL_CONV vector3Project(const Vector V, float ViewportX, float ViewportY, float ViewportWidth, float ViewportHeight, float ViewportMinZ, float ViewportMaxZ, const Matrix Projection, const Matrix& View, const Matrix& World) noexcept
	{
		return Vector CALL_CONV();
	}
	Vec3* CALL_CONV vector3ProjectStream(Vec3* pOutputStream, size_t OutputStride, const Vec3* pInputStream, size_t InputStride, size_t VectorCount, float ViewportX, float ViewportY, float ViewportWidth, float ViewportHeight, float ViewportMinZ, float ViewportMaxZ, const Matrix Projection, const Matrix& View, const Matrix& World) noexcept
	{
		return Vec3 * CALL_CONV();
	}
	Vector CALL_CONV vector3Unproject(const Vector V, float ViewportX, float ViewportY, float ViewportWidth, float ViewportHeight, float ViewportMinZ, float ViewportMaxZ, const Matrix Projection, const Matrix& View, const Matrix& World) noexcept
	{
		return Vector CALL_CONV();
	}
	Vec3* CALL_CONV vector3UnprojectStream(Vec3* pOutputStream, size_t OutputStride, const Vec3* pInputStream, size_t InputStride, size_t VectorCount, float ViewportX, float ViewportY, float ViewportWidth, float ViewportHeight, float ViewportMinZ, float ViewportMaxZ, const Matrix Projection, const Matrix& View, const Matrix& World) noexcept
	{
		return Vec3 * CALL_CONV();
	}

	/****************************************************************************
	 *
	 * 4D vector operations
	 *
	 ****************************************************************************/

	bool CALL_CONV vector4Equal(const Vector V1, const Vector V2) noexcept
	{
		return false;
	}
	uint32_t CALL_CONV vector4EqualR(const Vector V1, const Vector V2) noexcept
	{
		return 0;
	}
	bool CALL_CONV vector4EqualInt(const Vector V1, const Vector V2) noexcept
	{
		return false;
	}
	uint32_t CALL_CONV vector4EqualIntR(const Vector V1, const Vector V2) noexcept
	{
		return 0;
	}
	bool CALL_CONV vector4NearEqual(const Vector V1, const Vector V2, const Vector Epsilon) noexcept
	{
		return false;
	}
	bool CALL_CONV vector4NotEqual(const Vector V1, const Vector V2) noexcept
	{
		return false;
	}
	bool CALL_CONV vector4NotEqualInt(const Vector V1, const Vector V2) noexcept
	{
		return false;
	}
	bool CALL_CONV vector4Greater(const Vector V1, const Vector V2) noexcept
	{
		return false;
	}
	uint32_t CALL_CONV vector4GreaterR(const Vector V1, const Vector V2) noexcept
	{
		return 0;
	}
	bool CALL_CONV vector4GreaterOrEqual(const Vector V1, const Vector V2) noexcept
	{
		return false;
	}
	uint32_t CALL_CONV vector4GreaterOrEqualR(const Vector V1, const Vector V2) noexcept
	{
		return 0;
	}
	bool CALL_CONV vector4Less(const Vector V1, const Vector V2) noexcept
	{
		return false;
	}
	bool CALL_CONV vector4LessOrEqual(const Vector V1, const Vector V2) noexcept
	{
		return false;
	}
	bool CALL_CONV vector4InBounds(const Vector V, const Vector Bounds) noexcept
	{
		return false;
	}
	bool CALL_CONV vector4IsNaN(const Vector V) noexcept
	{
		return false;
	}
	bool CALL_CONV vector4IsInfinite(const Vector V) noexcept
	{
		return false;
	}
	Vector CALL_CONV vector4Dot(const Vector V1, const Vector V2) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vector4Cross(const Vector V1, const Vector V2, const Vector V3) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vector4LengthSq(const Vector V) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vector4ReciprocalLengthEst(const Vector V) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vector4ReciprocalLength(const Vector V) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vector4LengthEst(const Vector V) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vector4Length(const Vector V) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vector4NormalizeEst(const Vector V) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vector4Normalize(const Vector V) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vector4ClampLength(const Vector V, float LengthMin, float LengthMax) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vector4ClampLengthV(const Vector V, const Vector LengthMin, const Vector LengthMax) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vector4Reflect(const Vector Incident, const Vector Normal) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vector4Refract(const Vector Incident, const Vector Normal, float RefractionIndex) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vector4RefractV(const Vector Incident, const Vector Normal, const Vector RefractionIndex) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vector4Orthogonal(const Vector V) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vector4AngleBetweenNormalsEst(const Vector N1, const Vector N2) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vector4AngleBetweenNormals(const Vector N1, const Vector N2) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vector4AngleBetweenVectors(const Vector V1, const Vector V2) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV vector4Transform(const Vector V, const Matrix M) noexcept
	{
		return Vector CALL_CONV();
	}
	Vec4* CALL_CONV vector4TransformStream(Vec4* pOutputStream, size_t OutputStride, const Vec4* pInputStream, size_t InputStride, size_t VectorCount, const Matrix M) noexcept
	{
		return Vec4 * CALL_CONV();
	}

	/****************************************************************************
	 *
	 * Matrix operations
	 *
	 ****************************************************************************/

	bool CALL_CONV matrixIsNaN(const Matrix M) noexcept
	{
		return false;
	}
	bool CALL_CONV matrixIsInfinite(const Matrix M) noexcept
	{
		return false;
	}
	bool CALL_CONV matrixIsIdentity(const Matrix M) noexcept
	{
		return false;
	}
	Matrix CALL_CONV matrixMultiply(const Matrix M1, const Matrix& M2) noexcept
	{
		return Matrix CALL_CONV();
	}
	Matrix CALL_CONV matrixMultiplyTranspose(const Matrix M1, const Matrix& M2) noexcept
	{
		return Matrix CALL_CONV();
	}
	Matrix CALL_CONV matrixTranspose(const Matrix M) noexcept
	{
		return Matrix CALL_CONV();
	}
	Matrix CALL_CONV matrixInverse(Vector* pDeterminant, const Matrix M) noexcept
	{
		return Matrix CALL_CONV();
	}
	Matrix CALL_CONV matrixVectorTensorProduct(const Vector V1, const Vector V2) noexcept
	{
		return Matrix CALL_CONV();
	}
	Vector CALL_CONV matrixDeterminant(const Matrix M) noexcept
	{
		return Vector CALL_CONV();
	}
	bool CALL_CONV matrixDecompose(Vector* outScale, Vector* outRotQuat, Vector* outTrans, const Matrix M) noexcept
	{
		return false;
	}
	Matrix CALL_CONV matrixIdentity() noexcept
	{
		return Matrix CALL_CONV();
	}
	Matrix CALL_CONV matrixSet(float m00, float m01, float m02, float m03, float m10, float m11, float m12, float m13, float m20, float m21, float m22, float m23, float m30, float m31, float m32, float m33) noexcept
	{
		return Matrix CALL_CONV();
	}
	Matrix CALL_CONV matrixTranslation(float OffsetX, float OffsetY, float OffsetZ) noexcept
	{
		return Matrix CALL_CONV();
	}
	Matrix CALL_CONV matrixTranslationFromVector(const Vector Offset) noexcept
	{
		return Matrix CALL_CONV();
	}
	Matrix CALL_CONV matrixScaling(float ScaleX, float ScaleY, float ScaleZ) noexcept
	{
		return Matrix CALL_CONV();
	}
	Matrix CALL_CONV matrixScalingFromVector(const Vector Scale) noexcept
	{
		return Matrix CALL_CONV();
	}
	Matrix CALL_CONV matrixRotationX(float Angle) noexcept
	{
		return Matrix CALL_CONV();
	}
	Matrix CALL_CONV matrixRotationY(float Angle) noexcept
	{
		return Matrix CALL_CONV();
	}
	Matrix CALL_CONV matrixRotationZ(float Angle) noexcept
	{
		return Matrix CALL_CONV();
	}
	Matrix CALL_CONV matrixRotationRollPitchYaw(float Pitch, float Yaw, float Roll) noexcept
	{
		return Matrix CALL_CONV();
	}
	Matrix CALL_CONV matrixRotationRollPitchYawFromVector(const Vector Angles) noexcept
	{
		return Matrix CALL_CONV();
	}
	Matrix CALL_CONV matrixRotationNormal(const Vector NormalAxis, float Angle) noexcept
	{
		return Matrix CALL_CONV();
	}
	Matrix CALL_CONV matrixRotationAxis(const Vector Axis, float Angle) noexcept
	{
		return Matrix CALL_CONV();
	}
	Matrix CALL_CONV matrixRotationQuaternion(const Vector Quaternion) noexcept
	{
		return Matrix CALL_CONV();
	}
	Matrix CALL_CONV matrixTransformation2D(const Vector ScalingOrigin, float ScalingOrientation, const Vector Scaling, const Vector RotationOrigin, float Rotation, GXMVECTOR Translation) noexcept
	{
		return Matrix CALL_CONV();
	}
	Matrix CALL_CONV matrixTransformation(const Vector ScalingOrigin, const Vector ScalingOrientationQuaternion, const Vector Scaling, GXMVECTOR RotationOrigin, HXMVECTOR RotationQuaternion, HXMVECTOR Translation) noexcept
	{
		return Matrix CALL_CONV();
	}
	Matrix CALL_CONV matrixAffineTransformation2D(const Vector Scaling, const Vector RotationOrigin, float Rotation, const Vector Translation) noexcept
	{
		return Matrix CALL_CONV();
	}
	Matrix CALL_CONV matrixAffineTransformation(const Vector Scaling, const Vector RotationOrigin, const Vector RotationQuaternion, GXMVECTOR Translation) noexcept
	{
		return Matrix CALL_CONV();
	}
	Matrix CALL_CONV matrixReflect(const Vector ReflectionPlane) noexcept
	{
		return Matrix CALL_CONV();
	}
	Matrix CALL_CONV matrixShadow(const Vector ShadowPlane, const Vector LightPosition) noexcept
	{
		return Matrix CALL_CONV();
	}
	Matrix CALL_CONV matrixLookAtLH(const Vector EyePosition, const Vector FocusPosition, const Vector UpDirection) noexcept
	{
		return Matrix CALL_CONV();
	}
	Matrix CALL_CONV matrixLookAtRH(const Vector EyePosition, const Vector FocusPosition, const Vector UpDirection) noexcept
	{
		return Matrix CALL_CONV();
	}
	Matrix CALL_CONV matrixLookToLH(const Vector EyePosition, const Vector EyeDirection, const Vector UpDirection) noexcept
	{
		return Matrix CALL_CONV();
	}
	Matrix CALL_CONV matrixLookToRH(const Vector EyePosition, const Vector EyeDirection, const Vector UpDirection) noexcept
	{
		return Matrix CALL_CONV();
	}
	Matrix CALL_CONV matrixPerspectiveLH(float ViewWidth, float ViewHeight, float NearZ, float FarZ) noexcept
	{
		return Matrix CALL_CONV();
	}
	Matrix CALL_CONV matrixPerspectiveRH(float ViewWidth, float ViewHeight, float NearZ, float FarZ) noexcept
	{
		return Matrix CALL_CONV();
	}
	Matrix CALL_CONV matrixPerspectiveFovLH(float FovAngleY, float AspectRatio, float NearZ, float FarZ) noexcept
	{
		return Matrix CALL_CONV();
	}
	Matrix CALL_CONV matrixPerspectiveFovRH(float FovAngleY, float AspectRatio, float NearZ, float FarZ) noexcept
	{
		return Matrix CALL_CONV();
	}
	Matrix CALL_CONV matrixPerspectiveOffCenterLH(float ViewLeft, float ViewRight, float ViewBottom, float ViewTop, float NearZ, float FarZ) noexcept
	{
		return Matrix CALL_CONV();
	}
	Matrix CALL_CONV matrixPerspectiveOffCenterRH(float ViewLeft, float ViewRight, float ViewBottom, float ViewTop, float NearZ, float FarZ) noexcept
	{
		return Matrix CALL_CONV();
	}
	Matrix CALL_CONV matrixOrthographicLH(float ViewWidth, float ViewHeight, float NearZ, float FarZ) noexcept
	{
		return Matrix CALL_CONV();
	}
	Matrix CALL_CONV matrixOrthographicRH(float ViewWidth, float ViewHeight, float NearZ, float FarZ) noexcept
	{
		return Matrix CALL_CONV();
	}
	Matrix CALL_CONV matrixOrthographicOffCenterLH(float ViewLeft, float ViewRight, float ViewBottom, float ViewTop, float NearZ, float FarZ) noexcept
	{
		return Matrix CALL_CONV();
	}
	Matrix CALL_CONV matrixOrthographicOffCenterRH(float ViewLeft, float ViewRight, float ViewBottom, float ViewTop, float NearZ, float FarZ) noexcept
	{
		return Matrix CALL_CONV();
	}

	/****************************************************************************
	 *
	 * Quaternion operations
	 *
	 ****************************************************************************/

	bool CALL_CONV quaternionEqual(const Vector Q1, const Vector Q2) noexcept
	{
		return false;
	}
	bool CALL_CONV quaternionNotEqual(const Vector Q1, const Vector Q2) noexcept
	{
		return false;
	}
	bool CALL_CONV quaternionIsNaN(const Vector Q) noexcept
	{
		return false;
	}
	bool CALL_CONV quaternionIsInfinite(const Vector Q) noexcept
	{
		return false;
	}
	bool CALL_CONV quaternionIsIdentity(const Vector Q) noexcept
	{
		return false;
	}
	Vector CALL_CONV quaternionDot(const Vector Q1, const Vector Q2) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV quaternionMultiply(const Vector Q1, const Vector Q2) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV quaternionLengthSq(const Vector Q) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV quaternionReciprocalLength(const Vector Q) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV quaternionLength(const Vector Q) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV quaternionNormalizeEst(const Vector Q) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV quaternionNormalize(const Vector Q) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV quaternionConjugate(const Vector Q) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV quaternionInverse(const Vector Q) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV quaternionLn(const Vector Q) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV quaternionExp(const Vector Q) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV quaternionSlerp(const Vector Q0, const Vector Q1, float t) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV quaternionSlerpV(const Vector Q0, const Vector Q1, const Vector T) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV quaternionSquad(const Vector Q0, const Vector Q1, const Vector Q2, GXMVECTOR Q3, float t) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV quaternionSquadV(const Vector Q0, const Vector Q1, const Vector Q2, GXMVECTOR Q3, HXMVECTOR T) noexcept
	{
		return Vector CALL_CONV();
	}
	void CALL_CONV quaternionSquadSetup(Vector* pA, Vector* pB, Vector* pC, const Vector Q0, const Vector Q1, const Vector Q2, GXMVECTOR Q3) noexcept
	{
		return void CALL_CONV();
	}
	Vector CALL_CONV quaternionBaryCentric(const Vector Q0, const Vector Q1, const Vector Q2, float f, float g) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV quaternionBaryCentricV(const Vector Q0, const Vector Q1, const Vector Q2, GXMVECTOR F, HXMVECTOR G) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV quaternionIdentity() noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV quaternionRotationRollPitchYaw(float Pitch, float Yaw, float Roll) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV quaternionRotationRollPitchYawFromVector(const Vector Angles) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV quaternionRotationNormal(const Vector NormalAxis, float Angle) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV quaternionRotationAxis(const Vector Axis, float Angle) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV quaternionRotationMatrix(const Matrix M) noexcept
	{
		return Vector CALL_CONV();
	}
	void CALL_CONV quaternionToAxisAngle(Vector* pAxis, float* pAngle, const Vector Q) noexcept
	{
		return void CALL_CONV();
	}

	/****************************************************************************
	 *
	 * Plane operations
	 *
	 ****************************************************************************/

	bool CALL_CONV planeEqual(const Vector P1, const Vector P2) noexcept
	{
		return false;
	}
	bool CALL_CONV planeNearEqual(const Vector P1, const Vector P2, const Vector Epsilon) noexcept
	{
		return false;
	}
	bool CALL_CONV planeNotEqual(const Vector P1, const Vector P2) noexcept
	{
		return false;
	}
	bool CALL_CONV planeIsNaN(const Vector P) noexcept
	{
		return false;
	}
	bool CALL_CONV planeIsInfinite(const Vector P) noexcept
	{
		return false;
	}
	Vector CALL_CONV planeDot(const Vector P, const Vector V) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV planeDotCoord(const Vector P, const Vector V) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV planeDotNormal(const Vector P, const Vector V) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV planeNormalizeEst(const Vector P) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV planeNormalize(const Vector P) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV planeIntersectLine(const Vector P, const Vector LinePoint1, const Vector LinePoint2) noexcept
	{
		return Vector CALL_CONV();
	}
	void CALL_CONV planeIntersectPlane(Vector* pLinePoint1, Vector* pLinePoint2, const Vector P1, const Vector P2) noexcept
	{
		return void CALL_CONV();
	}
	Vector CALL_CONV planeTransform(const Vector P, const Matrix ITM) noexcept
	{
		return Vector CALL_CONV();
	}
	Vec4* CALL_CONV planeTransformStream(Vec4* pOutputStream, size_t OutputStride, const Vec4* pInputStream, size_t InputStride, size_t PlaneCount, const Matrix ITM) noexcept
	{
		return Vec4 * CALL_CONV();
	}
	Vector CALL_CONV planeFromPointNormal(const Vector Point, const Vector Normal) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV planeFromPoints(const Vector Point1, const Vector Point2, const Vector Point3) noexcept
	{
		return Vector CALL_CONV();
	}

	/****************************************************************************
	 *
	 * Color operations
	 *
	 ****************************************************************************/

	bool CALL_CONV colorEqual(const Vector C1, const Vector C2) noexcept
	{
		return false;
	}
	bool CALL_CONV colorNotEqual(const Vector C1, const Vector C2) noexcept
	{
		return false;
	}
	bool CALL_CONV colorGreater(const Vector C1, const Vector C2) noexcept
	{
		return false;
	}
	bool CALL_CONV colorGreaterOrEqual(const Vector C1, const Vector C2) noexcept
	{
		return false;
	}
	bool CALL_CONV colorLess(const Vector C1, const Vector C2) noexcept
	{
		return false;
	}
	bool CALL_CONV colorLessOrEqual(const Vector C1, const Vector C2) noexcept
	{
		return false;
	}
	bool CALL_CONV colorIsNaN(const Vector C) noexcept
	{
		return false;
	}
	bool CALL_CONV colorIsInfinite(const Vector C) noexcept
	{
		return false;
	}
	Vector CALL_CONV colorNegative(const Vector C) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV colorModulate(const Vector C1, const Vector C2) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV colorAdjustSaturation(const Vector C, float Saturation) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV colorAdjustContrast(const Vector C, float Contrast) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV colorRGBToHSL(const Vector rgb) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV colorHSLToRGB(const Vector hsl) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV colorRGBToHSV(const Vector rgb) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV colorHSVToRGB(const Vector hsv) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV colorRGBToYUV(const Vector rgb) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV colorYUVToRGB(const Vector yuv) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV colorRGBToYUV_HD(const Vector rgb) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV colorYUVToRGB_HD(const Vector yuv) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV colorRGBToYUV_UHD(const Vector rgb) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV colorYUVToRGB_UHD(const Vector yuv) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV colorRGBToXYZ(const Vector rgb) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV colorXYZToRGB(const Vector xyz) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV colorXYZToSRGB(const Vector xyz) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV colorSRGBToXYZ(const Vector srgb) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV colorRGBToSRGB(const Vector rgb) noexcept
	{
		return Vector CALL_CONV();
	}
	Vector CALL_CONV colorSRGBToRGB(const Vector srgb) noexcept
	{
		return Vector CALL_CONV();
	}

	/****************************************************************************
	 *
	 * Miscellaneous operations
	 *
	 ****************************************************************************/

	bool verifyCPUSupport() noexcept
	{
		return false;
	}
	Vector CALL_CONV fresnelTerm(const Vector CosIncidentAngle, const Vector RefractionIndex) noexcept
	{
		return Vector CALL_CONV();
	}
	bool scalarNearEqual(float S1, float S2, float Epsilon) noexcept
	{
		return false;
	}
	float scalarModAngle(float Value) noexcept
	{
		return 0.0f;
	}
	float scalarSin(float Value) noexcept
	{
		return 0.0f;
	}
	float scalarSinEst(float Value) noexcept
	{
		return 0.0f;
	}
	float scalarCos(float Value) noexcept
	{
		return 0.0f;
	}
	float scalarCosEst(float Value) noexcept
	{
		return 0.0f;
	}
	void scalarSinCos(float* pSin, float* pCos, float Value) noexcept
	{
	}
	void scalarSinCosEst(float* pSin, float* pCos, float Value) noexcept
	{
	}
	float scalarASin(float Value) noexcept
	{
		return 0.0f;
	}
	float scalarASinEst(float Value) noexcept
	{
		return 0.0f;
	}
	float scalarACos(float Value) noexcept
	{
		return 0.0f;
	}
	float scalarACosEst(float Value) noexcept
	{
		return 0.0f;
	}
}  // namespace Three