#ifndef GLFWCONTEXT_H
#define GLFWCONTEXT_H

#include <iostream>
#include <glad/glad.h>

#define GLFW_DLL
#include "GLFW/glfw3.h"

#include <context.h>

class GLFWContext : public Context
{
    GLFWwindow * m_window = nullptr;

public:

    virtual bool initContext(int width, int height, const char * title);
    virtual void processInput(Player & player);
    virtual bool shouldClose();
    virtual void swapBuffers();

    virtual void update();

    GLFWContext();

    virtual ~GLFWContext();
};

#endif // GLFWCONTEXT_H
