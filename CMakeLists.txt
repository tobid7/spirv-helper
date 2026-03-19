cmake_minimum_required(VERSION 3.22)

project(spirv-helper VERSION 0.1.0 LANGUAGES CXX)

option(SPV_BUILD_SHARED "Build Shared Library" OFF)

add_subdirectory(vendor)

if(SPV_BUILD_SHARED)
    add_library(spirv-helper SHARED
        source/spirv-helper.cpp
    )
else()
    add_library(spirv-helper STATIC
        source/spirv-helper.cpp
    )
endif()

target_link_libraries(spirv-helper PUBLIC
    glslang
    glslang-default-resource-limits
    OSDependent
    SPIRV

    spirv-cross-core
    spirv-cross-cpp
    spirv-cross-glsl
    spirv-cross-hlsl
    spirv-cross-msl
    spirv-cross-reflect
    spirv-cross-util
)

add_library(spirv-helper::spirv-helper ALIAS spirv-helper)

target_include_directories(spirv-helper
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)
