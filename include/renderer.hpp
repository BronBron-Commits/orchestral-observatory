
#pragma once
#include <SDL.h>
#include "agent.hpp"
#include "cluster.hpp"
#include "message.hpp"
#include "camera.hpp"

namespace Renderer {
    void init(SDL_Renderer* renderer);
    void drawAgent(SDL_Renderer* renderer, const Agent& agent);
    void drawCluster(SDL_Renderer* renderer, const Cluster& cluster);
    void drawMessage(SDL_Renderer* renderer, const Message& message);
    void setCamera(const Camera& camera);
    void clear(SDL_Renderer* renderer);
    void present(SDL_Renderer* renderer);
}
