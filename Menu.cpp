//
// Created by Alex on 27.07.2023.
//
#include "Menu.h"
#include <iostream>

Menu::Menu(){
    initTexture();
    initSprite();
    initGUI();
    initButtonPlus();
    //initVolumeSlider();
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
    buttonPlus->render(target);
//    volumeSlider->render(target);
    renderGUI(target);
}

void Menu::setPosition(float x, float y) {
    background.setPosition(x,y);
}

void Menu::renderGUI(sf::RenderTarget &target) {
    target.draw(headText);
    target.draw(volumeSettingsText);
}

//void Menu::initVolumeSlider() {
//    volumeSlider = new VolumeSlider(700.f, 570.f, 200.f, 20.f, 0.f, 100.f);
//}

Menu::~Menu() {
//    delete volumeSlider;
    delete buttonPlus;
}

void Menu::update(sf::Event event, sf::RenderWindow& window) {
    //volumeSlider->handleEvent(event, window);
    if(buttonPlus->handleClickEvent(event,window)){
        m_volume=10;
    }

}

float Menu::getVolume() {
    return m_volume;
}

void Menu::initButtonPlus() {
   buttonPlus = new ButtonVolume();
   buttonPlus->setPosition(780,600);
}


