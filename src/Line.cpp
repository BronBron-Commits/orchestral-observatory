#include "Line.h"
#include <vector>

Line::Line(float x1, float y1, float x2, float y2) : VAO(0), VBO(0) {
    setupLine(x1, y1, x2, y2);
}

Line::~Line() {
    if (VAO != 0) {
        glDeleteVertexArrays(1, &VAO);
    }
    if (VBO != 0) {
        glDeleteBuffers(1, &VBO);
    }
}

void Line::setupLine(float x1, float y1, float x2, float y2) {
    float vertices[] = {
        // Position      // Color (yellow)
        x1, y1,          1.0f, 1.0f, 0.0f,
        x2, y2,          1.0f, 1.0f, 0.0f
    };
    
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    // Position attribute
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    // Color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(2 * sizeof(float)));
    glEnableVertexAttribArray(1);
    
    glBindVertexArray(0);
}

void Line::render() {
    glBindVertexArray(VAO);
    glDrawArrays(GL_LINES, 0, 2);
    glBindVertexArray(0);
}
