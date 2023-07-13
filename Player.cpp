//
// Created by nikit on 15.06.2023.
//

#include "Player.h"

Player::Player(sf::Texture &texture, float _x, float _y){
    m_sprite.setTexture(texture);
    m_x = _x;
    m_y = _y;
    m_sprite.setPosition(_x, _y);
    m_onGround = true;
}

void Player::control() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        state = left;
        m_speed = 0.1f;

    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        state = right;
        m_speed = 0.1f;

    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && m_onGround) {
        state = down;
        m_speed = 0.1f;

    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && m_onGround) {//Написать прыжок
        state = jump;
        m_onGround = false;
    }
}

void Player::update(float time) {
    switch (state) {
        case DynamicObject::left:
            m_dx = m_speed;
            break;
        case DynamicObject::right:
            m_dx = -m_speed;
        case DynamicObject::jump:
            break;
        case DynamicObject::down:
            break;
    }
    m_x = m_dx * time;
    m_y = m_dy * time;

}

