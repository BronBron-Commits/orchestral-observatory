#include "Octagon.h"
#include <vector>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

Octagon::Octagon(float centerX, float centerY, float radius) : VAO(0), VBO(0), vertexCount(0) {
    setupOctagon(centerX, centerY, radius);
}

Octagon::~Octagon() {
    if (VAO != 0) {
        glDeleteVertexArrays(1, &VAO);
    }
    if (VBO != 0) {
        glDeleteBuffers(1, &VBO);
    }
}

void Octagon::setupOctagon(float centerX, float centerY, float radius) {
    std::vector<float> vertices;
    
    int sides = 8;
    
    // Create octagon as line loop
    for (int i = 0; i < sides; ++i) {
        float angle = 2.0f * M_PI * i / sides;
        float x = centerX + radius * cos(angle);
        float y = centerY + radius * sin(angle);
        
        // Position
        vertices.push_back(x);
        vertices.push_back(y);
        // Color (white)
        vertices.push_back(1.0f);
        vertices.push_back(1.0f);
        vertices.push_back(1.0f);
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

void Octagon::render() {
    glBindVertexArray(VAO);
    glDrawArrays(GL_LINE_LOOP, 0, vertexCount);
    glBindVertexArray(0);
}
