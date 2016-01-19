#pragma once

#include <GLFW/glfw3.h>

namespace Sparky {
namespace Graphics {

    class Window
    {
    public:
        Window(const char* title, int width, int height);
        ~Window();
        void update() const;
        GLFWwindow* getGLFWwindow() { return m_window; }

    private:
        const char *m_title;
        int m_width, m_height;
        GLFWwindow* m_window;

        void init();
    };

}}
