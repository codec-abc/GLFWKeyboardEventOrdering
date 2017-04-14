#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "linmath.h"

#include <stdlib.h>
#include <stdio.h>


static void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (action == GLFW_PRESS)
    {
        printf("keydown event\n");
        printf
        (
            "key scancode is %d, key virtual key code is %d \n", 
            scancode,
            key
        );
    }
    else if(action == GLFW_RELEASE)
    {
        printf("keyup event\n");
        printf
        (
            "key scancode is %d, key virtual key code is %d \n", 
            scancode,
            key
        );
    }

    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

static void character_callback(GLFWwindow* window, unsigned int codepoint)
{
    printf("text input event\n");
    printf("character is %c\n", codepoint);
}

int main(void)
{
    GLFWwindow* window;
    GLuint vertex_buffer, vertex_shader, fragment_shader, program;
    GLint mvp_location, vpos_location, vcol_location;

    glfwSetErrorCallback(error_callback);

    if (!glfwInit())
    {
        exit(EXIT_FAILURE);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwSetKeyCallback(window, key_callback);
    glfwSetCharCallback(window, character_callback);

    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
    glfwSwapInterval(1);

    while (!glfwWindowShouldClose(window))
    {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);

    glfwTerminate();
    exit(EXIT_SUCCESS);
}
