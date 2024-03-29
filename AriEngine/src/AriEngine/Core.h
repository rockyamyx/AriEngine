#pragma once

#ifdef AE_PLATFORM_WINDOWS
	#ifdef AE_BUILD_DLL
		#define ARI_API __declspec(dllexport)
	#else
		#define ARI_API __declspec(dllimport)
	#endif
#else
	#error AriEngine Only supports Windows!
#endif 

#ifdef AE_DEBUG
	#define AE_ENABLE_ASSERTS
#endif

#ifdef AE_ENABLE_ASSERTS
	#define AE_ASSERT(x, ...) { if(!(x)) { AE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define AE_CORE_ASSERT(x, ...) { if(!(x)) { AE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define AE_ASSERT(x, ...)
	#define AE_CORE_ASSERT(x, ...)
#endif


#define BIT(x) (1 << x)