cmake_minimum_required(VERSION 3.21.3)  # cmake minimum version

set(IMGUI_HEADER_DIR 
    ${PROJECT_SOURCE_DIR}/3rd/imgui
    ${PROJECT_SOURCE_DIR}/3rd/imgui/backends
)   # set imgui header path

set(IMGUI_SOURCE_DIR
    ${PROJECT_SOURCE_DIR}/3rd/imgui/imgui.cpp
    ${PROJECT_SOURCE_DIR}/3rd/imgui/imgui_draw.cpp
    ${PROJECT_SOURCE_DIR}/3rd/imgui/imgui_demo.cpp
    ${PROJECT_SOURCE_DIR}/3rd/imgui/imgui_widgets.cpp
    ${PROJECT_SOURCE_DIR}/3rd/imgui/imgui_tables.cpp
    ${PROJECT_SOURCE_DIR}/3rd/imgui/backends/imgui_impl_glfw.cpp
    ${PROJECT_SOURCE_DIR}/3rd/imgui/backends/imgui_impl_opengl3.cpp
)   # set imgui src path

set(GLFW_HEADER_DIR
    ${PROJECT_SOURCE_DIR}/3rd/glfw/include
)

set(GLM_HEADER_DIR
    ${PROJECT_SOURCE_DIR}/3rd/glm
)

add_library(myLib
    light.cpp
    util.cpp
    renderPipeline.cpp
    geometryData.cpp
    ${IMGUI_SOURCE_DIR}
)   # build a lib

target_include_directories(myLib
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
        ${IMGUI_HEADER_DIR}
        ${GLFW_HEADER_DIR}
        ${GLAD_OUT_DIR}/include
        ${GLM_HEADER_DIR}
)   # set lib include files

target_compile_features(myLib
    PUBLIC
        cxx_std_17
)   # enable c++17 feature
