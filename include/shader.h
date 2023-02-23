#ifndef SHADER_H
#define SHADER_H
#include <string>

class shader
{
private:
    static std::string shaderFileReader(const char* fileName, bool isValidate);
public:
    shader(/* args */);
    ~shader();
};

#endif
