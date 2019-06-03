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

#define BIT(x) (1 << x)