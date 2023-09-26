// Renderer_v0.2.0.hpp

#pragma once
#include <d3d11.h>

class Renderer {
public:
    Renderer(HWND hWnd);
    ~Renderer();

    bool Initialize();
    void Draw();
    void Shutdown();

private:
    HWND hWnd;  // Handle to the window
    ID3D11Device* device;
    ID3D11DeviceContext* deviceContext;
    IDXGISwapChain* swapChain;
    ID3D11RenderTargetView* renderTargetView;
};
