#pragma once

#define MAX_KEYS    1024
#define MAX_BUTTONS 32

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

        static bool isKeyPressed(unsigned int key);
    private:
        const char *m_title;
        int m_width, m_height;
        GLFWwindow* m_window;
        static bool m_keys[MAX_KEYS];
        static bool m_mouse_buttons[MAX_BUTTONS];
        static double m_mousex, m_mousey;

        bool init();
        friend void key_callback(GLFWwindow* window, int key,
                                 int scancode, int action, int mods);
    };

}}
