#pragma once
#include <string>

struct Message {
    int from_agent_id;
    int to_agent_id;
    std::string status; // sent, in-transit, received

    void renderFlow() const;
    void updateFlow();
};
