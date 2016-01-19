#include <iostream>
#include "window.h"

namespace Sparky {
namespace Graphics {

    // CONSTRUCTOR
    Window::Window(const char* title, int width, int height) :
    m_title(title), m_width(width), m_height(height)
    {
        init();
    }

    Window::~Window() {
        // Not implemented
    }

    void Window::init() {
        if (!glfwInit())
            return;

        m_window = glfwCreateWindow(m_width, m_height, m_title, NULL, NULL);

        if (!m_window) {
            glfwTerminate();
            std::cout << "Failed to create GLFW window!" << std::endl;
            return;
        }

        glfwMakeContextCurrent(m_window);
    }
} }
