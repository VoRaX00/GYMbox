#pragma once

#include "ButtonPlayer.h"

class Game{
private:
    sf::Sprite worldBackground;
    sf::Texture worldBackgroundTex;
    sf::RenderWindow* window;
    ButtonPlayer* player;

    void initWindow();
    void initPlayer();
    void initWorld();
public:
    Game();
    ~Game();
    void run();
    void update();
    void render();
    void renderWorld();
};