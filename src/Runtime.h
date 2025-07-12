#pragma once
#ifdef _WIN64
#ifdef RUNTIME_EXPORT
#define RUNTIME_API _declspec(dllexport)
#else
#define RUNTIME_API _declspec(dllimport)
#endif
#endif

void RUNTIME_API test();