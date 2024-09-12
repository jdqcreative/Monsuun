#pragma once

#ifdef MO_PLATFORM_WINDOWS
	#ifdef MONSUUN_BUILD_DLL
		#define MONSUUN_API __declspec(dllexport)
	#else
		#define MONSUUN_API __declspec(dllimport)
	#endif
#else
	#error "Monsuun only supports Windows""
#endif