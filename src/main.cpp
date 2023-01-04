#define GL_SILENCE_DEPRECATION // Important to define before OpenGL headers.
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "vendors/GLFW/glfw3.h"

void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

int main(){
    // glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    // glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    // glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    if (!glfwInit()){
        // Initialization failed
        return -1;
    }
    GLFWwindow* window = glfwCreateWindow(640, 480, "My Title", NULL, NULL);
    if (!window){
        // Window or OpenGL context creation failed
        glfwTerminate();
        return -1;
    }   
    glfwMakeContextCurrent(window);
    while (!glfwWindowShouldClose(window)){
        // Keep running
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);

        glViewport(0, 0, width, height);
        
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}