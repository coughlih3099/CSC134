# Technical Game Engine Design Document

## Title
Mythos Game Engine

## Company
Smooth Brain Dev

# Introduction

## Summary/Pitch
A hybrid game engine leveraging both Object-Oriented Programming (OOP) and Data-Oriented Design (DoD) principles to create a flexible, performant framework for game development. The engine uses Raylib as its foundational layer while introducing a custom architecture that optimizes for both development ergonomics and runtime performance.

## Technical Inspirations
- Raylib: Core rendering and window management
- EnTT: Modern C++ Entity Component System
- Unity DOTS: Hybrid OOP/DoD approach
- Bevy Engine: Rust-based ECS architecture patterns

## Platform
- Primary: PC (Windows, Linux, MacOS)
- Secondary: Potential for console ports through Raylib's platform support

## Software
- Core Engine: C++17/20
- Graphics API: Raylib
- Build System: CMake
- Testing Framework: doctest

## Target Audience
- Game developers who want:
  - Direct control over performance-critical systems
  - Clean separation between engine and game logic
  - Modern C++ practices without excessive template metaprogramming
  - Straightforward integration with existing C++ codebases

# Technical Architecture

## Core Systems Design

### System Categories

1. **Service Objects (OOP)**
   - Window Management (implemented)
   - Asset Management
   - Input System
   - Audio System
   - File I/O
   - Configuration Management
   
2. **Performance-Critical Systems (DoD/ECS)**
   - Physics
   - Rendering
   - Collision Detection
   - Particle Systems
   - Animation
   - Scene Graph

### Component Design

```cpp
// Example component structures for DoD approach
struct Transform {
    Vector3 position;
    Vector3 rotation;
    Vector3 scale;
};

struct Velocity {
    Vector3 linear;
    Vector3 angular;
};

struct RenderableSprite {
    Texture2D* texture;
    Rectangle sourceRect;
    Color tint;
};
```

## Core Loop Design

```cpp
class Engine {
    // Service objects (OOP)
    Window window;
    AssetManager assets;
    InputManager input;
    
    // ECS World/Registry
    Registry registry;
    
    // Systems (DoD)
    PhysicsSystem physics;
    RenderSystem renderer;
    
public:
    void update() {
        input.poll();
        physics.update(registry);
        renderer.update(registry);
    }
};
```

## Data Layout

### Memory Management
- Custom allocators for different subsystems
- Component pools for ECS data
- Object pools for frequently created/destroyed objects
- RAII for resource management

### Cache Optimization
- Components stored in contiguous arrays
- Systems process components in a cache-friendly manner
- Minimal virtual function calls in hot paths

## Subsystem Integration

### Window Management
Currently implemented features:
- Window creation and destruction
- Size management (minimum, maximum, current)
- Window state flags
- Test-friendly design with mode switching

Planned features:
- Event system integration (window resize, focus, close events)
- High DPI display support
- Proper handling of window minimize/maximize states
- Fullscreen mode transitions
- Window icon customization

### Rendering System
- Batch rendering for sprites
- Custom shader support
- Render command queuing
- Material system
- Layer/sorting system

### Physics System
- Spatial partitioning
- Broad and narrow phase collision detection
- Resolution system
- Physics material properties
- Constraint solver

# Implementation Priorities

## Phase 1: Core Architecture
- [x] Window management system
- [ ] Basic ECS implementation
- [ ] Event system
- [ ] Asset loading system

## Phase 2: Rendering
- [ ] Sprite batch renderer
- [ ] Basic shader system
- [ ] Primitive shapes
- [ ] Text rendering

## Phase 3: Physics
- [ ] Spatial partitioning
- [ ] Collision detection
- [ ] Basic physics resolution
- [ ] Trigger systems

## Phase 4: Tools
- [ ] Scene serialization
- [ ] Debug visualization
- [ ] Profiling tools
- [ ] Memory tracking

# Technical Requirements

## Performance Targets
- 60+ FPS on mid-range hardware
- < 16ms frame time budget
- < 1ms for physics updates
- < 100MB base memory footprint

## Quality Assurance
- Unit tests for all core systems
- Integration tests for subsystem interaction
- Performance benchmarks
- Memory leak detection
- Static analysis integration

## Platform Support
- Linux (primary)
- Windows (secondary)
- MacOS (maybe)
- Potential for console support through Raylib

# Documentation Requirements

## API Documentation
- Full Doxygen coverage
- Usage examples
- Best practices guide
- Performance guidelines

## Internal Documentation
- System architecture diagrams
- Data flow documentation
- Memory layout documentation
- Build system documentation
