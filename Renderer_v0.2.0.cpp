// Renderer_v0.2.0.cpp

#include "Renderer_v0.2.0.hpp"
#pragma comment(lib, "d3d11.lib")

Renderer::Renderer(HWND hWnd) : hWnd(hWnd), device(nullptr), deviceContext(nullptr), swapChain(nullptr), renderTargetView(nullptr) {}

Renderer::~Renderer() {
    // Destructor will be defined in Shutdown
}

bool Renderer::Initialize() {
    DXGI_SWAP_CHAIN_DESC scd;

    ZeroMemory(&scd, sizeof(DXGI_SWAP_CHAIN_DESC));

    scd.BufferCount = 1;  // Double buffering
    scd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    scd.BufferDesc.Width = 800;  // Window width
    scd.BufferDesc.Height = 600;  // Window height
    scd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    scd.OutputWindow = hWnd;
    scd.SampleDesc.Count = 1;
    scd.Windowed = TRUE;

    HRESULT hr = D3D11CreateDeviceAndSwapChain(
        nullptr,
        D3D_DRIVER_TYPE_HARDWARE,
        nullptr,
        0,
        nullptr,
        0,
        D3D11_SDK_VERSION,
        &scd,
        &swapChain,
        &device,
        nullptr,
        &deviceContext
    );

    if (FAILED(hr)) {
        return false;
    }

    // Create render target view
    ID3D11Texture2D* pBackBuffer;
    swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
    device->CreateRenderTargetView(pBackBuffer, nullptr, &renderTargetView);
    pBackBuffer->Release();

    deviceContext->OMSetRenderTargets(1, &renderTargetView, nullptr);

    return true;
}

void Renderer::Draw() {
    // Clear the back buffer to a deep blue color
    float clearColor[4] = { 0.0f, 0.2f, 0.4f, 1.0f };
    deviceContext->ClearRenderTargetView(renderTargetView, clearColor);

    // Present the back buffer to the screen
    swapChain->Present(0, 0);
}

void Renderer::Shutdown() {
    // Cleanup
    if (renderTargetView) renderTargetView->Release();
    if (swapChain) swapChain->Release();
    if (deviceContext) deviceContext->Release();
    if (device) device->Release();
}
