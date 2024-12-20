#pragma once
#include "Game.h"
#include "Button.h"

class GameEngine {
public:
    GameEngine();
    void run();
private:
    static constexpr int windowWidth = 800;
    static constexpr int windowHeight = 600;
    bool isPaused = false;

    AssetManager assetManager;
    std::unique_ptr<sf::RenderWindow> window;
    std::unique_ptr<Game> game;
    std::vector<std::shared_ptr<Button>> buttons;
    
    void input();
    void update(sf::Time const& deltaTime);
    void draw();

    void initializeButtons();
    void updateButtons(std::shared_ptr<Button> activeButton);
};