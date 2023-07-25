#include "ButtStrong.h"

ButtStrong::ButtStrong() {
    this->initTexture();
    this->initSprite();
    price = 50;
}

ButtStrong::~ButtStrong() {

}

void ButtStrong::initSprite() {
    this->sprite.setTexture(this->mainTex);
}

void ButtStrong::initTexture() {
    if (!this->mainTex.loadFromFile(R"(images\button.png)")) {
        std::cout << "ERROR: Could not load main texture" << std::endl;
    }
}

void ButtStrong::update() {

}

void ButtStrong::render(sf::RenderTarget &target) {
    target.draw(this->sprite);
}

bool ButtStrong::handleClickEvent(sf::Event event, const sf::RenderWindow& window) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

            if (this->sprite.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) {
                std::cout << "ButtonStrong clicked!" << std::endl;
                return true;
            }
        }
    }
}

void ButtStrong::setPosition(float x, float y) {
    this->sprite.setPosition(x, y);
}

void ButtStrong::setPosition(const sf::Vector2f& position) {
    this->sprite.setPosition(position);
}