//
// Created by nikit on 28.07.2023.
//

#include "VolumeSlider.h"
#include <iostream>

void VolumeSlider::initTexture() {
    if(!texture.loadFromFile(R"(images\ScaleMusic.png)"))
        std::cout<<"Error, could find scale music\n";
}
