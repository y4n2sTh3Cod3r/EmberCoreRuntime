#pragma once
#ifdef _WIN64
#ifdef ELGR_EXPORT
#define ELGR_API _declspec(dllexport)
#else
#define ELGR_API _declspec(dllimport)
#endif
#endif

#include "frame/frame.h"