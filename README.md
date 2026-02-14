# orchestral-observatory
A C++ visualization tool for multi-agent AI orchestration. Render agents in a grid-based octagonal layout, highlighting hierarchical relationships, activity states, and message flows. Built with SDL2 and OpenGL 3.3 Core for lightweight, real-time rendering. Designed as a modular scaffold so agent data can be plugged in later.

## Features

- **2D Orthographic Grid**: Background grid for spatial reference
- **Central Octagon**: Visual boundary for the agent hierarchy
- **Hierarchical Node Layout**: 
  - Project Manager (red) at the top
  - Senior Engineer (blue) in the middle
  - Two Junior Engineers (green) at the bottom
- **Connection Lines**: Visual representation of hierarchical relationships (Juniors → Senior → PM)
- **Modular Architecture**: Separate classes for Grid, Octagon, Node, Line, and Renderer

## Project Structure

```
orchestral-observatory/
├── CMakeLists.txt          # Build configuration
├── README.md               # This file
├── .gitignore             # Git ignore rules
├── include/               # Header files
│   ├── Renderer.h         # Main renderer class
│   ├── ShaderProgram.h    # Shader management
│   ├── Grid.h             # Grid rendering
│   ├── Octagon.h          # Octagon rendering
│   ├── Node.h             # Agent node rendering
│   └── Line.h             # Connection line rendering
├── src/                   # Source files
│   ├── main.cpp           # Entry point
│   ├── Renderer.cpp       # Renderer implementation
│   ├── ShaderProgram.cpp  # Shader management
│   ├── Grid.cpp           # Grid implementation
│   ├── Octagon.cpp        # Octagon implementation
│   ├── Node.cpp           # Node implementation
│   └── Line.cpp           # Line implementation
└── shaders/               # GLSL shaders
    ├── vertex.glsl        # Vertex shader
    └── fragment.glsl      # Fragment shader
```

## Prerequisites

### Ubuntu/Debian
```bash
sudo apt-get update
sudo apt-get install build-essential cmake
sudo apt-get install libsdl2-dev libglew-dev libgl1-mesa-dev
```

### macOS
```bash
brew install cmake sdl2 glew
```

### Arch Linux
```bash
sudo pacman -S cmake sdl2 glew mesa
```

## Building

1. Create a build directory:
```bash
mkdir build
cd build
```

2. Configure with CMake:
```bash
cmake ..
```

3. Build the project:
```bash
make
```

4. Run the application:
```bash
./orchestral_observatory
```

## Usage

- The application will display a window with the grid, octagon, and hierarchical node layout
- Press **ESC** to exit the application
- The visualization shows:
  - **Red node**: Project Manager (top)
  - **Blue node**: Senior Engineer (middle)
  - **Green nodes**: Junior Engineers (bottom left and right)
  - **Yellow lines**: Hierarchical connections

## Architecture

### Modular Design

Each visual component is encapsulated in its own class:

- **Renderer**: Main class that orchestrates the rendering pipeline
- **ShaderProgram**: Manages OpenGL shader compilation and linking
- **Grid**: Renders the background grid
- **Octagon**: Renders the central octagonal boundary
- **Node**: Renders agent nodes as colored circles (color based on role)
- **Line**: Renders connection lines between nodes

### OpenGL 3.3 Core

The project uses modern OpenGL with:
- Vertex Array Objects (VAOs)
- Vertex Buffer Objects (VBOs)
- GLSL shaders for rendering
- Orthographic projection for 2D rendering

### Extensibility

The modular architecture makes it easy to:
- Add new node types and roles
- Implement dynamic node positioning
- Add animations and state changes
- Integrate real agent data
- Extend with additional visual elements

## Future Enhancements

- Dynamic agent data integration
- Real-time message flow visualization
- Agent activity state indicators
- Interactive node selection
- Configurable layouts
- Performance metrics overlay
