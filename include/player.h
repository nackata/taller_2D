#ifndef PLAYER_H
#define PLAYER_H

#include <glm/glm.hpp>

class Player
{
    glm::vec3 m_camPos = {0.f, 0.f, 1.f};
    float camVelocity = 1.f;

public:
    Player();


    glm::vec3 camPos() const;
    void setCamPos(const glm::vec3 &camPos);
    float getCamVelocity() const;
    void setCamVelocity(float value);
};

#endif // PLAYER_H
