#pragma once
#include <vector>
#include <string>
#include "agent.hpp"

struct Cluster {
    int id;
    std::vector<Agent> agents;
    std::string type; // coding/research/validation

    void renderCluster() const;
    void updateAgents();
};
