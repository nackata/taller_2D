#ifndef RENDERSYSTEM_H
#define RENDERSYSTEM_H

#include "context.h"
#include "componentmanager.h"
#include "spritecomponent.h"
#include "texture.h"
#include "shader.h"
#include "glm/glm.hpp"

//////////////////////////////
/// \brief The RenderSystem class
/// Draw all entities with renderable component
/// Renderable - sprite transform

class RenderSystem
{   
private:

    Shader m_spriteShader;
    unsigned int VAO;

public:

    TextureManager m_textureManager;

    glm::vec3 camera = { 0.f, 0.f, 1.f };

    RenderSystem(const Context * context, Shader & spriteShader);

    void drawSprites(const ComponentManager & components);

    void clear() const;

};

#endif // RENDERSYSTEM_H
