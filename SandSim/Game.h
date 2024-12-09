#pragma once
#include "WoodCell.h"
#include "FireCell.h"
#include "StoneCell.h"
#include "WaterCell.h"
#include "SandCell.h"
#include "Cell.h"
#include "AssetManager.h"


class Game {
public:
	Game(sf::RenderWindow& window);

	bool InBounds(int x, int y) const;

	bool IsEmpty(int x, int y) const;

	void setCell(sf::Vector2i position);

	std::shared_ptr<Cell> createCell(int x, int y);

	void setType(CellType newType);

	void updateRadius(int dr);

	void update(sf::Time const& deltaTime);

	void draw();

	sf::IntRect getRectForCell(CellType cellType) const;
private:
	sf::Texture textureAtlas;
	sf::IntRect sandRect, waterRect, stoneRect, fireRect, woodRect;

	CellType type;
	int width, height, scale, radius;
	sf::RenderWindow& window;
	std::vector<std::vector<std::shared_ptr<Cell>>> grid;
};