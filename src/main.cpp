#define GLFW_INCLUDE_NONE
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "vendors/GLFW/glfw3.h"

void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

int main(){
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
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
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}