#pragma once

#include <memory>
#include <utility>

// Platform detection using predefined macros
#ifdef _WIN32

	/* Windows x64/x86 */
	#ifdef _WIN64

		/* Windows x64 */
		#define MO_PLATFORM_WINDOWS
	#else	

		/* Windows x86 */
		#error	"x86 Builds are not supported!"

	#endif

#elif defined(__APPLE__) || defined(__MACH__)

	#include <TargetConditionals.h>

	/* TARGET_OS_MAC exists on all platforms
	 * so we check all of them (in this order)
	 * to ensure that we're running on MAC
	 * and not some other Apple platform */

	#if TARGET_IPHONE_SIMULATOR == 1

		#error "IOS simulator is not supported!"

	#elif TARGET_OS_IPHONE == 1

		#define MU_PLATFORM_IOS
		#error "IOS is not supported!"

	#elif TARGET_OS_MAC == 1

		#define MU_PLATFORM_MACOS
		#error "MacOS is not supported!"

#else

	#define MONSUUN_API __declspec(dllimport)
	#error "Uknown Apple platform!"

#endif

/* We also have to check __ANDROID__ before __linux__ 
 * since android is based on the linux kernel
 * it has __linux__ defined */
#elif defined(__ANDROID__)
	#define MU_PLATFORM_ANDROID
	#error "Android is not supported!"
#elif defined(__linux__)
	#define MU_PLATFORM_LINUX
	#error "Linux is not supported"
#else
	/* Uknown compiler/platform */
	#error "Uknown platform!"
#endif // End of platform detection


// DLL support
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
#endif // End of DLL support

#ifdef MU_DEBUG
	#define MU_ENABLE_ASSERTS
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
	template <typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template <typename T>
	using Ref = std::shared_ptr<T>;
	template <typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

}