#include "../include/glfwcontext.h"

bool GLFWContext::initContext(int width, int height, const char *title)
{
    if (m_window) return false;

    if(!glfwInit()) return false;
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);


    m_window = glfwCreateWindow(width, height, title, nullptr, nullptr);

    if (m_window == nullptr)
    {
        std::cerr << "error creating window" << std::endl;
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(m_window);

    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
    {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return false;
    }

    glfwSetInputMode(m_window, GLFW_STICKY_KEYS, 1);

    glViewport(0, 0, width, height);

    return true;
}

void GLFWContext::processInput(Player &player)
{
    glm::vec3 camPos = player.camPos();

    if (glfwGetKey(m_window, GLFW_KEY_S) == GLFW_PRESS)
        camPos += glm::vec3(0.f, 0.001f, 0.f) * player.getCamVelocity();

    if (glfwGetKey(m_window, GLFW_KEY_W) == GLFW_PRESS)
        camPos += glm::vec3(0.f, -0.001f, 0.f) * player.getCamVelocity();

    if (glfwGetKey(m_window, GLFW_KEY_D) == GLFW_PRESS)
        camPos += glm::vec3(-0.001f, 0.f, 0.f) * player.getCamVelocity();

    if (glfwGetKey(m_window, GLFW_KEY_A) == GLFW_PRESS)
        camPos += glm::vec3(0.001f, 0.f, 0.f) * player.getCamVelocity();

    if (glfwGetKey(m_window, GLFW_KEY_EQUAL) == GLFW_PRESS)
        camPos += glm::vec3(0.0f, 0.f, -0.001);

    if (glfwGetKey(m_window, GLFW_KEY_MINUS) == GLFW_PRESS)
        camPos += glm::vec3(0.0f, 0.f, 0.001);

    player.setCamPos(camPos);
}

bool GLFWContext::shouldClose()
{
    if (glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        return true;

    return false;
}

void GLFWContext::swapBuffers()
{
    glfwSwapBuffers(m_window);
}

void GLFWContext::update()
{
    glfwPollEvents();
    swapBuffers();
}

GLFWContext::GLFWContext()
{

}

GLFWContext::~GLFWContext()
{
    glfwTerminate();
}
