#pragma once
#include <vector>
#include <memory>
#include <iostream>
#include "CellType.h"

class Cell {
public:
	int x, y;
	int width;
	int height;
	int direction;
	CellType type;
	bool updated;
	int lifetime;
	int fireResist;
	int tickToMove;
	

	Cell(int x, int y, CellType type);
	virtual ~Cell() {}

	virtual void update(std::vector<std::vector<std::shared_ptr<Cell>>>& grid) = 0;
	bool sideIsEmpty(int nx, int ny, std::vector<std::vector<std::shared_ptr<Cell>>>& grid);
	bool inBounds(int nx, int ny);
};