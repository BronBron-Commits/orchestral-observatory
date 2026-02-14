#pragma once
#include <string>
#include <vector>

struct Vec3 {
    float x, y, z;
    Vec3(float x_=0, float y_=0, float z_=0) : x(x_), y(y_), z(z_) {}
};

struct Agent {
    int id;
    std::string role; // Codex, Gemini, Claude, Orchestrator
    Vec3 position;
    float activity_level; // 0-1
    std::vector<std::string> active_tasks;

    void updateState();
    void render() const;
};
