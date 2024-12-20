#pragma once
#include "PowderCell.h"
#include "WoodCell.h"
#include "FireCell.h"
#include "StoneCell.h"
#include "WaterCell.h"
#include "SandCell.h"
#include "AssetManager.h"

class Game {
public:
	Game(sf::RenderWindow& window);

	void setCell(sf::Vector2i position);

	void setType(CellType newType);

	void updateRadius(int dr);

	void update(sf::Time const& deltaTime);

	void draw();

	void clear();

	
private:
	bool InBounds(int x, int y) const;
	bool IsEmpty(int x, int y) const;
	std::shared_ptr<Cell> createCell(int x, int y);
	sf::IntRect getRectForCell(CellType cellType) const;

	sf::Texture textureAtlas;
	sf::IntRect sandRect, waterRect, stoneRect, fireRect, woodRect, powderRect;

	CellType type;
	int width, height, scale, radius;
	sf::RenderWindow& window;
	std::vector<std::vector<std::shared_ptr<Cell>>> grid;
};