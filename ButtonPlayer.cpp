#include "ButtonPlayer.h"
#include "SFML/Audio.hpp"
ButtonPlayer::ButtonPlayer()
{
    initTexture();
    initSprite();
    points = 0;
    power = 1;
    hpMax = 100;
    hp = hpMax;
}

ButtonPlayer::~ButtonPlayer() = default;

void ButtonPlayer::initTexture() {
    if (!mainTex.loadFromFile("images\\G11.png")) {
        std::cout << "ERROR: Could not load main texture" << std::endl;
    }

    if (!pressedTex.loadFromFile(R"(images\G21.png)")) {
        std::cout << "ERROR: Could not load pressed texture" << std::endl;
    }
}

void ButtonPlayer::update() {}

void ButtonPlayer::render(sf::RenderWindow &target) {
    target.draw(sprite);
}

bool ButtonPlayer::handleClickEvent(sf::Event event, sf::RenderWindow& window) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

            if (sprite.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) {
                std::cout << "Button clicked!" << std::endl;
                points+=power;
                return true;
            }
        }
    }
    return false;
}

const int& ButtonPlayer::getHp() const
{
    return hp;
}

const int& ButtonPlayer::getHpMax() const
{
    return hpMax;
}

void ButtonPlayer::resetTexturePressed() {
    sprite.setTexture(pressedTex);
}

void ButtonPlayer::resetTextureReleased() {
    sprite.setTexture(mainTex);
}

void ButtonPlayer::setMainTexture(const std::string& path) {
    sf::Texture tmp;
    if (!tmp.loadFromFile(path)) {
        std::cout << "ERROR: Could not load main texture" << std::endl;
    }
    mainTex = tmp;
}

void ButtonPlayer::setPressedTexture(const std::string& path) {
    sf::Texture tmp;
    if (!tmp.loadFromFile(path)) {
        std::cout << "ERROR: Could not load pressed texture" << std::endl;
    }
    pressedTex = tmp;
}
