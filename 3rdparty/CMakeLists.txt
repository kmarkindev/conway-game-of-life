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

target_link_libraries(${APP_TARGET} PRIVATE glad glfw glm::glm imgui)