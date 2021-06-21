# check if OpenGL is available
find_package(OpenGL REQUIRED)

add_subdirectory(glad)

set(GLFW_BUILD_EXAMPLES OFF)
set(GLFW_BUILD_TESTS OFF)
set(GLFW_BUILD_DOCS OFF)
set(GLFW_INSTALL OFF)
add_subdirectory(glfw)

add_subdirectory(glm)

include(import-imgui)

set(INSTALL_GTEST OFF)
cmake_policy(SET CMP0077 NEW)
add_subdirectory(googletest)