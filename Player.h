//
// Created by nikit on 15.06.2023.
//
#include "DynamicObject.h"
#ifndef GYMBOX_PLAYER_H
#define GYMBOX_PLAYER_H


class Player : DynamicObject{
public:
    Player(sf::Texture &texture, float _x, float _y);
    void control() override;
    void update(float time) override;
};


#endif //GYMBOX_PLAYER_H
