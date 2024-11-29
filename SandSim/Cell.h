#pragma once
#include <vector>
#include <memory>

enum class CellType {Sand, Water, Fire, Stone, Empty};

class Cell {
public:
	size_t x, y;
	CellType type = CellType::Empty;
	bool updated = false;

	Cell(size_t x, size_t y, CellType type);
	virtual ~Cell() {}

	virtual void update(std::vector<std::vector<std::shared_ptr<Cell>>>& grid) = 0;
	bool isEmpty(size_t nx, size_t ny, size_t width, size_t height);
	bool moveRight();
};