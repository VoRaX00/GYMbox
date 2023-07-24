#include "ButtonPlayer.h"

ButtonPlayer::ButtonPlayer()
{
    this->initTexture();
    this->initSprite();
}

ButtonPlayer::~ButtonPlayer() {

}

void ButtonPlayer::initSprite() {
    this->sprite.setTexture(this->mainTex );
}

void ButtonPlayer::initTexture() {
    if (!this->mainTex.loadFromFile(R"(C:\Users\glebm\CLionProjects\GYMbox\images\GG1.png)")) {
        std::cout << "ERROR: Could not load main texture" << std::endl;
    }
}

void ButtonPlayer::update() {

}

void ButtonPlayer::render(sf::RenderTarget &target) {
    target.draw(this->sprite);
}

void ButtonPlayer::handleClickEvent(sf::Event event, const sf::RenderWindow& window) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

            if (this->sprite.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) {
                std::cout << "Button clicked!" << std::endl;
            }
        }
    }
}

void ButtonPlayer::setPosition(float x, float y) {
    this->sprite.setPosition(x, y);
}

void ButtonPlayer::setPosition(const sf::Vector2f& position) {
    this->sprite.setPosition(position);
}
