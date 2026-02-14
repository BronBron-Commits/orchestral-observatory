Ochestral Observatory

A 3D visualization of AI agent clusters and message flows using SDL2 and OpenGL.

## Features
- Agents visualized as animated octagons
- Clusters arranged in flexible octagonal grids
- Message flows as animated lines/arrows
- Camera controls: orbit, zoom, pan
- Modular, real-time data updates

## Build Instructions

### Prerequisites
- CMake >= 3.16
- C++17 compiler
- SDL2 development libraries
- OpenGL (>=3.3)
- GLEW
- GLM

### Build
```sh
mkdir build
cd build
cmake ..
cmake --build .
```

### Run
```sh
./orchestral-observatory
```

## Project Structure
- `include/` — Header files
- `src/` — Source files
- `shaders/` — GLSL shaders
- `assets/` — Textures, fonts, icons
- `build/` — Build artifacts

## Next Steps
- Implement octagon rendering in `renderer.cpp`
- Add camera controls in `main.cpp`
- Add message flow visualization
- Integrate ImGui for debug overlay (optional)
=======
# orchestral-observatory
A C++ visualization tool for multi-agent AI orchestration. Render agents in a grid-based octagonal layout, highlighting hierarchical relationships, activity states, and message flows. Built with SDL2 and OpenGL for lightweight, real-time rendering. Designed as a modular scaffold so agent data can be plugged in later.
>>>>>>> bd5969c4cd26139252d70a6a7cda90bd6060c1ad
