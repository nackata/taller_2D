#include "../include/player.h"

glm::vec3 Player::camPos() const
{
    return m_camPos;
}

void Player::setCamPos(const glm::vec3 &camPos)
{
    m_camPos = camPos;
}

float Player::getCamVelocity() const
{
    return camVelocity;
}

void Player::setCamVelocity(float value)
{
    camVelocity = value;
}

Player::Player()
{

}
