#pragma once

#include <string>
#include <glad/glad.h>
#include <glm/glm.hpp>

class Shader
{
public:
    Shader(std::string vertexShaderSrc, std::string fragmentShaderSrc);
    ~Shader();
    void UseProgram();
    void SetMat4(std::string name, glm::mat4 value);
private:
    GLuint _programId;
};


