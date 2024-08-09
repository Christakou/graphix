#ifndef EBO_CLASS_H
#define EBO_CLASS_H
#include<glad/glad.h>

class EBO
{
public:
    GLuint ID;
    EBO(const GLuint* indices, GLsizeiptr size);

    void Bind() const;

    void Unbind() const;
    void Delete() const;
};

#endif