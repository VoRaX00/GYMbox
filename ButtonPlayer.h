#pragma once

#include <iostream>
#include "ButtonObject.h"

class ButtonPlayer : public ButtonObject{
private:
    sf::Texture pressedTex;
    void initTexture() override;
    sf::Texture newTex;
    sf::Clock clock;
    int hp;
    int hpMax;
    
public:
    ButtonPlayer();
    ~ButtonPlayer();
    unsigned points;
    unsigned power;
    void update() override;
    void render(sf::RenderTarget& target) override;
    bool handleClickEvent(sf::Event event, sf::RenderWindow& window) override;

    void setMainTexture(const std::string& path);
    void setPressedTexture(const std::string& path);

    void resetTexturePressed();
    void resetTextureReleased();

    const int& getHp() const;
    const int& getHpMax() const;
};