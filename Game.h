#pragma once

#include "ButtonPlayer.h"
#include "ButtonStrong.h"
#include "ButtonStart.h"
#include "string"
#include "sstream"

class Game{
private:
    sf::Sprite worldBackground;
    sf::Texture worldBackgroundTex;
    sf::RenderWindow* window;
    ButtonPlayer* player;
    ButtonStrong* strong;
    ButtonStart* start;

    bool playerClick = false;

    sf::Font font;
    sf::Text pointText;
    sf::Text strongText;
    sf::Text levelText;

    sf::RectangleShape playerHpBar;
    sf::RectangleShape playerHpBarBack;

    bool startButtonPressed;

    void initWindow();
    void initPlayer();
    void initStrong();
    void initStart();
    void initWorld();
    void initGUI();
    void initSystems();
    void renderDefault();

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
    void newLevel(); //Метод, который изменяет уровень и спрайты персонажа
    //unsigned power;
    unsigned level;
};