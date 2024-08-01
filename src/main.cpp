#define GLM_ENABLE_EXPERIMENTAL
#include<iostream>
#include<glad/glad.h>
#include<stb/stb_image.h>
#include<GLFW/glfw3.h>

int main() {
    constexpr unsigned int width = 800;
    constexpr unsigned int height = 800;
    if (!glfwInit()) {
        std::cout << "Failed to initialize GLFW\n";
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow* window = glfwCreateWindow(width, height, "TestWindow", NULL, NULL);
    if (window == nullptr) {
        std::cout << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD\n";
        return -1;
    }

    glViewport(0, 0, width, height);

    while (!glfwWindowShouldClose(window)) {
        // Render loop
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}