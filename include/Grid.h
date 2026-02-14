#ifndef GRID_H
#define GRID_H

#include <GL/glew.h>

class Grid {
public:
    Grid(int rows, int cols, float cellSize);
    ~Grid();
    
    void render();
    
private:
    GLuint VAO, VBO;
    int vertexCount;
    
    void setupGrid(int rows, int cols, float cellSize);
};

#endif
