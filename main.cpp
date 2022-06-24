#include <iostream>
#include "util.h"
#include "renderPipeline.h"

int main(int argc, char* argv[])
{
    util::hideConsole();

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "MyGraphics_OpenGL", nullptr, nullptr);
    if (!window)
    {
        throw std::runtime_error("Error creating glfw window");
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);    // enable v-sync

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        throw std::runtime_error("Error creating glad loader");
    }

    renderPipeline::prepareUIContext(window, "#version 460 core");
    renderPipeline mrp;

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        mrp.renderLoop();
        glfwSwapBuffers(window);
    }

    renderPipeline::releaseUIContext();

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}