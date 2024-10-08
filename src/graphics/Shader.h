#ifndef SHADER_H
#define SHADER_H

#include <../../include/glad/glad.h>
#include<string>
#include<fstream>
#include<iostream>
#include<cerrno>


class Shader
{
public:
    GLuint ID;
    Shader(const char* vertexFile, const char* fragmentFile);

    void Activate() const;
    void Delete() const;
private:
    static std::string _get_file_contents(const char* filename);

};
#endif