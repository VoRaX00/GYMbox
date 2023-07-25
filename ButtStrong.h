#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class ButtStrong{
private:
    sf::Sprite sprite;
    sf::Texture mainTex;
    void initSprite();
    void initTexture();
public:
    ButtStrong();
    ~ButtStrong();
    void update();
    void render(sf::RenderTarget& target);
    bool handleClickEvent(sf::Event event, const sf::RenderWindow& window);
    void setPosition(float x, float y);
    void setPosition(const sf::Vector2f& position);
    unsigned price;
};