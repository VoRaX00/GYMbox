#include "Game.h"

Game::Game() { //Конструктор класса Game, в котором инициализируются все объекты это класса
    initWindow();
    initPlayer();
    initStrong();
    initStart();
    initWorld();
    initGUI();
    initSystems();
    initButtonMenu();
    initMenu();
}

Game::~Game(){ //Деструктор класса Game, в котором удаляются объекты
    delete window;
    delete player;
    delete strong;
    delete start;
    delete buttonMenu;
    delete menu;
}

void Game::run() { //запуск игры
    backgroundMusic.play();
    backgroundMusic.setLoop(true);

    while (window->isOpen()) {
        update();
        render();
    }
}

void Game::initWindow() { //инициализация окна
    window = new sf::RenderWindow (sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "GYMbox/09.03.04", sf::Style::Titlebar | sf::Style::Close);
    window->setFramerateLimit(90);
    //window->setVerticalSyncEnabled(true);
}

void Game::initPlayer() { //инициализация игрока

    player = new ButtonPlayer();
    player->setPosition(250,150);
}

void Game::initStrong() { //инициализация кнопки

    strong = new ButtonStrong();
    strong->setPosition(1150,150);
}

void Game::initStart() { //инициализация кнопки старт

    start = new ButtonStart();
    start->setPosition(0,50);
}


void Game::initButtonMenu() { //инициализация кнопки меню
    buttonMenu = new ButtonMenu();
    buttonMenu->setPosition(0,0);
}


void Game::update() { //метод, который отлавливает действия пользователя
    sf::Event event;
    while(window->pollEvent(event)){
        if(event.Event::type == sf::Event::Closed){
            window->close();
        }
        if(event.Event::key.code == sf::Keyboard::Escape){
            window->close();
        }

        if (!startButtonPressed) {
            if (start->handleClickEvent(event, *window)) {
                sound.play();
                startButtonPressed = true;
            }
        } else {
            bool isButtonMenuClicked = buttonMenu->handleClickEvent(event,*window);
            if(isButtonMenuClicked && !menuClicked){
                sound.play();
                menuClicked = true;
                break;
            }else if(isButtonMenuClicked){
                sound.play();
                menuClicked = false;
                break;
            }

            if(!menuClicked)
                playerClick = player->handleClickEvent(event, *window);

            if (playerClick)
                sound.play();

            if ((player->points >= strong->price) && (strong->handleClickEvent(event, *window)) && !menuClicked) {
                    sound.play();
                    player->points -= strong->price;
                    strong->price *= 3;
                    player->power *= 5;
                    multiplier += 600;
            }

            if (multiplier == 1800) {
                newLevel();
            }
        }
    }

    updateGUI();
}


void Game::render() { // отрисовка изображений на окне
    sf::Event event;

    if (playerClick) {
        player->resetTexturePressed();
        renderDefault();
        sf::sleep(sf::seconds(0.1));
        player->resetTextureReleased();
    }

    if (!startButtonPressed) {
        window->clear();
        renderWorld();
        start->render(*window);
        window->display();
    } else {
        renderDefault();
    }
}


void Game::initWorld() { //инициализация мира
    if(!worldBackgroundTex.loadFromFile(R"(images\BackGym.png)")){
        std::cout << "ERROR";
    }
    worldBackground.setTexture(worldBackgroundTex);
}

void Game::renderWorld() { //отрисовка мира
    window->draw(worldBackground);
}

void Game::initGUI(){ //инициализация всех текстовых полей на сцене
    if (!font.loadFromFile(R"(C:\Windows\Fonts\Arial.ttf)"))
        std::cout << "ERROR::GAME::Failed to load font\n";

    pointText.setPosition(700.f, 25.f);
    pointText.setFont(font);
    pointText.setCharacterSize(50);
    pointText.setFillColor(sf::Color::Black);
    pointText.setString("test");

    strongText.setPosition(1250.f, 200.f);
    strongText.setFont(font);
    strongText.setCharacterSize(30);
    strongText.setFillColor(sf::Color::White);
    strongText.setString("test");

    levelText.setPosition(700.f, 900.f);
    levelText.setFont(font);
    levelText.setCharacterSize(50);
    levelText.setFillColor(sf::Color::Black);
    levelText.setString("test");

    playerHpBar.setSize(sf::Vector2f(1800.f, 25.f));
    playerHpBar.setFillColor(sf::Color::Yellow);
    playerHpBar.setPosition(sf::Vector2f(0.f, 970.f));

    playerHpBarBack = playerHpBar;
    playerHpBarBack.setFillColor(sf::Color(25, 25, 25, 200));
}

void Game::initSystems(){ //инициализация системы
    points = 0;
    multiplier = 0;
    level = 1;
    if (!backgroundMusic.openFromFile("music\\ACDC.ogg")) {
        std::cout << "ERROR::GAME::Failed to load background music" << std::endl;
    }

    if (!buffer.loadFromFile("music\\sound.ogg")) {
        std::cout << "ERROR" << std::endl;
    }

    sound.setBuffer(buffer);
}

void Game::updateGUI(){ //метод, который изменяет текстовые поля взависимости от действий пользователя
    std::stringstream ss;
    std::stringstream ssq;
    std::stringstream ssl;
    ss << "POWER: " << player->points;
    ssq << "STRONG//PRICE: " << strong->price;
    ssl << "LEVEL: " << level;
    pointText.setString(ss.str());
    strongText.setString(ssq.str());
    levelText.setString(ssl.str());

    float hpPercent = static_cast<float>(player->getHp()) / player->getHpMax();
    playerHpBar.setSize(sf::Vector2f(multiplier * hpPercent, playerHpBar.getSize().y));
}

void Game::renderGUI() //отрисовка текстовых полей
{
    window->draw(pointText);
    window->draw(strongText);
    window->draw(levelText);
    window->draw(playerHpBarBack);
    window->draw(playerHpBar);
}

void Game::renderDefault() { //Базовая отрисовка всей сцены
    window->clear();
    renderWorld();
    player->render(*window);
    strong->render(*window);
    buttonMenu->render(*window);
    renderGUI();
    if(menuClicked){
        menu->render(*window);
    }
    window->display();
}

void Game::newLevel() { // Метод изменяющий уровень
    level++;

    std::string pathMain = "images/G1" + std::to_string(level) + ".png"; //После второго уровня будет белый квадрат, так как у нас нет следующих спрайтов
    std::string pathPressed = "images/G2" + std::to_string(level) + ".png";
    player->setMainTexture(pathMain);
    player->setPressedTexture(pathPressed);

    multiplier = 0;
}

void Game::initMenu() {
    menu = new Menu();
    menu->setPosition(400.f, 100);
}
