#pragma once

#include "RenderAPI.h"
#include "Camera.h"
#include "Shader.h"
#include "../Field.h"
#include "VertexBuffer.h"
#include "VertexArray.h"

class FieldRenderer
{
public:
    explicit FieldRenderer(RenderAPI* renderApi, Camera* camera);
    void Render(Field& field);
private:
    RenderAPI* _renderApi;
    Camera* _camera;
    Shader _shader;
    VertexArray _vertexArray;
    VertexBuffer _vertexBuffer;
};