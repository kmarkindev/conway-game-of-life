#include "VertexBuffer.h"

VertexBuffer::VertexBuffer()
{
    glGenBuffers(1, &_id);

    Bind();

    /*
     * We need to only render quads
     * so no need to load any other data
     */

    float* data = new float[12]{
        0.45, 0.45,
        -0.45, 0.45,
        -0.45, -0.45,

        0.45, 0.45,
        -0.45, -0.45,
        0.45, -0.45
    };

    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 12, data, GL_STATIC_DRAW);

    Unbind();
}

void VertexBuffer::Bind()
{
    glBindBuffer(GL_ARRAY_BUFFER, _id);
}

void VertexBuffer::Unbind()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

VertexBuffer::~VertexBuffer()
{
    glDeleteBuffers(1, &_id);
}
