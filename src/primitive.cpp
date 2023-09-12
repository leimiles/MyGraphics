#include "primitive.h"

const float* primitive::triangle_NDC = new float[9]
    {
        -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f, 0.5f, 0.0f
    };