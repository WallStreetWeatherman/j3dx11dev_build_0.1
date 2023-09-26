// EngineCore_v0.1.0.cpp

#include "EngineCore_v0.1.0.hpp"
#include "Renderer_v0.1.0.hpp"  // Include the Renderer header

EngineCore::EngineCore() : renderer(nullptr) {}

EngineCore::~EngineCore() {
    // Destructor will be defined later
}

void EngineCore::Initialize(HINSTANCE hInstance, int nCmdShow) {
    // Initialize DirectX, Window, etc. (You'll define these later)

    // Initialize the Renderer
    renderer = new Renderer();
    renderer->Initialize();
}

void EngineCore::Run() {
    // Main game loop
    while (true) {
        // ... Game logic, input, etc.

        // Call renderer draw method
        if (renderer) {
            renderer->Draw();
        }
    }
}

void EngineCore::Shutdown() {
    // Cleanup resources
    if (renderer) {
        renderer->Shutdown();
        delete renderer;
    }
}
