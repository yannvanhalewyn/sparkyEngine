#pragma once

#include <GLFW/glfw3.h>

namespace Sparky {
namespace Graphics {

    class Window
    {
    public:
        Window(const char* title, int width, int height);
        ~Window();
        void clear() const;
        void update() const;
        bool closed() const;

    private:
        const char *m_title;
        int m_width, m_height;
        GLFWwindow* m_window;

        bool init();
    };

}}
