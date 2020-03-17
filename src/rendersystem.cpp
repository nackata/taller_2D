#include "rendersystem.h"

RenderSystem::RenderSystem(const Context * context, Shader & spriteShader) : m_spriteShader(spriteShader)
{
    const glm::mat4 projection = glm::ortho(-1.f * context->screenRatio(), 1.f * context->screenRatio(), -1.f, 1.f, -1.f, 1.f);
    m_spriteShader.use();
    m_spriteShader.setMat4("projection", projection);

    // init sprite data
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
}

void RenderSystem::drawSprites(const ComponentManager &components)
{
    m_spriteShader.use();
    m_spriteShader.setVec3("camPos", camera);
    glBindVertexArray(VAO);

    for (const auto & sprite : components.range<SpriteComponent>())
    {
        m_textureManager.bindTexture(sprite.getTexture());
        m_spriteShader.setVec2("tilePos", sprite.getPosition());
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
    }
}

void RenderSystem::clear() const
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}
