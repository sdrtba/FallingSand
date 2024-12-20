#include "Cell.h"

Cell::Cell(int x, int y, CellType type) : x(x), y(y), type(type) {
	updated = false;
}

bool Cell::inBounds(int nx, int ny) {
    return nx >= 0 && nx < width && ny >= 0 && ny < height;
}

bool Cell::sideIsEmpty(int nx, int ny, std::vector<std::vector<std::shared_ptr<Cell>>>& grid) {
	return grid[nx][ny] == nullptr;
}

void Cell::update(std::vector<std::vector<std::shared_ptr<Cell>>>& grid) {
}