#pragma once
#ifdef __cpp_concepts
#define REQUIRES(...) requires __VA_ARGS__
#else
#define REQUIRES(...)
#endif