#include "Node.h"
#include <vector>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

Node::Node(float x, float y, float radius, NodeRole role, const std::string& label)
    : VAO(0), VBO(0), vertexCount(0), x(x), y(y), radius(radius), role(role), label(label) {
    setupNode(x, y, radius, role);
}

Node::~Node() {
    if (VAO != 0) {
        glDeleteVertexArrays(1, &VAO);
    }
    if (VBO != 0) {
        glDeleteBuffers(1, &VBO);
    }
}

void Node::getColorForRole(NodeRole role, float& r, float& g, float& b) {
    switch (role) {
        case NodeRole::PROJECT_MANAGER:
            r = 1.0f; g = 0.2f; b = 0.2f; // Red
            break;
        case NodeRole::SENIOR_ENGINEER:
            r = 0.2f; g = 0.6f; b = 1.0f; // Blue
            break;
        case NodeRole::JUNIOR_ENGINEER:
            r = 0.2f; g = 1.0f; b = 0.2f; // Green
            break;
    }
}

void Node::setupNode(float x, float y, float radius, NodeRole role) {
    std::vector<float> vertices;
    
    int segments = 32;
    float r, g, b;
    getColorForRole(role, r, g, b);
    
    // Center vertex
    vertices.push_back(x);
    vertices.push_back(y);
    vertices.push_back(r);
    vertices.push_back(g);
    vertices.push_back(b);
    
    // Circle vertices
    for (int i = 0; i <= segments; ++i) {
        float angle = 2.0f * M_PI * i / segments;
        float vx = x + radius * cos(angle);
        float vy = y + radius * sin(angle);
        
        vertices.push_back(vx);
        vertices.push_back(vy);
        vertices.push_back(r);
        vertices.push_back(g);
        vertices.push_back(b);
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

void Node::render() {
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLE_FAN, 0, vertexCount);
    glBindVertexArray(0);
}
