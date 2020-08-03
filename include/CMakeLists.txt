cmake_minimum_required(VERSION 3.15)
project(crc VERSION 0.0.1)

add_library(${PROJECT_NAME} INTERFACE)
target_sources(${PROJECT_NAME}
    INTERFACE
        ${PROJECT_SOURCE_DIR}/common_crc_type.hpp
        ${PROJECT_SOURCE_DIR}/crc.hpp
        ${PROJECT_SOURCE_DIR}/utility.hpp
)

target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_17)
target_include_directories(${PROJECT_NAME} INTERFACE ${PROJECT_SOURCE_DIR})