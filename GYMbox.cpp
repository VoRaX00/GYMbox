// Created by nikit on 14.06.2023.
//
#include "GYMbox.h"

using namespace sf;
using namespace std;




void updateWalkImage(Texture& texture, Sprite& sprite, int& numImage, int& time, RenderWindow& window){
    if(time<250){
        time++;
        return;
    }
    else{
        if(numImage > 8){
            numImage = 1;
        }

        time = 1;
        std::string path = "C:\\Users\\nikit\\CLionProjects\\GYMbox\\images\\walk\\walk" + std::to_string(numImage)+".png";
        if(!texture.loadFromFile(path)) {
            window.close();
        }
        numImage++;

        sprite.setTexture(texture);
    }
}

void fun(){
    std::cout<<"Hello";
}


bool loadImage(sf::Texture &texture, std::string path){
    return texture.loadFromFile(path);
}

void game(){
    const std::string PATH_WALK1 = R"(images\walk\walk1.png)";
    const std::string DEFAULT_PATH_BUTTON = R"(images\button.png)";

    sf::RenderWindow window(sf::VideoMode(800, 600), "GYM!!!");//Создание окна 800*600
    bool isLeft = false; //проверка повёрнут ли персонаж на лево

    sf::Texture texturePerson; // текстура персонажа

    if (!loadImage(texturePerson, PATH_WALK1)) { //загрузка текстуры
        window.close();
    }

    sf::Texture textureButton;

    if (!loadImage(textureButton, DEFAULT_PATH_BUTTON)) {
        window.close();
    }

    auto button = std::make_unique<Button<std::function<void()>>>(20,30,textureButton, fun); //Кнопка

    sf::Sprite person(texturePerson);

    int numberRunSprite = 1;
    int time = 0;

    while (window.isOpen()) {
        auto event = std::make_unique<Event>();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            updateWalkImage(texturePerson, person, numberRunSprite, time, window);

            person.move(-0.1f, 0.f);
            if (!isLeft) {
                person.setScale(-1.f, 1.f);
            }
            isLeft = true;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            updateWalkImage(texturePerson, person, numberRunSprite, time, window);

            person.move(0.1f, 0.f);
            if (isLeft)
                person.setScale(1.f, 1.f);
            isLeft = false;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            person.move(0.f, -0.1f);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            person.move(0.f, 0.1f);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {//Написать прыжок

        }

        while (window.pollEvent(*event)) {
            switch (event->type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseButtonPressed:
                    if (event->mouseButton.button == sf::Mouse::Left) {
                        button->onClicked(event->mouseButton.x, event->mouseButton.y);
                    }
                    break;

                default:
                    break;
            }
        }

        window.clear();
        window.draw(person);
        window.draw(*button);
        window.display();
    }
}