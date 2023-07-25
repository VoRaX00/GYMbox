#include "ButtonPlayer.h"

ButtonPlayer::ButtonPlayer()
{
    this->initTexture();
    this->initSprite();
    points = 0;
    this->hpMax = 100;
    this->hp = this->hpMax;
}

ButtonPlayer::~ButtonPlayer() = default;

void ButtonPlayer::initTexture() {
    if (!this->mainTex.loadFromFile(R"(images\G1.png)")) {
        std::cout << "ERROR: Could not load main texture" << std::endl;
    }

    if (!this->pressedTex.loadFromFile(R"(images\G2.png)")) {
        std::cout << "ERROR: Could not load main texture" << std::endl;
    }
}

void ButtonPlayer::update() {

}

void ButtonPlayer::render(sf::RenderTarget &target) {
    target.draw(this->sprite);
}

void ButtonPlayer::handleClickEvent(sf::Event event, sf::RenderWindow& window) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

            if (this->sprite.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) {
                std::cout << "Button clicked!" << std::endl;
                points++;

                //Разгибание и сгибание руки
                sprite.setTexture(pressedTex);
                window.draw(sprite);
                window.display();
                sf::sleep(sf::seconds(1));
                sprite.setTexture(mainTex);
            }
        }
    }
}

const int & ButtonPlayer::getHp() const
{
    return this->hp;
}

const int & ButtonPlayer::getHpMax() const
{
    return this->hpMax;
}
