//
// Created by nikit on 14.06.2023.
//
#include "Button.h"
#include <memory>
#include <iostream>

#pragma once
#define GYMBOX_GYMBOX_H


void fun(); //Тестовая функция, значения не имеет, будет удалена после какого-то времени
void updateWalkImage(sf::Texture& texture, sf::Sprite& sprite, int& numImage, int& time, sf::RenderWindow& window); //Обновляет изображение при ходьбе
bool loadImage(sf::Texture &texture, std::string path);
void game(); //Эта функция игры, т.е. она как бы является главной, в которой как бы и происходит игра