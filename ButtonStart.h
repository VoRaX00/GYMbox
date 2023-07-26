#pragma once

#include <iostream>
#include "ButtonObject.h"

class ButtonStart: public ButtonObject{
private:
    void initTexture() override;
public:
    ButtonStart();
    ~ButtonStart();
    void update() override;
    void render(sf::RenderTarget& target) override;
    bool handleClickEvent(sf::Event event, sf::RenderWindow& window) override;
};