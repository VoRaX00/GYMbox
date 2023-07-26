#include "ButtonObject.h"

void ButtonObject::initSprite() {
    this->sprite.setTexture(mainTex);
}

ButtonObject::ButtonObject() = default;

void ButtonObject::setPosition(float x, float y) {
    sprite.setPosition(x,y);
}

void ButtonObject::setPosition(const sf::Vector2f &position) {
    sprite.setPosition(position);
}
