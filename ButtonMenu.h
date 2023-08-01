#pragma once
#include "ButtonObject.h"

class ButtonMenu : public ButtonObject{
private:
    void initTexture() override;
public:
    ButtonMenu();
    void update() override;
    void render(sf::RenderTarget& target) override;
    bool handleClickEvent(sf::Event event, sf::RenderWindow& window) override;
};
