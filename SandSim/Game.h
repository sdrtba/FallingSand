#pragma once
#include "StoneCell.h"
#include "WaterCell.h"
#include "SandCell.h"
#include "Cell.h"
#include "AssetManager.h"


class Game {
public:
	Game(sf::RenderWindow& window);

	bool InBounds(int x, int y);

	bool IsEmpty(int x, int y);

	void setCell(sf::Vector2i position);

	void setType(CellType newType);

	void updateRadius(int r);

	void update(sf::Time const& deltaTime);

	void draw();

private:
	sf::Texture textureAtlas;
	sf::IntRect sandRect;
	sf::IntRect waterRect;
	sf::IntRect stoneRect;

	CellType type;
	int width, height, scale;
	int radius = 0;
	sf::RenderWindow& window;
	std::vector<std::vector<std::shared_ptr<Cell>>> grid;
};