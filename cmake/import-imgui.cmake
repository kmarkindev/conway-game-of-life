set(IMGUI_ROOT_DIR "${CMAKE_SOURCE_DIR}/3rdparty/imgui")

add_library(imgui STATIC
        "${IMGUI_ROOT_DIR}/imgui.cpp"
        "${IMGUI_ROOT_DIR}/imgui_draw.cpp"
        "${IMGUI_ROOT_DIR}/imgui_tables.cpp"
        "${IMGUI_ROOT_DIR}/imgui_widgets.cpp"
        "${IMGUI_ROOT_DIR}/imgui_demo.cpp"

        "${IMGUI_ROOT_DIR}/backends/imgui_impl_glfw.cpp"
        "${IMGUI_ROOT_DIR}/backends/imgui_impl_opengl3.cpp"
        )

target_include_directories(imgui PUBLIC
        "${IMGUI_ROOT_DIR}"
)

target_link_libraries(imgui PRIVATE glfw glad)

target_compile_definitions(imgui PRIVATE IMGUI_IMPL_OPENGL_LOADER_GLAD)
