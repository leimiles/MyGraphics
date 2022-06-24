#ifndef RENDERPIPELINE_H
#define RENDERPIPELINE_H
#include "glad/glad.h"
#include "GLFW/glfw3.h"

class renderPipeline
{
private:
    /* data */
public:
    renderPipeline(/* args */);
    ~renderPipeline();
    void clearTarget();
    void ImGuiDemo();
    static void prepareImGuiContext(GLFWwindow* window);
    static void releaseImGuiContext();
};

#endif