add_library(APP_TARGET_INTERFACE INTERFACE)

target_link_libraries(APP_TARGET_INTERFACE INTERFACE glad glfw glm::glm imgui)

target_sources(APP_TARGET_INTERFACE INTERFACE
    Field.cpp
    Field.h
    Cell.cpp
    Cell.h
    Field.h
    Window.cpp
    Window.h
    DeltaTime.cpp
    DeltaTime.h
    FieldSeeder.cpp
    FieldSeeder.h
    Random.h
    Random.cpp
    Renderer/RenderAPI.cpp
    Renderer/RenderAPI.h
    Renderer/VertexArray.cpp
    Renderer/VertexArray.h
    Renderer/VertexBuffer.cpp
    Renderer/VertexBuffer.h
    Renderer/Shader.cpp
    Renderer/Shader.h
    Renderer/FieldRenderer.cpp
    Renderer/FieldRenderer.h
    Renderer/Camera.cpp
    Renderer/Camera.h
    Rules/IRule.h
    Rules/KillLessThanTwo.h
    Rules/KillLessThanTwo.cpp
    Rules/KillMoreThanThree.cpp
    Rules/KillMoreThanThree.h
    Rules/SpawnWithThree.h
    Rules/SpawnWithThree.cpp
    Commands/ICommand.h
    Commands/KillCommand.h
    Commands/KillCommand.cpp
    Commands/SpawnCommand.cpp
    Commands/SpawnCommand.h
)

add_executable(${APP_TARGET})
target_link_libraries(${APP_TARGET} PUBLIC APP_TARGET_INTERFACE)
set_target_properties(${APP_TARGET} PROPERTIES
    OUTPUT_NAME ${APP_NAME}
)

target_sources(${APP_TARGET} PRIVATE Main.cpp)