#include "ButtonStrong.h"

ButtonStrong::ButtonStrong() {
    this->initTexture();
    this->initSprite();
}

void ButtonStrong::initTexture() {
    if (!this->mainTex.loadFromFile(R"(images\button.png)")) {
        std::cout << "ERROR: Could not load main texture" << std::endl;
    }
}

void ButtonStrong::update(){}

void ButtonStrong::render(sf::RenderTarget &target) {
    target.draw(this->sprite);
}

void ButtonStrong::handleClickEvent(sf::Event event, sf::RenderWindow& window) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

            if (this->sprite.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) {
                std::cout << "ButtonStrong clicked!" << std::endl;
            }
        }
    }
}