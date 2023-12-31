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
}

Game::~Game(){ //Деструктор класса Game, в котором удаляются объекты
    delete window;
    delete player;
    delete strong;
    delete start;
    delete buttonMenu;
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
}

void Game::initPlayer() { //инициализация игрока

    player = new ButtonPlayer();
    player->setPosition(150,0);
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

        if(event.Event::type == sf::Event::Closed)
            window->close();

        if(event.Event::key.code == sf::Keyboard::Escape)
            window->close();

        if(theEnd)
            break;


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
                initMenu();
                break;
            }else if(isButtonMenuClicked){
                sound.play();
                menuClicked = false;
                delete menu;
                menu = nullptr;
                break;
            }

            if(menuClicked) {
                float currentVolume = backgroundMusic.getVolume();
                menu->update(event, *window);
                if(menu->click) {
                    float newVolume = (currentVolume + menu->getVolume());

                    if (newVolume > 100.f)
                        newVolume = 100.f;
                    else if (newVolume < 0.f)
                        newVolume = 0.f;
                    else if((int)newVolume%10==9){
                        newVolume++;
                    }

                    backgroundMusic.setVolume(newVolume);
                }
                break;
            }
            playerClick = player->handleClickEvent(event, *window);

            if (playerClick) {
                sound.play();
                break;
            }

            if ((player->points >= strong->price) && (strong->handleClickEvent(event, *window)) && !menuClicked) {
                sound.play();
                player->points -= strong->price;
                strong->price += level * 20;
                player->power += level + 1;
                multiplier += 600;
            }

            if (multiplier == 1800 && level <= 4) {
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
        sf::sleep(sf::seconds(0.14));
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

    if(!endWorldBackgroundTex.loadFromFile(R"(images\BackGymD.png)")){
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

    pointText.setPosition(900.f, 25.f);
    pointText.setFont(font);
    pointText.setCharacterSize(50);
    pointText.setFillColor(sf::Color::Black);
    pointText.setString("test");

    strongText.setPosition(1200.f, 200.f);
    strongText.setFont(font);
    strongText.setCharacterSize(30);
    strongText.setFillColor(sf::Color::Cyan);
    strongText.setString("test");

    levelText.setPosition(900.f, 900.f);
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
    ssq << "STRONG::POWER: " << strong->price;
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

    if (level == 5 && multiplier == 1800){
        worldBackground.setTexture(endWorldBackgroundTex);
        renderWorld();
        theEnd = true;
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