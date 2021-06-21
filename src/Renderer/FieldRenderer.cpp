#include "FieldRenderer.h"

FieldRenderer::FieldRenderer(RenderAPI* renderApi, Camera* camera)
    : _renderApi(renderApi), _camera(camera), _shader(Shader()),
    _vertexArray(VertexArray()), _vertexBuffer(VertexBuffer())
{
    _vertexArray.AssignVertexBuffer(_vertexBuffer);
}

void FieldRenderer::Render(const Field& field)
{
    auto proj = _camera->GetProjectionMatrix();

    _shader.UseProgram();

    for(auto iter = field.Begin(); iter != field.End(); ++iter)
    {
        auto cellPos = iter->GetPosition();
        glm::vec3 pos = glm::vec3(cellPos.x, cellPos.y, 0);
        auto transform = proj * glm::translate(glm::mat4(1.0f), pos);

        _shader.SetMat4("transformation", transform);

        _vertexArray.Bind();
        _renderApi->DrawArrays();
        _vertexArray.Unbind();
    }
}
