#pragma once

#ifdef CD_PLATFORM_WINDOWS
	#ifdef CD_BUILD_DLL
		#define CONDOR_API __declspec(dllexport)
	#else
		#define CONDOR_API __declspec(dllimport)
	#endif
#else
	#error Condor only supports Windows!
#endif