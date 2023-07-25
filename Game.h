#pragma once

#include "ButtonPlayer.h"
#include "ButtonStrong.h"
#include "string"
#include "sstream"

class Game{
private:
    sf::Sprite worldBackground;
    sf::Texture worldBackgroundTex;
    sf::RenderWindow* window;
    ButtonPlayer* player;
    ButtonStrong* strong;

    sf::Font font;
    sf::Text pointText;
    sf::Text strongText;

    sf::RectangleShape playerHpBar;
    sf::RectangleShape playerHpBarBack;

    void initWindow();
    void initPlayer();
    void initStrong();
    void initWorld();
    void initGUI();
    void initSystems();

public:
    unsigned multiplier;
    unsigned points;
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