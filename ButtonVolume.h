//
// Created by Alex on 29.07.2023.
//
#pragma once

#include "ButtonObject.h"
class ButtonVolume : public ButtonObject {
private:
    void initTexture() override;
public:
    ButtonVolume();
    void update() override;
    void render(sf::RenderTarget& target) override;
    bool handleClickEvent(sf::Event event, sf::RenderWindow& window) override;
};