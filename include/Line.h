#ifndef LINE_H
#define LINE_H

#include <GL/glew.h>

class Line {
public:
    Line(float x1, float y1, float x2, float y2);
    ~Line();
    
    void render();
    
private:
    GLuint VAO, VBO;
    
    void setupLine(float x1, float y1, float x2, float y2);
};

#endif
