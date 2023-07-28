#pragma once

#include "ButtonPlayer.h"
#include "ButtonStrong.h"
#include "ButtonStart.h"
#include "ButtonMenu.h"
#include "Menu.h"
#include "string"
#include "sstream"
#include <SFML/Audio.hpp>

class Game{
private:
    const short WINDOW_WIDTH = 1800;
    const short WINDOW_HEIGHT = 990;

    sf::Sprite worldBackground;
    sf::Texture worldBackgroundTex;
    sf::Texture endWorldBackgroundTex;
    sf::RenderWindow* window;
    ButtonPlayer* player;
    ButtonStrong* strong;
    ButtonStart* start;
    ButtonMenu* buttonMenu;
    Menu* menu;

    sf::Music backgroundMusic;
    sf::SoundBuffer buffer;
    sf::Sound sound;


    bool playerClick = false;

    sf::Font font;
    sf::Text pointText;
    sf::Text strongText;
    sf::Text levelText;

    sf::RectangleShape playerHpBar;
    sf::RectangleShape playerHpBarBack;

    bool startButtonPressed;
    bool menuClicked = false;

    void initWindow();
    void initPlayer();
    void initStrong();
    void initStart();
    void initWorld();
    void initGUI();
    void initSystems();
    void renderDefault();
    void initButtonMenu();
    void initMenu();

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
    void newLevel(); // Метод, который изменяет уровень и спрайты персонажа
    //unsigned power;
    unsigned level;
};