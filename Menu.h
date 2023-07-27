//
// Created by Alex on 27.07.2023.
//
#pragma once
#include "string"
#include "sstream"
#include <SFML/Graphics.hpp>

class Menu{

private:
    sf::RenderWindow* window;
    sf::Sprite background;
    sf::Texture backgroundTexture;
    sf::Font font;

    sf::Text headText;
    sf::Text volumeSettingsText;

    void initTexture(); //инициализация текстуры
    void initSprite(); //инициализация спрайта
    void initGUI();
    void renderGUI(sf::RenderTarget &target);

public:
    Menu();
    void render(sf::RenderTarget &target);
    void setPosition(float x, float y);
};
