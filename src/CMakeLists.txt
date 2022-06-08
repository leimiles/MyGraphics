cmake_minimum_required(VERSION 3.21.3)      # cmake minimum version

add_library(myLib                           # build a lib
    light.cpp
    util.cpp
)

target_include_directories(myLib            # set lib include files
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)


target_compile_features(myLib               # enable c++17 feature
    PUBLIC
        cxx_std_17
)


