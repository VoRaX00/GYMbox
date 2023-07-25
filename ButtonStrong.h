#pragma once

#include <iostream>
#include "ButtonObject.h"

class ButtonStrong : public ButtonObject{
private:
    void initTexture() override;
public:
    ButtonStrong();
    ~ButtonStrong();
    void update() override;
    void render(sf::RenderTarget& target) override;
    bool handleClickEvent(sf::Event event, sf::RenderWindow& window) override;
    unsigned price;
};