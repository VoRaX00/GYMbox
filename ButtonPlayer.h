#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class ButtonPlayer{
private:
    sf::Sprite sprite;
    sf::Texture mainTex;
    sf::Texture pressedTex;
    void initSprite();
    void initTexture();
public:
    ButtonPlayer();
    ~ButtonPlayer();
    void update();
    void render(sf::RenderTarget& target);
    void handleClickEvent(sf::Event event, const sf::RenderWindow& window);
    void setPosition(float x, float y);
    void setPosition(const sf::Vector2f& position);
};