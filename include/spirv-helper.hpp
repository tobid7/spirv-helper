#pragma once

/*
MIT License
Copyright (c) 2024 - 2026 René Amthor (tobid7)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
 */

/** Generated with ppam */
#ifndef SPV_BUILD_STATIC
#ifdef _WIN32  // Windows (MSVC Tested)
#ifdef SPV_BUILD_SHARED
#define SPV_API __declspec(dllexport)
#else
#define SPV_API __declspec(dllimport)
#endif
#elif defined(__APPLE__)  // macOS (untested yet)
#ifdef SPV_BUILD_SHARED
#define SPV_API __attribute__((visibility("default")))
#else
#define SPV_API
#endif
#elif defined(__linux__)  // Linux (untested yet)
#ifdef SPV_BUILD_SHARED
#define SPV_API __attribute__((visibility("default")))
#else
#define SPV_API
#endif
#endif
#else
#define SPV_API
#endif

#include <string>
#include <vector>

struct TBuiltInResource;
namespace SpirvHelper {
enum class Format {
  GLSL,
  HLSL,
  MSL,  // Not supported yet
  SPIRV,
};

enum class Stage {
  Vertex = 0,
  Geometry = 3,
  Fragment = 4,
};

SPV_API void Init();
SPV_API void Exit();
SPV_API void SetupResources(TBuiltInResource& resources);
SPV_API std::vector<unsigned int> GLSL2SPV(Stage stage, const char* code);
SPV_API std::string SPV2GLSL(const std::vector<unsigned int>& spirv,
                             int version, bool es = false);
SPV_API std::string SPV2HLSL(const std::vector<unsigned int>& spirv,
                             int version);
};  // namespace SpirvHelper