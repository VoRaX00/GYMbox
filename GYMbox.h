#pragma once
#include "ButtonPlayer.h"
#include "Button.h"
#include <memory>
#include <iostream>

class GYMbox{
private:
    sf::VideoMode videoMode;
    sf::RenderWindow* window;
    ButtonPlayer* buttonPlayer;
    sf::Event event;
    void initVar();
    void initWorld();
    void initPlayer();
public:
    GYMbox();
    virtual ~GYMbox();

    void pollEvents();
    void update();
    void render();
    const bool running() const;
};

void fun(); //Тестовая функция, значения не имеет, будет удалена после какого-то времени
void updateWalkImage(sf::Texture& texture, sf::Sprite& sprite, int& numImage, int& time, sf::RenderWindow& window); //Обновляет изображение при ходьбе
bool loadImage(sf::Texture &texture, std::string path);
void game(); //Эта функция игры, т.е. она как бы является главной, в которой как бы и происходит игра