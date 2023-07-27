#include "ButtonMenu.h"
#include <iostream>

ButtonMenu::ButtonMenu() {
    initTexture();
    initSprite();
}

void ButtonMenu::update() {}

void ButtonMenu::render(sf::RenderTarget &target) {
    target.draw(sprite);
}

bool ButtonMenu::handleClickEvent(sf::Event event, sf::RenderWindow &window) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

            if (sprite.getGlobalBounds().contains(static_cast<float>(mousePosition.x),
                                                        static_cast<float>(mousePosition.y))) {
                std::cout<<"ButtonMenu clicked"<<std::endl;
                return true;
            }
        }
    }

    return false;
}

void ButtonMenu::initTexture() {
    if (!mainTex.loadFromFile(R"(images\menu.png)")) {
        std::cout << "ERROR: Could not load button menu texture" << std::endl;
    }
}

