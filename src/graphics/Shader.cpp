#include "../graphics/Shader.h"
#include <cerrno>
#include <stdexcept>
#include <fstream>
#include <cstring>



Shader::Shader(const char* vertexFile, const char* fragmentfile) {

    const char* vertexSource = _get_file_contents(vertexFile).c_str();
    const char* fragmentSource = _get_file_contents(fragmentfile).c_str();

    // Create Vertex Shader Object and get its reference
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    // Attach Vertex Shader source to the Vertex Shader Object
    glShaderSource(vertexShader, 1, &vertexSource, NULL);
    // Compile the Vertex Shader into machine code
    glCompileShader(vertexShader);

    // Create Fragment Shader Object and get its reference
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    // Attach Fragment Shader source to the Fragment Shader Object
    glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
    glCompileShader(fragmentShader);

    ID = glCreateProgram();
    glAttachShader(ID, vertexShader);
    glAttachShader(ID, fragmentShader);
    glLinkProgram(ID);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void Shader::Activate() const {
    glUseProgram(ID);
}

void Shader::Delete() const {
    glDeleteProgram(ID);
}

std::string Shader::_get_file_contents(const char* filename)
{
    if (std::ifstream fileInputStream(filename, std::ios::binary); fileInputStream)
    {
        std::string contents;

        // We need seek to the end of the file to get the file size
        fileInputStream.seekg(0, std::ios::end);
        const size_t buffer_size = fileInputStream.tellg();
        contents.resize(buffer_size);
        fileInputStream.seekg(0, std::ios::beg);
        fileInputStream.read(&contents[0], buffer_size);
        fileInputStream.close();
        return contents;
    }
    throw std::runtime_error("Failed to open file " + std::string(filename) + ": " + std::strerror(errno));
}