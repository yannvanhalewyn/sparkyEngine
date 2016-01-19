#include <iostream>
#include "window.h"

namespace Sparky {
namespace Graphics {

    bool Window::m_keys[MAX_KEYS];
    bool Window::m_mouse_buttons[MAX_BUTTONS];
    void window_resize(GLFWwindow *window, int width, int height);
    void key_callback(GLFWwindow* window,
            int key, int scancode, int action, int mods);

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
        glfwSetWindowUserPointer(m_window, this);
        glfwSetWindowSizeCallback(m_window, window_resize);
        glfwSetKeyCallback(m_window, key_callback);

        std::cout << glGetString(GL_VERSION) << std::endl;
        printf("Supported GLSL version is %s.\n",
                (char *) glGetString(GL_SHADING_LANGUAGE_VERSION));

        return true;
    }

    void Window::clear() const {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void Window::update() {
        glfwSwapBuffers(m_window);
        glfwPollEvents();
    }

    bool Window::closed() const {
        return glfwWindowShouldClose(m_window);
    }

    void window_resize(GLFWwindow *window, int width, int height) {
        // Not necessary for mac
        glViewport(0, 0, width, height);
    }

    void key_callback(GLFWwindow* window, int key,
                      int scancode, int action, int mods) {
        Window *win = (Window*) glfwGetWindowUserPointer(window);
        win->m_keys[key] = action != GLFW_RELEASE;
    }

    bool Window::isKeyPressed(unsigned int key) {
        // TODO: Log This!
        if (key >= MAX_KEYS) return false;
        return m_keys[key];
    }

} }
