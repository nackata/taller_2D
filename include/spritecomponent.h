#ifndef SPRITECOMPONENT_H
#define SPRITECOMPONENT_H

#include "component.h"
#include "lib/glm/glm.hpp"
#include "texture.h"

class SpriteComponent : public Component<SpriteComponent>
{
    glm::vec2 position = { 0.f, 0.f };

    // scale relative to renderer standart sprite size
    glm::vec2 scale = {1.f, 1.f};

    float rotation = 0.f;

    bool isActive = true;

    TextureManager::Texture texture;

public:
    SpriteComponent(TextureManager::Texture tex);
    SpriteComponent(TextureManager::Texture tex, size_t id);

    glm::vec2 getPosition() const;
    void setPosition(const glm::vec2 &value);

    glm::vec2 getScale() const;
    void setScale(const glm::vec2 &value);

    float getRotation() const;
    void setRotation(float value);

    bool getIsActive() const;
    void setIsActive(bool value);

    TextureManager::Texture getTexture() const;
    void setTexture(const TextureManager::Texture &value);
};

#endif // SPRITECOMPONENT_H
