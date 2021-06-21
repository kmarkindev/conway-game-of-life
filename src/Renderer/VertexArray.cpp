#include "VertexArray.h"

void VertexArray::Unbind() const
{
    glBindVertexArray(0);
}

void VertexArray::Bind() const
{
    glBindVertexArray(_id);
}

VertexArray::~VertexArray()
{
    glDeleteVertexArrays(1, &_id);
}

VertexArray::VertexArray()
{
    glGenVertexArrays(1, &_id);
}

void VertexArray::AssignVertexBuffer(VertexBuffer vertexBuffer)
{
    Bind();

    vertexBuffer.Bind();

    //We only use quads
    //so we dont need to allow to config this
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, nullptr);

    Unbind();
    vertexBuffer.Unbind();
}
