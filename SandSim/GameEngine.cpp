#include "GameEngine.h"

GameEngine::GameEngine() {
	emptyBtn.setState(true);
}

void GameEngine::updateButtons(int index) {
	emptyBtn.setState(false);
	sandBtn.setState(false);
	waterBtn.setState(false);
	stoneBtn.setState(false);
	switch (index) {
	case 0:
		emptyBtn.setState(true);
		break;
	case 1:
		sandBtn.setState(true);
		break;
	case 2:
		waterBtn.setState(true);
		break;
	case 3:
		stoneBtn.setState(true);
		break;
	}
}

void GameEngine::input() {
	sf::Event event;
	while (window->pollEvent(event)) {
		if (event.type == sf::Event::Closed) window->close();

		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Num0) ispause = !ispause;
			if (event.key.code == sf::Keyboard::LBracket) game->updateRadius(-1);
			else if (event.key.code == sf::Keyboard::RBracket) game->updateRadius(1);
		}
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		if (emptyBtn.checkClick(sf::Mouse::getPosition(*window)))
		{
			updateButtons(0);
			game->setType(CellType::Empty);

		}
		else if (sandBtn.checkClick(sf::Mouse::getPosition(*window)))
		{
			updateButtons(1);
			game->setType(CellType::Sand);
		}
		else if (waterBtn.checkClick(sf::Mouse::getPosition(*window)))
		{
			updateButtons(2);
			game->setType(CellType::Water);
		}
		else if (stoneBtn.checkClick(sf::Mouse::getPosition(*window)))
		{
			updateButtons(3);
			game->setType(CellType::Stone);
		}
		else {
			game->setCell(sf::Mouse::getPosition(*window));
		}
	} 
}

void GameEngine::update(sf::Time const& deltaTime) {
	// !!!!
	window->setTitle(std::to_string(1 / deltaTime.asSeconds()));
	if (!ispause) game->update(deltaTime);
}

void GameEngine::draw() {
	window->clear(sf::Color::Black);

	window->draw(*emptyBtn.getSprite());
	window->draw(*sandBtn.getSprite());
	window->draw(*waterBtn.getSprite());
	window->draw(*stoneBtn.getSprite());

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