//
// Created by Alex on 27.07.2023.
//
#pragma once
#include "ButtonObject.h"

class Menu : public ButtonObject{
private:
    void initTexture() override;
public:
    Menu();
    void update() override;
    void render(sf::RenderTarget& target) override;
    bool handleClickEvent(sf::Event event, sf::RenderWindow& window) override;
};
