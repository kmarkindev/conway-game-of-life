#pragma once

#include <glad/glad.h>

#include "VertexBuffer.h"

class VertexArray
{
public:
    VertexArray();
    ~VertexArray();
    void AssignVertexBuffer(VertexBuffer vertexBuffer);
    void Bind() const;
    void Unbind() const;
private:
    GLuint _id;
};


