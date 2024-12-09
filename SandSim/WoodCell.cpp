#include "WoodCell.h"
#include "FireCell.h"
#include <algorithm>

WoodCell::WoodCell(int x, int y) : Cell(x, y, CellType::Wood) {
    fireResist = rand() % 10;
}

void WoodCell::update(std::vector<std::vector<std::shared_ptr<Cell>>>& grid) {
    if (fireResist < 0) {
        grid[x][y] = std::make_unique<FireCell>(x, y);
    }
    updated = true;
}
