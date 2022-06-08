cmake_minimum_required(VERSION 3.21.3)      # cmake minimum version
project(MyGraphics VERSION 0.1.0)           # project version

include(CTest)
enable_testing()

set(EXE_NAME myGraphic)                     # set program name


add_executable(${EXE_NAME} main.cpp)        # build an exe file

add_subdirectory(src)                       # build subdirectory
add_subdirectory(3rd/glfw)
add_subdirectory(3rd/glad)

target_link_libraries(
    ${EXE_NAME}
        myLib
        glfw
        glad
)    # link library

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
# Update submodules as needed   更新子模块
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                    RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMODE_RESULT}, please check")
        endif()
    endif()
endif()
# CHECK ALL THE SUBMODULES  检查子模块
# "$ git submodule add https://github.com/glfw/glfw.git 3rd/glfw" this is the example about how you kan add submodule
if(NOT EXISTS "${PROJECT_SOURCE_DIR}/3rd/glfw/CMakeLists.txt")
    message(FATAL_ERROR "the glfw submodules was not downloaded!")
endif()

if(NOT EXISTS "${PROJECT_SOURCE_DIR}/3rd/glad/CMakeLists.txt")
    message(FATAL_ERROR "the glad submodules was not downloaded!")
endif()