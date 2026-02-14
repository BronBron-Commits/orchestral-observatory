#ifndef SHADER_PROGRAM_H
#define SHADER_PROGRAM_H

#include <string>
#include <GL/glew.h>

class ShaderProgram {
public:
    ShaderProgram();
    ~ShaderProgram();
    
    bool loadShaders(const std::string& vertexPath, const std::string& fragmentPath);
    void use();
    GLuint getProgram() const { return program; }
    
    void setMat4(const std::string& name, const float* value);
    
private:
    GLuint program;
    GLuint compileShader(GLenum type, const std::string& source);
    std::string readFile(const std::string& filePath);
};

#endif
