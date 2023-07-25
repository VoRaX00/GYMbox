#pragma once

#include "ButtonObject.h"
#include <iostream>

class ButtonStrong : public ButtonObject{
private:
    void initTexture() override;
public:
    ButtonStrong();
    void update() override;
    void render(sf::RenderTarget& target) override;
    void handleClickEvent(sf::Event event, sf::RenderWindow& window) override;
};