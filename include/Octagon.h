#ifndef OCTAGON_H
#define OCTAGON_H

#include <GL/glew.h>

class Octagon {
public:
    Octagon(float centerX, float centerY, float radius);
    ~Octagon();
    
    void render();
    
private:
    GLuint VAO, VBO;
    int vertexCount;
    
    void setupOctagon(float centerX, float centerY, float radius);
};

#endif
