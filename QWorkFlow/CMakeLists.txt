# Set Basic Info
cmake_minimum_required(VERSION 3.5)
project(QWorkFlow VERSION 0.0.001 LANGUAGES CXX)

# Set this is a share lib
add_library(${PROJECT_NAME} SHARED)

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
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# Add src
target_sources(${PROJECT_NAME} PRIVATE
    src/nodeItem.cpp
    src/main.cpp
)

# # Qt5
# find_package(Qt5 COMPONENTS Core REQUIRED)

# # Link Qt5
# target_link_libraries(${PROJECT_NAME} PRIVATE
#     Qt5::Core
# )

# # Turn On Qt MOC/UIC/RCC
# set_target_properties(${PROJECT_NAME} PROPERTIES
#     AUTOMOC ON
#     AUTOUIC ON
#     AUTORCC ON
# )

# # Install rule
# install(TARGETS ${PROJECT_NAME}
#     LIBRARY DESTINATION lib
#     ARCHIVE DESTINATION lib
#     RUNTIME DESTINATION bin
#     PUBLIC_HEADER DESTINATION include
# )