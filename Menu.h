//
// Created by Alex on 27.07.2023.
//
#pragma once
#include "string"
#include "sstream"
#include "VolumeSlider.h"
#include "ButtonVolume.h"

class Menu{
private:
    sf::Sprite background;
    sf::Texture backgroundTexture;
    sf::Font font;

    sf::Text headText;
    sf::Text volumeSettingsText;

//    VolumeSlider* volumeSlider;
    ButtonVolume* buttonPlus;
    ButtonVolume* buttonDegree;

    float m_volume=0;


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
    void render(sf::RenderTarget &target);
    void setPosition(float x, float y);
    void update(sf::Event event, sf::RenderWindow& window);
    float getVolume() const;
    void setVolume(const float& value);
};
