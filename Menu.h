//
// Created by Alex on 27.07.2023.
//
#pragma once
#include "string"
#include "sstream"
#include "ButtonVolume.h"

class Menu{
private:
    sf::Sprite background;
    sf::Texture backgroundTexture;
    sf::Font font;

    sf::Text headText;
    sf::Text volumeSettingsText;
    sf::Text percentVolume;

//    VolumeSlider* volumeSlider;
    ButtonVolume* buttonPlus;
    ButtonVolume* buttonDegree;

    int m_volume=0;

    void initTexture(); //инициализация текстуры
    void initSprite(); //инициализация спрайта
    void initGUI();
    void renderGUI(sf::RenderTarget &target);
//    void initVolumeSlider();
    void initButtonVolume();

public:
    bool click = false;
    Menu();
    ~Menu();
    void render(sf::RenderWindow &target);
    void setPosition(float x, float y);
    void update(sf::Event event, sf::RenderWindow& window);
    int getVolume() const;
};
