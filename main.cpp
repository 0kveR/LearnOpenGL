// Copyright Krrish Verma 2024

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

void processInput(GLFWwindow* window);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

int main() {
    // Initial Setup
    glfwInit();
    // Informs glfw we are using OpenGL 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    /* We are using the core profile.
     * From LearnOpenGL: "we'll get access to a smaller subset of OpenGL features without backwards-compatible
     * features we no longer need"*/
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Initialize window
    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL) {
        std::cout << "ERROR: Failed to create the window." << std::endl;
        return 1;
    }
    // Makes window main context on the current thread
    glfwMakeContextCurrent(window);

    // Make sure to initialize GLAD before calling any OpenGL functions!
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // Sets callback fn to make content scale with window
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Prevent window from closing on its own
    while(!glfwWindowShouldClose(window)) {
        processInput(window);

        // Changes color
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Checks for any events and swaps buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}