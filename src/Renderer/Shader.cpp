#include "Shader.h"

Shader::~Shader()
{
    glDeleteProgram(_programId);
}

void Shader::UseProgram()
{
    glUseProgram(_programId);
}

void Shader::SetMat4(std::string name, glm::mat4 value)
{
    UseProgram();
    auto loc = glGetUniformLocation(_programId, name.c_str());
    glUniformMatrix4fv(loc, 1, GL_FALSE, &value[0][0]);
}

Shader::Shader()
{
    std::string vertexShaderSrc = R"(
    #version 330 core

    layout (location = 0) in vec2 Vert;

    uniform mat4 transformation;

    void main()
    {
        gl_Position = transformation * vec4(Vert.x, Vert.y, 0, 1);
    }
    )";

    std::string fragmentShaderSrc = R"(
    #version 330 core

    out vec4 Color;

    void main()
    {
        Color = vec4(1, 1, 1, 1);
    }
    )";

    auto vertexShader = glCreateShader(GL_VERTEX_SHADER);
    auto fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    auto src = vertexShaderSrc.c_str();
    glShaderSource(vertexShader, 1, &src, nullptr);
    src = fragmentShaderSrc.c_str();
    glShaderSource(fragmentShader, 1, &src, nullptr);

    glCompileShader(vertexShader);
    glCompileShader(fragmentShader);

    _programId = glCreateProgram();
    glAttachShader(_programId, vertexShader);
    glAttachShader(_programId, fragmentShader);
    glLinkProgram(_programId);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}
