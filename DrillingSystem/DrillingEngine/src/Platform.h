#pragma once

#if defined(_WIN32) || defined(_WIN64)
	#define DLL_EXPORT __declspec(dllexport) // Windows platform
#else
	#define	DLL_EXPORT __attribute__((visibility("default"))) // Unix-like platform (Linux, macOS)
#endif