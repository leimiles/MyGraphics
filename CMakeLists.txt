cmake_minimum_required(VERSION 3.21.3)      # cmake minimum version
project(MyGraphics VERSION 0.1.0)           # project version

include(CTest)
enable_testing()

set(EXE_NAME myGraphic)                     # set program name


add_executable(${EXE_NAME} main.cpp)        # build an exe file

add_subdirectory(src)                       # build subdirectory
target_link_libraries(${EXE_NAME} myLib)    # link library

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)


target_compile_features(${EXE_NAME}         # enable c++17 feature
    PUBLIC
        cxx_std_17
)