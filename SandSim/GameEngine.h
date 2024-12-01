#pragma once
#include "Game.h"
#include "Button.h"


class GameEngine {
public:
	GameEngine();
	void run();
private:
	AssetManager manager;
	std::unique_ptr<sf::RenderWindow> window = std::make_unique<sf::RenderWindow>(sf::VideoMode(800, 600), L"Sand", sf::Style::Close);
	std::unique_ptr<Game> game = std::make_unique<Game>(*window);

	Button emptyBtn = Button(sf::Vector2f(10, 600 - 40), AssetManager::GetTexture("image/empty.png"), AssetManager::GetTexture("image/empty1.png"));
	Button sandBtn = Button(sf::Vector2f(10 + 40, 600 - 40), AssetManager::GetTexture("image/sand.png"), AssetManager::GetTexture("image/sand1.png"));
	Button waterBtn = Button(sf::Vector2f(10 + 80, 600 - 40), AssetManager::GetTexture("image/water.png"), AssetManager::GetTexture("image/water1.png"));
	Button stoneBtn = Button(sf::Vector2f(10 + 120, 600 - 40), AssetManager::GetTexture("image/stone.png"), AssetManager::GetTexture("image/stone1.png"));
	Button fireBtn = Button(sf::Vector2f(10 + 160, 600 - 40), AssetManager::GetTexture("image/fire.png"), AssetManager::GetTexture("image/fire1.png"));
	Button woodBtn = Button(sf::Vector2f(10 + 200, 600 - 40), AssetManager::GetTexture("image/wood.png"), AssetManager::GetTexture("image/wood1.png"));

	void updateButtons(int index);
	void input();
	void update(sf::Time const& deltaTime);
	void draw();

	bool ispause = false;
};