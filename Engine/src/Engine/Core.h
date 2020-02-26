#pragma once

#ifdef PLATFORM_WINDOWS
	#ifdef BUILD_DLL
		#define ENGINE_API __declspec(dllexport)
	#else
		#define ENGINE_API __declspec(dllimport)
	#endif 
#else
	#error No Windows support!
#endif

#define BIT(x) (1 << x)