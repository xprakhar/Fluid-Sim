#include "Three.h"

namespace Three {

	Vector CALL_CONV loadVec2_a(const Vec2_a* pSource) noexcept {
		return _mm_load_ps((const float*)pSource);
	}
}  // namespace Three