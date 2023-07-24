#include "Game.h"

Game::Game() {
    this->initWindow();
    this->initPlayer();
    this->initWorld();
}

Game::~Game(){
    delete this->window;
    delete this->player;
}

void Game::run() {
    while(this->window->isOpen()){
        this->update();
        this->render();
    }
}

void Game::initWindow() {
    this->window = new sf::RenderWindow (sf::VideoMode(1800, 990), "GYMbox/build_1.0", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(90);
    this->window->setVerticalSyncEnabled(true);
}

void Game::initPlayer() {

    this->player = new ButtonPlayer();
    this->player->setPosition(250,150);
}

void Game::update() {
    sf::Event event;
    while(this->window->pollEvent(event)){
        if(event.Event::type == sf::Event::Closed){
            this->window->close();
        }
        if(event.Event::KeyPressed && event.Event::key.code == sf::Keyboard::Escape){
            this->window->close();
        }

        this->player->handleClickEvent(event, *this->window);
    }
}

void Game::render() {
    this->window->clear();
    this->renderWorld();
    this->player->render(*this->window);
    this->window->display();
}

void Game::initWorld() {
    if(!this->worldBackgroundTex.loadFromFile("C:\\Users\\glebm\\CLionProjects\\GYMbox\\images\\BackGym.png")){
        std::cout << "ERROR";
    }
    this->worldBackground.setTexture(this->worldBackgroundTex);
}

void Game::renderWorld() {
    this->window->draw(this->worldBackground);
}