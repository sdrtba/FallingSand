#pragma once
#include "Game.h"


class GameEngine {
public:
	GameEngine();
	void run();
private:
	std::unique_ptr<sf::RenderWindow> window = std::make_unique<sf::RenderWindow>(sf::VideoMode(800, 600), L"Sand", sf::Style::Close);
	std::unique_ptr<Game> game = std::make_unique<Game>(*window);

	void input();
	void update(sf::Time const& deltaTime);
	void draw();

	bool ispause = false;
};