#include <iostream>
#include "util.h"
#include "renderPipeline.h"

int main(int argc, char* argv[])
{
    util::hideConsole();
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(800, 600, "MyGraphics_OpenGL", nullptr, nullptr);
    if (!window)
    {
        glfwTerminate();
        throw std::runtime_error("Error creating glfw window");
        return -1;
    }

    glfwMakeContextCurrent(window);
    // enable v-sync
    glfwSwapInterval(1);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to init GLAD." << std::endl;
        return -1;
    }

    renderPipeline::prepareUIContext(window);
    renderPipeline mrp;

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        mrp.clearTarget();
        mrp.debug("this is debug info.");
        glfwSwapBuffers(window);
    }

    renderPipeline::releaseUIContext();

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}