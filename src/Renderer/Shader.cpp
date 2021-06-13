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

Shader::Shader(std::string vertexShaderSrc, std::string fragmentShaderSrc)
{
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
