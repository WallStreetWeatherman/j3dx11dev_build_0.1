// EngineCore_v0.1.0.hpp

#pragma once
#include <windows.h>

class Renderer;  // Forward declaration

class EngineCore {
public:
    EngineCore();
    ~EngineCore();

    void Initialize(HINSTANCE hInstance, int nCmdShow);
    void Run();
    void Shutdown();

private:
    Renderer* renderer;  // Renderer instance
};
