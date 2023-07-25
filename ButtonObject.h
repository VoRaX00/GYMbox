//
// Created by Alex on 25.07.2023.
//
#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class ButtonObject {
protected:
    sf::Sprite sprite;
    sf::Texture mainTex;
    void initSprite();
    virtual void initTexture() = 0;

public:
    ButtonObject();
    virtual void update() = 0;
    virtual void render(sf::RenderTarget& target) = 0;
    virtual bool handleClickEvent(sf::Event event, sf::RenderWindow& window) = 0;
    void setPosition(float x, float y);
    void setPosition(const sf::Vector2f& position);
};
