#pragma once
#include "agent.hpp" // for Vec3

struct Mat4 {
    float m[16];
};

class Camera {
public:
    Camera();
    void orbit(float dx, float dy);
    void zoom(float amount);
    void pan(float dx, float dy);
    Mat4 getViewMatrix() const;
private:
    Vec3 position;
    Vec3 target;
    float distance;
    float yaw, pitch;
};
