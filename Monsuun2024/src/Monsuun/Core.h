#pragma once

#include <memory>

#ifdef MO_PLATFORM_WINDOWS
	#if MU_DYNAMIC_LINK
		#ifdef MONSUUN_BUILD_DLL
			#define MONSUUN_API __declspec(dllexport)
		#else
			#define MONSUUN_API __declspec(dllimport)
		#endif
	#else
		#define MONSUUN_API
	#endif
#else
	#error "Monsuun only supports Windows"
#endif

#ifdef MU_ENABLE_ASSERTS
	#define MU_ASSERT(x, ...) { if(!(x))  { MU_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define MU_CORE_ASSERT(x, ...) { if(!(x)) {MU_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define MU_ASSERT(x, ...)
	#define MU_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define MU_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

namespace Monsuun {

	template <typename T>
	using Scope = std::unique_ptr<T>;
	
	template <typename T>
	using Ref = std::shared_ptr<T>;

}