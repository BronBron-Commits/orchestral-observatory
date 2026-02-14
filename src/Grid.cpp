#include "Grid.h"
#include <vector>
#include <cmath>

Grid::Grid(int rows, int cols, float cellSize) : VAO(0), VBO(0), vertexCount(0) {
    setupGrid(rows, cols, cellSize);
}

Grid::~Grid() {
    if (VAO != 0) {
        glDeleteVertexArrays(1, &VAO);
    }
    if (VBO != 0) {
        glDeleteBuffers(1, &VBO);
    }
}

void Grid::setupGrid(int rows, int cols, float cellSize) {
    std::vector<float> vertices;
    
    float width = cols * cellSize;
    float height = rows * cellSize;
    float startX = -width / 2.0f;
    float startY = -height / 2.0f;
    
    // Vertical lines
    for (int i = 0; i <= cols; ++i) {
        float x = startX + i * cellSize;
        
        // Position
        vertices.push_back(x);
        vertices.push_back(startY);
        // Color (gray)
        vertices.push_back(0.3f);
        vertices.push_back(0.3f);
        vertices.push_back(0.3f);
        
        // Position
        vertices.push_back(x);
        vertices.push_back(startY + height);
        // Color (gray)
        vertices.push_back(0.3f);
        vertices.push_back(0.3f);
        vertices.push_back(0.3f);
    }
    
    // Horizontal lines
    for (int i = 0; i <= rows; ++i) {
        float y = startY + i * cellSize;
        
        // Position
        vertices.push_back(startX);
        vertices.push_back(y);
        // Color (gray)
        vertices.push_back(0.3f);
        vertices.push_back(0.3f);
        vertices.push_back(0.3f);
        
        // Position
        vertices.push_back(startX + width);
        vertices.push_back(y);
        // Color (gray)
        vertices.push_back(0.3f);
        vertices.push_back(0.3f);
        vertices.push_back(0.3f);
    }
    
    vertexCount = vertices.size() / 5; // 2 position + 3 color
    
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);
    
    // Position attribute
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    // Color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(2 * sizeof(float)));
    glEnableVertexAttribArray(1);
    
    glBindVertexArray(0);
}

void Grid::render() {
    glBindVertexArray(VAO);
    glDrawArrays(GL_LINES, 0, vertexCount);
    glBindVertexArray(0);
}
