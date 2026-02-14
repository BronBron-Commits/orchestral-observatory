#include <SDL.h>
// Global renderer pointer for use in cluster.cpp
SDL_Renderer* g_renderer = nullptr;
#include <iostream>
#include "renderer.hpp"
#include "camera.hpp"
#include "cluster.hpp"

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Failed to initialize SDL2: " << SDL_GetError() << std::endl;
        return -1;
    }

    SDL_Window* window = SDL_CreateWindow(
        "Orchestral Observatory",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        1280, 720,
        SDL_WINDOW_SHOWN
    );
    if (!window) {
        std::cerr << "Failed to create window: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return -1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Failed to create renderer: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }


    Renderer::init(renderer);
    Camera camera;

    // Test data: one cluster with three agents
    Cluster cluster;
    cluster.id = 1;
    cluster.type = "coding";
    for (int i = 0; i < 3; ++i) {
        Agent agent;
        agent.id = i;
        agent.role = "Codex";
        agent.position = Vec3(i * 2.0f, 0.0f, 0.0f);
        agent.activity_level = 0.5f;
        cluster.agents.push_back(agent);
    }
    // Make renderer globally accessible for now
    g_renderer = renderer;

    bool running = true;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) running = false;
            // TODO: Camera controls
        }
        Renderer::setCamera(camera);
        Renderer::clear(renderer);
        cluster.renderCluster();
        Renderer::present(renderer);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
