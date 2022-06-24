#ifndef RENDERPIPELINE_H
#define RENDERPIPELINE_H
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <string>

class renderPipeline
{
private:
    /* data */
public:
    renderPipeline(/* args */);
    ~renderPipeline();
    void clearTarget();
    void debug(std::string info);
    void renderLoop();
    static void prepareUIContext(GLFWwindow* window);
    static void releaseUIContext();
};

#endif