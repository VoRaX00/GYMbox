#pragma once

#include "ButtonObject.h"
#include <iostream>

class ButtonStrong : public ButtonObject{
private:
    sf::Sprite sprite;
    sf::Texture mainTex;
    void initTexture() override;
public:
    ButtonStrong();
    ~ButtonStrong();
    void update() override;
    void render(sf::RenderTarget& target) override;
    void handleClickEvent(sf::Event event, sf::RenderWindow& window) override;
    void setPosition(float x, float y) override;
    void setPosition(const sf::Vector2f& position) override;
};