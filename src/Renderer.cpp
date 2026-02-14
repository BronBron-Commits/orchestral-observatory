#include "Renderer.h"
#include <iostream>
#include <cmath>

Renderer::Renderer(int width, int height)
    : width(width), height(height), window(nullptr), glContext(nullptr) {}

Renderer::~Renderer() {
    cleanup();
}

bool Renderer::initialize() {
    if (!initSDL()) {
        return false;
    }
    
    if (!initOpenGL()) {
        return false;
    }
    
    setupScene();
    return true;
}

bool Renderer::initSDL() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL initialization failed: " << SDL_GetError() << std::endl;
        return false;
    }
    
    // Set OpenGL attributes
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    
    // Create window
    window = SDL_CreateWindow(
        "Orchestral Observatory",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN
    );
    
    if (!window) {
        std::cerr << "Window creation failed: " << SDL_GetError() << std::endl;
        return false;
    }
    
    // Create OpenGL context
    glContext = SDL_GL_CreateContext(window);
    if (!glContext) {
        std::cerr << "OpenGL context creation failed: " << SDL_GetError() << std::endl;
        return false;
    }
    
    SDL_GL_SetSwapInterval(1); // Enable vsync
    
    return true;
}

bool Renderer::initOpenGL() {
    // Initialize GLEW
    glewExperimental = GL_TRUE;
    GLenum glewError = glewInit();
    if (glewError != GLEW_OK) {
        std::cerr << "GLEW initialization failed: " << glewGetErrorString(glewError) << std::endl;
        return false;
    }
    
    // Set viewport
    glViewport(0, 0, width, height);
    
    // Enable blending for transparency
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    // Load shaders
    shaderProgram = std::make_unique<ShaderProgram>();
    if (!shaderProgram->loadShaders("shaders/vertex.glsl", "shaders/fragment.glsl")) {
        std::cerr << "Failed to load shaders" << std::endl;
        return false;
    }
    
    // Set orthographic projection
    setOrthographicProjection();
    
    return true;
}

void Renderer::setOrthographicProjection() {
    // Create orthographic projection matrix for 2D rendering
    float left = -400.0f;
    float right = 400.0f;
    float bottom = -300.0f;
    float top = 300.0f;
    
    float projection[16] = {
        2.0f / (right - left), 0.0f, 0.0f, 0.0f,
        0.0f, 2.0f / (top - bottom), 0.0f, 0.0f,
        0.0f, 0.0f, -1.0f, 0.0f,
        -(right + left) / (right - left), -(top + bottom) / (top - bottom), 0.0f, 1.0f
    };
    
    shaderProgram->use();
    shaderProgram->setMat4("projection", projection);
}

void Renderer::setupScene() {
    // Create grid (20x20 grid with 40 pixel cells)
    grid = std::make_unique<Grid>(15, 20, 40.0f);
    
    // Create central octagon
    octagon = std::make_unique<Octagon>(0.0f, 0.0f, 150.0f);
    
    // Create nodes in hierarchical layout
    // Project Manager at the top
    nodes.push_back(std::make_unique<Node>(0.0f, 150.0f, 25.0f, NodeRole::PROJECT_MANAGER, "PM"));
    
    // Senior Engineer in the middle
    nodes.push_back(std::make_unique<Node>(0.0f, 0.0f, 25.0f, NodeRole::SENIOR_ENGINEER, "Senior"));
    
    // Two Junior Engineers at the bottom
    nodes.push_back(std::make_unique<Node>(-100.0f, -150.0f, 25.0f, NodeRole::JUNIOR_ENGINEER, "Junior 1"));
    nodes.push_back(std::make_unique<Node>(100.0f, -150.0f, 25.0f, NodeRole::JUNIOR_ENGINEER, "Junior 2"));
    
    // Create connection lines
    // Junior 1 -> Senior
    lines.push_back(std::make_unique<Line>(-100.0f, -150.0f, 0.0f, 0.0f));
    
    // Junior 2 -> Senior
    lines.push_back(std::make_unique<Line>(100.0f, -150.0f, 0.0f, 0.0f));
    
    // Senior -> Project Manager
    lines.push_back(std::make_unique<Line>(0.0f, 0.0f, 0.0f, 150.0f));
}

void Renderer::render() {
    // Clear screen with dark background
    glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    shaderProgram->use();
    
    // Render grid
    grid->render();
    
    // Render octagon
    octagon->render();
    
    // Render connection lines
    for (auto& line : lines) {
        line->render();
    }
    
    // Render nodes
    for (auto& node : nodes) {
        node->render();
    }
    
    SDL_GL_SwapWindow(window);
}

void Renderer::handleEvents(bool& running) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            running = false;
        } else if (event.type == SDL_KEYDOWN) {
            if (event.key.keysym.sym == SDLK_ESCAPE) {
                running = false;
            }
        }
    }
}

void Renderer::run() {
    bool running = true;
    
    std::cout << "Orchestral Observatory running..." << std::endl;
    std::cout << "Press ESC to exit" << std::endl;
    
    while (running) {
        handleEvents(running);
        render();
        SDL_Delay(16); // ~60 FPS
    }
}

void Renderer::cleanup() {
    nodes.clear();
    lines.clear();
    octagon.reset();
    grid.reset();
    shaderProgram.reset();
    
    if (glContext) {
        SDL_GL_DeleteContext(glContext);
        glContext = nullptr;
    }
    
    if (window) {
        SDL_DestroyWindow(window);
        window = nullptr;
    }
    
    SDL_Quit();
}
