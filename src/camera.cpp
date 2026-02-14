
#include "camera.hpp"
#include <cmath>

Camera::Camera()
    : position(0.0f, 0.0f, 10.0f), target(0.0f, 0.0f, 0.0f), distance(10.0f), yaw(0.0f), pitch(0.0f) {}

void Camera::orbit(float dx, float dy) {
    // TODO: Implement orbit logic
}

void Camera::zoom(float amount) {
    // TODO: Implement zoom logic
}

void Camera::pan(float dx, float dy) {
    // TODO: Implement pan logic
}

Mat4 Camera::getViewMatrix() const {
    // Minimal lookAt implementation
    Vec3 f = {target.x - position.x, target.y - position.y, target.z - position.z};
    float flen = std::sqrt(f.x*f.x + f.y*f.y + f.z*f.z);
    if (flen > 0) { f.x /= flen; f.y /= flen; f.z /= flen; }
    Vec3 up = {0, 1, 0};
    Vec3 s = {f.y * up.z - f.z * up.y, f.z * up.x - f.x * up.z, f.x * up.y - f.y * up.x};
    float slen = std::sqrt(s.x*s.x + s.y*s.y + s.z*s.z);
    if (slen > 0) { s.x /= slen; s.y /= slen; s.z /= slen; }
    Vec3 u = {s.y * f.z - s.z * f.y, s.z * f.x - s.x * f.z, s.x * f.y - s.y * f.x};
    Mat4 m = { {
        s.x,  u.x, -f.x, 0,
        s.y,  u.y, -f.y, 0,
        s.z,  u.z, -f.z, 0,
        -(s.x*position.x + s.y*position.y + s.z*position.z),
        -(u.x*position.x + u.y*position.y + u.z*position.z),
        (f.x*position.x + f.y*position.y + f.z*position.z),
        1
    }};
    return m;
}
