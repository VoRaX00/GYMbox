//
// Created by nikit on 28.07.2023.
//
#include "ButtonObject.h"
#include "SFML/Audio.hpp"

class VolumeSlider :  ButtonObject{
private:
    sf::RectangleShape m_slider;
    float m_value;
    float m_minValue;
    float m_maxValue;
    bool m_dragging = false;

    void initTexture() override;

public:
    VolumeSlider();
    VolumeSlider(float x, float y, float width, float height, float minValue = 0.f, float maxValue = 100.f);
    void update() override;
    void render(sf::RenderTarget& target) override;
    void handleEvent(sf::Event event, sf::RenderWindow& window);
    bool handleClickEvent(sf::Event event, sf::RenderWindow &window) override{ return false; }
    void setValue(float value);
    float getValue() const;
};

