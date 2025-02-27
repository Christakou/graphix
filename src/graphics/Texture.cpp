#include "Texture.h"

#include <iostream>
#include <ostream>
#include <string>
#include<stb/stb_image.h>
#include <glad/glad.h>

Texture::Texture(const char* filePath, GLint targetTexture, GLint textureUnit) {

    std::string completeFilePath =  std::string(PROJECT_ROOT_DIR) + "/textures/" + std::string(filePath);
    m_targetTexture = targetTexture;
    int widthImg, heightImg, numColCh;
    unsigned char* bytes = stbi_load(completeFilePath.c_str(), &widthImg, &heightImg, &numColCh, 0);

    if (!bytes) {
        std::cerr << "Error loading texture from " << completeFilePath << std::endl;
    }

    glGenTextures(1, &ID);
    glActiveTexture(textureUnit);
    glBindTexture(targetTexture, ID);

    glTexParameteri(targetTexture, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(targetTexture, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glTexParameteri(targetTexture, GL_TEXTURE_WRAP_S, GL_REPEAT);

    glTexParameteri(targetTexture, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexImage2D(targetTexture, 0, GL_RGBA, widthImg, heightImg, 0, GL_RGBA, GL_UNSIGNED_BYTE, bytes);

    glGenerateMipmap(targetTexture);

    stbi_image_free(bytes);


    glBindTexture(targetTexture, 0);
}

void Texture::Bind() const {
    glBindTexture(m_targetTexture, ID);
}

void Texture::Unbind() const {
    glBindTexture(m_targetTexture, 0);
}