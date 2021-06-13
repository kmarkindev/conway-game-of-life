#pragma once

#include <glad/glad.h>

class VertexBuffer
{
public:
    VertexBuffer();
    ~VertexBuffer();
    void Bind();
    void Unbind();
private:
    GLuint _id;
};


