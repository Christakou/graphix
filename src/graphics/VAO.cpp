#include"VAO.h"

// Constructor that generates a VAO ID
VAO::VAO()
{
    glGenVertexArrays(1, &ID);
}

// Links a VBO to the VAO using a certain layout
void VAO::LinkAttrib(VBO& VBO, const GLuint layout, const GLuint numComponents, const GLenum type, const GLsizeiptr stride, const void* offset)
{
    VBO.Bind();
    glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
    glEnableVertexAttribArray(layout);
    VBO.Unbind();
}

// Binds the VAO
void VAO::Bind() const {
    glBindVertexArray(ID);
}

// Unbinds the VAO
void VAO::Unbind() const{
    glBindVertexArray(0);
}

// Deletes the VAO
void VAO::Delete() const {
    glDeleteVertexArrays(1, &ID);
}
