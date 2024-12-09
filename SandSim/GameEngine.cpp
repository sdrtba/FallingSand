#include "GameEngine.h"


GameEngine::GameEngine()
    : window(std::make_unique<sf::RenderWindow>(sf::VideoMode(windowWidth, windowHeight), L"Sand", sf::Style::Close)),
    game(std::make_unique<Game>(*window)) {
    initializeButtons();
    buttons.front()->setState(true);
    window->setFramerateLimit(360);
}

void GameEngine::initializeButtons() {
    struct ButtonData {
        sf::Vector2f pos;
        CellType cellType;
        std::string normalTexture;
        std::string clickedTexture;
    };

    std::vector<ButtonData> buttonData = {
        {{10, windowHeight - 40}, CellType::Empty, "image/empty.png", "image/empty1.png"},
        {{50, windowHeight - 40}, CellType::Sand, "image/sand.png", "image/sand1.png"},
        {{90, windowHeight - 40}, CellType::Water, "image/water.png", "image/water1.png"},
        {{130, windowHeight - 40}, CellType::Stone, "image/stone.png", "image/stone1.png"},
        {{170, windowHeight - 40}, CellType::Fire, "image/fire.png", "image/fire1.png"},
        {{210, windowHeight - 40}, CellType::Wood, "image/wood.png", "image/wood1.png"},
    };

    for (const auto& data : buttonData) {
        buttons.push_back(std::make_shared<Button>(
            data.pos,
            data.cellType,
            AssetManager::GetTexture(data.normalTexture),
            AssetManager::GetTexture(data.clickedTexture)
        ));
    }
}

void GameEngine::updateButtons(std::shared_ptr<Button> activeButton) {
    for (auto& button : buttons) {
        button->setState(button == activeButton);
    }
}

void GameEngine::input() {
    sf::Event event;
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) window->close();

        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Num0) isPaused = !isPaused;
            if (event.key.code == sf::Keyboard::LBracket) game->updateRadius(-1);
            else if (event.key.code == sf::Keyboard::RBracket) game->updateRadius(1);
        }
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
        if (mousePos.x < 0 || mousePos.x > windowWidth || mousePos.y < 0 || mousePos.y > windowHeight) return;

        for (auto& button : buttons) {
            if (button->checkClick(mousePos)) {
                updateButtons(button);
                game->setType(button->getCellType());
                return;
            }
        }

        game->setCell(mousePos);
    }
}

void GameEngine::update(sf::Time const& deltaTime) {
    window->setTitle(std::to_string(1 / deltaTime.asSeconds()));
    if (!isPaused) game->update(deltaTime);
}

void GameEngine::draw() {
    window->clear(sf::Color::Black);

    for (const auto& button : buttons) {
        window->draw(*button->getSprite());
    }

    game->draw();
    window->display();
}

void GameEngine::run() {
    sf::Clock clock;

    while (window->isOpen()) {
        sf::Time dt = clock.restart();
        input();
        update(dt);
        draw();
    }
}