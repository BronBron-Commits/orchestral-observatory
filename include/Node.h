#ifndef NODE_H
#define NODE_H

#include <GL/glew.h>
#include <string>

enum class NodeRole {
    PROJECT_MANAGER,
    SENIOR_ENGINEER,
    JUNIOR_ENGINEER
};

class Node {
public:
    Node(float x, float y, float radius, NodeRole role, const std::string& label);
    ~Node();
    
    void render();
    
    float getX() const { return x; }
    float getY() const { return y; }
    
private:
    GLuint VAO, VBO;
    int vertexCount;
    float x, y;
    float radius;
    NodeRole role;
    std::string label;
    
    void setupNode(float x, float y, float radius, NodeRole role);
    void getColorForRole(NodeRole role, float& r, float& g, float& b);
};

#endif
