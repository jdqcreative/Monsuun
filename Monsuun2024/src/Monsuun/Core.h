#pragma once

#ifdef MO_PLATFORM_WINDOWS
	#ifdef MONSUUN_BUILD_DLL
		#define MONSUUN_API __declspec(dllexport)
	#else
		#define MONSUUN_API __declspec(dllimport)
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