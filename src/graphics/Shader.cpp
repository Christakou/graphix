#include "Shader.h"





Shader::Shader(const char* vertexFile, const char* fragmentfile) {
    const std::string vertexFullPath = std::string(PROJECT_ROOT_DIR) + "/shaders/" + std::string(vertexFile);
    const std::string fragmentFullPath = std::string(PROJECT_ROOT_DIR) + "/shaders/" + std::string(fragmentfile);
    const char* vertexSource = _get_file_contents(vertexFullPath).c_str();
    const char* fragmentSource = _get_file_contents(fragmentFullPath).c_str();

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexSource, NULL);
    glCompileShader(vertexShader);
    checkCompileErrors(vertexShader, "VERTEX");
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
    glCompileShader(fragmentShader);
    checkCompileErrors(fragmentShader, "FRAGMENT");
    ID = glCreateProgram();
    glAttachShader(ID, vertexShader);
    glAttachShader(ID, fragmentShader);
    glLinkProgram(ID);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void Shader::checkCompileErrors(GLuint shader, std::string type) {
    GLint success;
    GLchar infoLog[1024];
    if (type != "PROGRAM") {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(shader, 1024, NULL, infoLog);
            std::cerr << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
        }
    } else {
        glGetProgramiv(shader, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(shader, 1024, NULL, infoLog);
            std::cerr << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
        }
    }
}

std::string Shader::_get_file_contents(const std::string &filename)
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
    throw std::runtime_error("Failed to open file " + std::string(filename));
}

void Shader::Activate() const {
    // Use the Shader Program
    glUseProgram(ID);
}

void Shader::Delete() const {
    // Delete the Shader Program
    glDeleteProgram(ID);
}