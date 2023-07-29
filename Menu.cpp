#include "Menu.h"
#include <iostream>

Menu::Menu(){
    initTexture();
    initSprite();
    initGUI();
    initButtonVolume();
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
    volumeSettingsText.setPosition(650, 250);
    volumeSettingsText.setCharacterSize(40);
    volumeSettingsText.setString("VOLUME SETTINGS");
    volumeSettingsText.setFillColor(sf::Color::Cyan);
}

void Menu::render(sf::RenderTarget &target) {
    target.draw(background);
    buttonPlus->render(target);
    buttonDegree->render(target);
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
    delete buttonDegree;
}

void Menu::update(sf::Event event, sf::RenderWindow& window) {
    //volumeSlider->handleEvent(event, window);
    if(buttonPlus->handleClickEvent(event,window)){
        m_volume=10;
        click = true;
        return;
    }
    else if(buttonDegree->handleClickEvent(event,window)){
        m_volume=-10;
        click = true;
        return;
    }
    click = false;
}

float Menu::getVolume() const{
    return m_volume;
}

void Menu::initButtonVolume() {
    buttonPlus = new ButtonVolume("plus");
    buttonPlus->setPosition(1000,325);
    buttonDegree = new ButtonVolume("degree");
    buttonDegree->setPosition(600, 325);
}

void Menu::setVolume(const float& value) {
    m_volume = value;
}


