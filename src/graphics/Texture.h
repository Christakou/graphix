#ifndef Texture_CLASS_H
#define Texture_CLASS_H

#include<glad/glad.h>
#include"VBO.h"
class Texture
{
public:
    Texture(const char* filePath, GLint targetTexture, GLint textureUnit);
    unsigned char* bytes = nullptr;
    GLuint ID{};

    void Bind() const;

    void Unbind() const;

private:
    GLuint m_targetTexture;
};

#endif
