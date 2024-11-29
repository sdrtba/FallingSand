#pragma once
#include "StoneCell.h"
#include "WaterCell.h"
#include "SandCell.h"
#include "Cell.h"
#include <SFML/Graphics.hpp>


class Game {
public:
	Game(sf::RenderWindow& window);

	bool InBounds(int x, int y);

	bool IsEmpty(int x, int y);

	bool IsUpdatableCell(int x, int y);

	void setCell(sf::Vector2i position);

	void setType(CellType newType);

	void updateRadius(int r);

	void update(sf::Time const& deltaTime);

	void draw();

private:
	CellType type;
	int width, height, scale;
	int radius = 0;
	sf::RenderWindow& window;
	std::vector<std::vector<std::shared_ptr<Cell>>> grid;
};