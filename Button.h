#pragma once

#include <SFML/Graphics.hpp>

template <class T>
class Button : public sf::Sprite{
public:

    Button(float _x, float _y, sf::Texture &texture, T func) : Sprite(texture), onClick(func){
        setPosition(_x,_y);
        m_texture = texture;
    }

    Button(float _x, float _y, T func) : onClick(func){
        setPosition(_x,_y);
    }

    Button(sf::Texture &texture, T func) : Sprite(texture), onClick(func){}

    void onClicked(int x, int y){
        sf::Vector2f mousePos((float)x, (float)y);
        if(checkClicked(mousePos)){
            onClick();
        }
    }

private:
    bool checkClicked(sf::Vector2f mousePos){
        return getGlobalBounds().contains(mousePos);
    }

    T onClick;

public:
    sf::Texture m_texture;
};
