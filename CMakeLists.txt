cmake_minimum_required(VERSION 3.18)

project(conway-game-of-life VERSION 1.0.0 LANGUAGES CXX)

if(${CMAKE_BINARY_DIR} STREQUAL ${CMAKE_SOURCE_DIR})
    message(FATAL "building inside source files is a bad idea. Please, try to use \"Out of source\" build instead.")
endif()

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(config)

add_executable(${APP_TARGET})

set_target_properties(${APP_TARGET} PROPERTIES
    OUTPUT_NAME ${APP_NAME}
)

add_subdirectory(src)
add_subdirectory(3rdparty)