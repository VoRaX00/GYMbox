#pragma once

#include "ButtonPlayer.h"
#include "ButtStrong.h"
#include "string"
#include "sstream"

class Game{
private:
    sf::Sprite worldBackground;
    sf::Texture worldBackgroundTex;
    sf::RenderWindow* window;
    ButtonPlayer* player;
    ButtStrong* strong;

    sf::Font font;
    sf::Text pointText;
    unsigned points;

    unsigned multiplier;
    sf::RectangleShape playerHpBar;
    sf::RectangleShape playerHpBarBack;

    void initWindow();
    void initPlayer();
    void initStrong();
    void initWorld();
    void initGUI();
    void initSystems();

public:
    Game();
    ~Game();
    void run();
    void update();
    void updateGUI();
    void render();
    void renderGUI();
    void renderWorld();
    unsigned power;
};