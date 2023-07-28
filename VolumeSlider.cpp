//
// Created by nikit on 28.07.2023.
//
#include "VolumeSlider.h"
#include <iostream>

void VolumeSlider::initTexture() {
    if(!mainTex.loadFromFile(R"(images\ScaleMusic.png)"))
        std::cout<<"Error, could find scale music\n";
}

VolumeSlider::VolumeSlider() {
    initTexture();
    initSprite();
}

void VolumeSlider::update() {
    setValue(m_value);
    float percent = (m_value - m_minValue) / (m_maxValue - m_minValue);
    float sliderPosX = m_slider.getPosition().x + percent * m_slider.getSize().x;
    m_slider.setPosition(sliderPosX - m_slider.getSize().x / 2, m_slider.getPosition().y);
}

void VolumeSlider::render(sf::RenderTarget &target) {
    target.draw(m_slider);
}

VolumeSlider::VolumeSlider(float x, float y, float width, float height, float minValue, float maxValue) : m_slider(sf::Vector2f(width,height)), m_value(50.f),
m_minValue(minValue), m_maxValue(maxValue) {
    m_slider.setPosition(x,y);
    m_slider.setFillColor(sf::Color::Red);
    update();
}

void VolumeSlider::setValue(float value) {
    m_value = value;
    if(value > m_maxValue)
        m_value = m_maxValue;
    else if(value < m_minValue)
        m_value = m_minValue;
    //update();
}

float VolumeSlider::getValue() const {
    return m_value;
}

void VolumeSlider::handleEvent(sf::Event event, sf::RenderWindow &window) {
    if (event.type == sf::Event::MouseButtonPressed)
    {
        sf::Vector2f mousePosition = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
        if (m_slider.getGlobalBounds().contains(mousePosition))
        {
            m_dragging = true;
        }
    }
    else if (event.type == sf::Event::MouseButtonReleased)
    {
        m_dragging = false;
    }
    else if(event.type == sf::Event::MouseMoved && m_dragging)
    {
        float relativeX = event.mouseMove.x - m_slider.getPosition().x;
        float percent = relativeX / m_slider.getSize().x;
        m_value = m_minValue + percent * (m_maxValue - m_minValue);
        update();
    }
}
