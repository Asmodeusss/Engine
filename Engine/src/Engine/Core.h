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

#ifdef ENABLE_ASSERT
	#define ASSERT(x, ...) {if (!(x)) {APP_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define CORE_ASSERT(x, ...) {if (!(x)) {CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define ASSERT(x, ...)
	#define CORE_ASSERT(x, ...)
#endif