# Set Basic Info
cmake_minimum_required(VERSION 3.5)
project(Test VERSION 0.0.001 LANGUAGES CXX)

# Set this is a share lib
# add_library(${PROJECT_NAME} SHARED)
add_executable(${PROJECT_NAME})

# Set std20
set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)

# Set complite config
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(${PROJECT_NAME} PRIVATE
        -O3
        -ffunction-sections
        -fdata-sections
    )
    target_link_options(${PROJECT_NAME} PRIVATE
        -Wl,--gc-sections
    )
# Fuxx MSVC
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(${PROJECT_NAME} PRIVATE
        /O2
        /GL
    )
    target_link_options(${PROJECT_NAME} PRIVATE
        /LTCG
    )
endif()

# Add include
target_include_directories(${PROJECT_NAME} PUBLIC
    ../../../../QWorkFlow/include/SupportLibs/Message.hpp,
    $<INSTALL_INTERFACE:include>
)

# Add src
target_sources(${PROJECT_NAME} PRIVATE
    src/Message.cpp
)