#include <iostream>
#include <glad/glad.h>

#define GLFW_DLL
#include "GLFW/glfw3.h"
#include <glm/glm.hpp>

#define STB_IMAGE_IMPLEMENTATION
#include "lib/stb_image/stb_image.h"

#include "shader.h"
#include "context.h"
#include "glfwcontext.h"
#include "player.h"

const int width = 800;
const int height = 600;
const float screenRatio = static_cast<float>(width) / height;
const std::string title = { "Taller_2d 0.0.1 " };

const glm::mat4 projection = glm::ortho(-1.f * screenRatio, 1.f * screenRatio, -1.f, 1.f, -1.f, 1.f);


//void processInput(GLFWwindow *window)
//{
//    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//        glfwSetWindowShouldClose(window, true);

//    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
//        camPos += glm::vec3(0.f, 0.001f, 0.f) * camVelocity;

//    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
//        camPos += glm::vec3(0.f, -0.001f, 0.f) * camVelocity;

//    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
//        camPos += glm::vec3(-0.001f, 0.f, 0.f) * camVelocity;

//    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
//        camPos += glm::vec3(0.001f, 0.f, 0.f) * camVelocity;

//    if (glfwGetKey(window, GLFW_KEY_EQUAL) == GLFW_PRESS)
//        camPos += glm::vec3(0.0f, 0.f, -0.001);

//    if (glfwGetKey(window, GLFW_KEY_MINUS) == GLFW_PRESS)
//        camPos += glm::vec3(0.0f, 0.f, 0.001);

//}


int main()
{
//    if(!glfwInit()) return 1;
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);


//    GLFWwindow * window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

//    if (window == nullptr)
//    {
//        std::cerr << "error creating window" << std::endl;
//        glfwTerminate();
//        return 1;
//    }

//    glfwMakeContextCurrent(window);

//    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
//    {
//        std::cout << "Failed to initialize GLAD" << std::endl;
//        return 1;
//    }

//    glfwSetInputMode(window, GLFW_STICKY_KEYS, 1);

//    glViewport(0, 0, width, height);

    Context * context = new GLFWContext();
    context->initContext(width, height, title.c_str());

    Player player;

    ////////////////////////
    //  vertex data
    //
    //

    float vertexData[] = {
        -0.5f, -0.5f, 0.f, 0.f,
        -0.5f,  0.5f, 0.f, 1.f,
         0.5f, -0.5f, 1.f, 0.f,
         0.5f,  0.5f, 1.f, 1.f
    };


    int indexes[] = {
        0, 1, 2,
        1, 2, 3
    };


    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    unsigned int VBO, EBO;
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, static_cast<GLsizeiptr>(sizeof(vertexData) * sizeof(float)), vertexData, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, static_cast<GLsizeiptr>(sizeof(vertexData) * sizeof(float)), indexes, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), static_cast<void*>(nullptr));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), reinterpret_cast<void*>(2 * sizeof(float)));



    auto mainShader = Shader("common/shaders/vertex_shader.glsl", "common/shaders/fragment_shader.glsl");

    mainShader.use();

    unsigned int texture1;

    glGenTextures(1, &texture1);
    glBindTexture(GL_TEXTURE_2D, texture1);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true);
    unsigned char *data = stbi_load("common/texture/grass_floor.jpg", &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);

    mainShader.setInt("tex", 0);

    mainShader.setMat4("projection", projection);

    while(!context->shouldClose())
    {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture1);

//        int rad = 3;
//        for (int i = -rad - 1; i < rad + 1; ++i)
//        {
//            for (int j = -rad; j < rad ; ++j)
//            {
        mainShader.setVec2("tilePos", glm::vec2(0.f, 0.f));
        glDrawElements(GL_TRIANGLES, static_cast<int>(sizeof(indexes)), GL_UNSIGNED_INT, nullptr);
//            }
//        }


        context->update();

        mainShader.setVec3("camPos", player.camPos());
        context->processInput(player);
    }

    glfwTerminate();

    return 0;
}
