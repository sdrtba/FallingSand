#include "GameEngine.h"

GameEngine::GameEngine() {
	
}

void GameEngine::input() {
	sf::Event event;
	while (window->pollEvent(event)) {
		if (event.type == sf::Event::Closed) window->close();

		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Num0) {
				ispause = !ispause;
			}
			if (event.key.code == sf::Keyboard::LBracket) {
				game.updateRadius(-1);
			}
			else if (event.key.code == sf::Keyboard::RBracket) {
				game.updateRadius(1);
			}
			if (event.key.code == sf::Keyboard::Num1) {
				game.setType(CellType::Sand);
			}
			else if (event.key.code == sf::Keyboard::Num2) {
				game.setType(CellType::Water);
			}
			else if (event.key.code == sf::Keyboard::Num3) {
				game.setType(CellType::Stone);
			}
			else if (event.key.code == sf::Keyboard::Num4) {
				game.setType(CellType::Empty);
			}
		}
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		game.setCell(sf::Mouse::getPosition(*window));
	}
}

void GameEngine::update(sf::Time const& deltaTime) {
	if (!ispause) game.update(deltaTime);
}

void GameEngine::draw() {
	window->clear(sf::Color::Black);
	game.draw();
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