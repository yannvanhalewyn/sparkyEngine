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
        void update();
        bool closed() const;

        inline int getWidth() { return m_width; }
        inline int getHeight() { return m_height; }

    private:
        const char *m_title;
        int m_width, m_height;
        GLFWwindow* m_window;

        bool init();
    };

}}
