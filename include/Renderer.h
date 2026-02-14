#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <memory>
#include <vector>
#include "ShaderProgram.h"
#include "Grid.h"
#include "Octagon.h"
#include "Node.h"
#include "Line.h"

class Renderer {
public:
    Renderer(int width, int height);
    ~Renderer();
    
    bool initialize();
    void run();
    void cleanup();
    
private:
    int width, height;
    SDL_Window* window;
    SDL_GLContext glContext;
    
    std::unique_ptr<ShaderProgram> shaderProgram;
    std::unique_ptr<Grid> grid;
    std::unique_ptr<Octagon> octagon;
    std::vector<std::unique_ptr<Node>> nodes;
    std::vector<std::unique_ptr<Line>> lines;
    
    bool initSDL();
    bool initOpenGL();
    void setupScene();
    void render();
    void handleEvents(bool& running);
    void setOrthographicProjection();
};

#endif
