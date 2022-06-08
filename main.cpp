#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "util.h"
#include "renderPipeline.h"

int main(int argc, char* argv[])
{
    util::hideConsole();
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(800, 600, "MyGraphics_OpenGL", NULL, NULL);
    if (window == NULL)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to init GLAD." << std::endl;
        return -1;
    }

    renderPipeline mrp;

    while (!glfwWindowShouldClose(window))
    {
        mrp.clearTarget();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;

}