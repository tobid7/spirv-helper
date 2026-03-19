#pragma once

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

void Init();
void Exit();
void SetupResources(TBuiltInResource& resources);
std::vector<unsigned int> GLSL2SPV(Stage stage, const char* code);
std::string SPV2GLSL(const std::vector<unsigned int>& spirv, int version,
                     bool es = false);
std::string SPV2HLSL(const std::vector<unsigned int>& spirv, int version);
};  // namespace SpirvHelper