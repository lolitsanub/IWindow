#include "IWindow.h"

#include <iostream>

void WindowPosCallback(IWindow::Window& window, int64_t x, int64_t y) {
    std::cout << "Window position: " << x << ", " << y << '\n';
}


void WindowSizeCallback(IWindow::Window& window, int64_t width, int64_t height) {
    std::cout << "Window Size: " << width << ", " << height << '\n';
}

int main() {
    IWindow::Window window{};
    if (!window.Create(1280, 720, u8"Hello IWindow")) return EXIT_FAILURE;

    window.SetPosCallback(WindowPosCallback);
    window.SetSizeCallback(WindowSizeCallback);
    
    while (window.IsRunning()) {

        if (window.IsKeyDown(IWindow::Key::A, IWindow::Key::W) && window.IsKeyUp(IWindow::Key::Alt))
            std::cout << "Key A and W were pressed!\n";

        window.Update();
    }
}