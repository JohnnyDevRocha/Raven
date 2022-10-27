#pragma once

#ifdef RV_PLATFORM_WINDOWS
	#ifdef RV_BUILD_DLL
		#define RAVEN_API _declspec(dllexport)
	#else
		#define RAVEN_API _declspec(dllimport)
	#endif
#else
	#error Raven only support Windows!
#endif

#define BIT(x) (1 << x)