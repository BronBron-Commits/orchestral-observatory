#include "cluster.hpp"
#include "renderer.hpp"

void Cluster::renderCluster() const {
    extern SDL_Renderer* g_renderer;
    Renderer::drawCluster(g_renderer, *this);
}

void Cluster::updateAgents() {
    for (auto& agent : agents) {
        agent.updateState();
    }
}
