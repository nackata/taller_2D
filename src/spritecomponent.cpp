#include "../include/spritecomponent.h"

SpriteComponent::SpriteComponent(TextureManager::Texture tex) : Component<SpriteComponent>(0),  texture(tex)
{

}

SpriteComponent::SpriteComponent(TextureManager::Texture tex, size_t id) : Component<SpriteComponent>(id), texture(tex)
{

}

glm::vec2 SpriteComponent::getPosition() const
{
    return position;
}

void SpriteComponent::setPosition(const glm::vec2 &value)
{
    position = value;
}

glm::vec2 SpriteComponent::getScale() const
{
    return scale;
}

void SpriteComponent::setScale(const glm::vec2 &value)
{
    scale = value;
}

float SpriteComponent::getRotation() const
{
    return rotation;
}

void SpriteComponent::setRotation(float value)
{
    rotation = value;
}

bool SpriteComponent::getIsActive() const
{
    return isActive;
}

void SpriteComponent::setIsActive(bool value)
{
    isActive = value;
}

TextureManager::Texture SpriteComponent::getTexture() const
{
    return texture;
}

void SpriteComponent::setTexture(const TextureManager::Texture &value)
{
    texture = value;
}
