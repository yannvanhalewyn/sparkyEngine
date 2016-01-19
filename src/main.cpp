#include "window.h"
#include <iostream>

#ifdef DEBUG
    #define LOG(x) std::cout << x << std::endl;
#else
    #define LOG(x)
#endif

int main(int argc, char *argv[])
{
    Sparky::Graphics::Window w("Game", 640, 480);

    while(!glfwWindowShouldClose(w.getGLFWwindow())) {
        glfwSwapBuffers(w.getGLFWwindow());
        glfwPollEvents();
    }

    glfwTerminate();

    LOG("foobar")

    return 0;
}
