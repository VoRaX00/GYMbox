#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class ButtonStrong{
private:
    sf::Sprite sprite;
    sf::Texture mainTex;
    void initSprite();
    void initTexture();
public:
    ButtonStrong();
    ~ButtonStrong();
    void update();
    void render(sf::RenderTarget& target);
    void handleClickEvent(sf::Event event, const sf::RenderWindow& window);
    void setPosition(float x, float y);
    void setPosition(const sf::Vector2f& position);
};