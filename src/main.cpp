#include "Renderer.h"
#include <iostream>

int main(int argc, char* argv[]) {
    const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 600;
    
    Renderer renderer(WINDOW_WIDTH, WINDOW_HEIGHT);
    
    if (!renderer.initialize()) {
        std::cerr << "Failed to initialize renderer" << std::endl;
        return 1;
    }
    
    renderer.run();
    
    return 0;
}
