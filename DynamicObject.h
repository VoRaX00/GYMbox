//
// Created by nikit on 15.06.2023.
//
#include "GYMbox.h"
#ifndef GYMBOX_DYNAMICOBJECT_H
#define GYMBOX_DYNAMICOBJECT_H


class DynamicObject {
protected:
    sf::Sprite m_sprite;
    sf::Texture m_texture;
    float m_x, m_y, m_speed, m_dx, m_dy;
    bool m_onGround;

    enum State{
        left,
        right,
        jump,
        down
    };

    State state;
public:
    std::pair<float,float> getPlayerCoordinate();
    virtual void control() = 0;
    virtual void update(float time) = 0;
};


#endif //GYMBOX_DYNAMICOBJECT_H
