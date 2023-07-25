#pragma once

#include <iostream>
#include "ButtonObject.h"

class ButtonStrong : ButtonObject{
private:
    void initTexture() override;
public:
    ButtonStrong();
    ~ButtonStrong();
    void update() override;
    void render(sf::RenderTarget& target) override;
    bool handleClickEvent(sf::Event event, const sf::RenderWindow& window);
    unsigned price;
};