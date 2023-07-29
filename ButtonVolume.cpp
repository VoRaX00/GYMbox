//
// Created by Alex on 29.07.2023.
//

#include "ButtonVolume.h"
#include <iostream>

ButtonVolume::ButtonVolume() {
    initTexture();
    initSprite();
}

void ButtonVolume::update() {}

void ButtonVolume::render(sf::RenderTarget &target) {
    target.draw(sprite);
}

bool ButtonVolume::handleClickEvent(sf::Event event, sf::RenderWindow &window) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

            if (sprite.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) {
                std::cout << "ButtonVolumePlus clicked!" << std::endl;
                return true;
            }
        }
    }
    return false;
}

void ButtonVolume::initTexture() {
    if(typeButton == "plus") {
        if (!mainTex.loadFromFile(R"(images\plus.png)"))
            std::cout << "Error, not found image plus\n";
    }
    else{
        if (!mainTex.loadFromFile(R"(images\degree.png)"))
            std::cout << "Error, not found image plus\n";
    }
}

ButtonVolume::ButtonVolume(const std::string &str) {
    typeButton = str;
    initTexture();
    initSprite();
}
