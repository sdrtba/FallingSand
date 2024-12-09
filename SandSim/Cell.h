#pragma once
#include <vector>
#include <memory>

enum class CellType { Sand, Water, Fire, Stone, Wood, Empty };

class Cell {
public:
	int x, y;
	CellType type = CellType::Empty;
	bool updated = false;
	int lifetime;
	int fireResist;
	int tickToMove;

	Cell(int x, int y, CellType type);
	virtual ~Cell() {}

	virtual void update(std::vector<std::vector<std::shared_ptr<Cell>>>& grid) = 0;
	bool inBounds(int nx, int ny, int width, int height);
};