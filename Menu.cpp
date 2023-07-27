//
// Created by Alex on 27.07.2023.
//
#include "Menu.h"
#include <iostream>

Menu::Menu(){
    initTexture();
    initSprite();
    initGUI();
}

void Menu::initTexture() {
    if(!backgroundTexture.loadFromFile(R"(images\land.png)")){
        std::cout<<"ERROR: NOT FOUND TEXTURE MENU"<<std::endl;
    }
}

void Menu::initSprite() {
    background.setTexture(backgroundTexture);
}

void Menu::initGUI() {
    if (!font.loadFromFile(R"(C:\Windows\Fonts\Arial.ttf)"))
        std::cout << "ERROR::GAME::Failed to load font\n";

    headText.setFont(font);
    headText.setPosition(700, 150);
    headText.setCharacterSize(60);
    headText.setString("SETTINGS");
    headText.setFillColor(sf::Color::Cyan);

    volumeSettingsText.setFont(font);
    volumeSettingsText.setPosition(700, 450);
    volumeSettingsText.setCharacterSize(40);
    volumeSettingsText.setString("VOLUME SETTINGS");
    volumeSettingsText.setFillColor(sf::Color::Magenta);
}

void Menu::render(sf::RenderTarget &target) {
    target.draw(background);
}

void Menu::setPosition(float x, float y) {
    background.setPosition(x,y);
}

void Menu::renderGUI(sf::RenderTarget &target) {
    target.draw(headText);
    target.draw(volumeSettingsText);
}


