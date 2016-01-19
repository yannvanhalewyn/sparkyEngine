#include <iostream>
#include "window.h"

namespace Sparky {
namespace Graphics {

    // CONSTRUCTOR
    Window::Window(const char* title, int width, int height) :
    m_title(title), m_width(width), m_height(height)
    {
        if (!init())
            glfwTerminate();
    }

    Window::~Window() {
        // Not implemented
    }

    bool Window::init() {
        if (!glfwInit()) {
            std::cout << "GLFW failed to initialize." << std::endl;
            return false;
        }

        m_window = glfwCreateWindow(m_width, m_height, m_title, NULL, NULL);

        if (!m_window) {
            glfwTerminate();
            std::cout << "Failed to create GLFW window!" << std::endl;
            return false;
        }

        glfwMakeContextCurrent(m_window);

        return true;
    }

    void Window::clear() const {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void Window::update() const {
        glfwSwapBuffers(m_window);
        glfwPollEvents();
    }

    bool Window::closed() const {
        return glfwWindowShouldClose(m_window);
    }

} }
