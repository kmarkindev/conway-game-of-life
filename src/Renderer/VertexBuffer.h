#pragma once

#include <glad/glad.h>

class VertexBuffer
{
public:
    VertexBuffer();
    ~VertexBuffer();
    void Bind() const;
    void Unbind() const;
private:
    GLuint _id;
};


