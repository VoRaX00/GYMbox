//
// Created by Alex on 27.07.2023.
//

#include "Menu.h"
#include <iostream>

Menu::Menu() {
    initTexture();
    initSprite();
}

void Menu::update() {

}

void Menu::render(sf::RenderTarget &target) {
    target.draw(sprite);
}

bool Menu::handleClickEvent(sf::Event event, sf::RenderWindow &window) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

            if (this->sprite.getGlobalBounds().contains(static_cast<float>(mousePosition.x),
                                                        static_cast<float>(mousePosition.y))) {
                std::cout<<"Menu clicked"<<std::endl;
                return true;
            }
        }
    }

    return false;
}

void Menu::initTexture() {
    if (!mainTex.loadFromFile(R"(images\menu.png)")) {
        std::cout << "ERROR: Could not load menu texture" << std::endl;
    }
}

