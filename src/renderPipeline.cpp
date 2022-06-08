#include "renderPipeline.h"
#include "glad/glad.h"

renderPipeline::renderPipeline(/* args */)
{
}

renderPipeline::~renderPipeline()
{
}

void renderPipeline::clearTarget()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}