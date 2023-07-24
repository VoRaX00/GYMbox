#include "Game.h"

Game::Game() {
    this->initWindow();
    this->initPlayer();
    this->initStrong();
    this->initWorld();
    this->initGUI();
    this->initSystems();
}

Game::~Game(){
    delete this->window;
    delete this->player;
    delete this->strong;
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

void Game::initStrong() {

    this->strong = new ButtStrong();
    this->strong->setPosition(1150,150);
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
        this->strong->handleClickEvent(event, *this->window);
    }

    this->updateGUI();
}

void Game::render() {
    this->window->clear();
    this->renderWorld();
    this->player->render(*this->window);
    this->strong->render(*this->window);
    this->renderGUI();
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

void Game::initGUI()
{
    if (!this->font.loadFromFile("C:\\Windows\\Fonts\\Arial.ttf"))
        std::cout << "ERROR::GAME::Failed to load font" << "\n";

    this->pointText.setPosition(700.f, 25.f);
    this->pointText.setFont(this->font);
    this->pointText.setCharacterSize(50);
    this->pointText.setFillColor(sf::Color::Black);
    this->pointText.setString("test");

    this->playerHpBar.setSize(sf::Vector2f(1800.f, 25.f));
    this->playerHpBar.setFillColor(sf::Color::Yellow);
    this->playerHpBar.setPosition(sf::Vector2f(0.f, 980.f));

    this->playerHpBarBack = this->playerHpBar;
    this->playerHpBarBack.setFillColor(sf::Color(25, 25, 25, 200));
}

void Game::initSystems()
{
    this->points = 0;
    this->multiplier = 0;
}

void Game::updateGUI()
{
    std::stringstream ss;

    ss << "POWER: " << this->player->points;

    this->pointText.setString(ss.str());

    float hpPercent = static_cast<float>(this->player->getHp()) / this->player->getHpMax();
    this->playerHpBar.setSize(sf::Vector2f(multiplier * hpPercent, this->playerHpBar.getSize().y));
}

void Game::renderGUI()
{
    this->window->draw(this->pointText);
    this->window->draw(this->playerHpBarBack);
    this->window->draw(this->playerHpBar);
}