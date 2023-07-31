#include "ButtonStart.h"

void ButtonStart::initTexture() {
    if (!mainTex.loadFromFile("images\\logo.png")) {
        std::cout << "ERROR: Could not load main texture" << std::endl;
    }
}

ButtonStart::ButtonStart(){
    initTexture();
    initSprite();
}

ButtonStart::~ButtonStart() = default;

void ButtonStart::update() {

}

void ButtonStart::render(sf::RenderWindow &target) {
    target.draw(sprite);
}

bool ButtonStart::handleClickEvent(sf::Event event, sf::RenderWindow& window) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

            if (sprite.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) {
                std::cout << "ButtonStart clicked!" << std::endl;
                return true;
            }
        }
    }
    return false;
}
