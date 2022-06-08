#include <iostream>
#include "GLFW/glfw3.h"

int main(int argc, char* argv[])
{
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(800, 600, "Title", NULL, NULL);
    if (window == NULL)
    {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    while (!glfwWindowShouldClose(window))
    {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;

}