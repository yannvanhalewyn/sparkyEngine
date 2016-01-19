#include "graphics/window.h"
#include <iostream>

#ifdef DEBUG
    #define LOG(x) std::cout << x << std::endl;
#else
    #define LOG(x)
#endif

int main(int argc, char *argv[])
{
    Sparky::Graphics::Window w("Game", 960, 540);
    glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

    while(!w.closed()) {
        w.clear();
        glBegin(GL_TRIANGLES);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f( 0.0f,  0.5f);
        glVertex2f( 0.5f, -0.5f);
        glEnd();
        w.update();
    }

    glfwTerminate();

    return 0;
}
