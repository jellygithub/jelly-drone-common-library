cmake_minimum_required(VERSION 3.16)

project(bd_client_demo LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(BD_ARCH "" CACHE STRING "Library architecture folder name (e.g., aarch64, x86_64)")

if (BD_ARCH STREQUAL "")
    if (CMAKE_SYSTEM_PROCESSOR MATCHES "aarch64|arm64")
        set(BD_ARCH "aarch64")
    elseif (CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64|amd64")
        set(BD_ARCH "x86_64")
    else()
        set(BD_ARCH "${CMAKE_SYSTEM_PROCESSOR}")
    endif()
endif()

set(BD_LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib/${BD_ARCH}")
set(BD_LIB_PATH "${BD_LIB_DIR}/libbd_position.so")

add_library(bd_position SHARED IMPORTED GLOBAL)
set_target_properties(bd_position PROPERTIES
    IMPORTED_LOCATION "${BD_LIB_PATH}"
)

add_executable(bd_demo_client src/main.cpp)
target_include_directories(bd_demo_client PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(bd_demo_client PRIVATE bd_position)

set_target_properties(bd_demo_client PROPERTIES
    BUILD_RPATH "\$ORIGIN/../lib/${BD_ARCH}"
    INSTALL_RPATH "\$ORIGIN/../lib/${BD_ARCH}"
)
