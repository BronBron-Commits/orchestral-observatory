#include "renderer.hpp"

#include <SDL.h>

namespace Renderer {
    void init(SDL_Renderer* renderer) {
        // No-op for SDL2
    }
    void drawAgent(SDL_Renderer* renderer, const Agent& agent) {
        const int numSides = 8;
        float radius = 40.0f;
        float cx = 640.0f + agent.position.x * 60.0f;
        float cy = 360.0f + agent.position.y * 60.0f;
        if (!renderer) return;
        SDL_SetRenderDrawColor(renderer, 100, 200, 255, 255);
        SDL_Point points[numSides + 1];
        for (int i = 0; i <= numSides; ++i) {
            float angle = (float)i / numSides * 2.0f * 3.1415926f;
            points[i].x = (int)(cx + radius * cosf(angle));
            points[i].y = (int)(cy + radius * sinf(angle));
        }
        SDL_RenderDrawLines(renderer, points, numSides + 1);
    }
    void drawCluster(SDL_Renderer* renderer, const Cluster& cluster) {
        int n = (int)cluster.agents.size();
        float gridRadius = 3.0f;
        for (int i = 0; i < n; ++i) {
            float angle = (float)i / n * 2.0f * 3.1415926f;
            float x = gridRadius * cosf(angle);
            float y = gridRadius * sinf(angle);
            Agent agent = cluster.agents[i];
            agent.position.x = x;
            agent.position.y = y;
            drawAgent(renderer, agent);
        }
    }
    void drawMessage(SDL_Renderer* renderer, const Message& message) {
        // TODO: Draw line/arrow for message
    }
    void setCamera(const Camera& camera) {
        // TODO: Set camera/view matrix
    }
    void clear(SDL_Renderer* renderer) {
        if (renderer) {
            SDL_SetRenderDrawColor(renderer, 10, 10, 30, 255);
            SDL_RenderClear(renderer);
        }
    }
    void present(SDL_Renderer* renderer) {
        // No-op, handled in main.cpp with SDL_RenderPresent
    }
}
