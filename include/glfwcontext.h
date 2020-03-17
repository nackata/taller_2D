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
    int m_width;
    int m_height;

public:

    virtual bool initContext(int width, int height, const char * title) override;
    virtual void processInput(Player & player) override;
    virtual bool shouldClose() override;
    virtual void swapBuffers() override;

    virtual void update() override;

    GLFWContext();

    virtual ~GLFWContext() override;

    virtual int width() const override { return m_width; }
    virtual int height() const override { return m_height; }
    virtual float screenRatio() const override { return static_cast<float>(m_width) / m_height; }
};

#endif // GLFWCONTEXT_H
