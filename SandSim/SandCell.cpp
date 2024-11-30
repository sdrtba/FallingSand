#include "SandCell.h"
#include <algorithm>

SandCell::SandCell(size_t x, size_t y) : Cell(x, y, CellType::Sand) {}

void SandCell::update(std::vector<std::vector<std::shared_ptr<Cell>>>& grid) {
    int width = grid[0].size();
    int height = grid.size();
    int direction = rand() % 2 * 2 - 1;

    if (isEmpty(x, y + 1, width, height) && grid[y + 1][x] == nullptr) {
        std::swap(grid[y][x], grid[y + 1][x]);
        y += 1;
    }

    else if (isEmpty(x + direction, y + 1, width, height) && grid[y + 1][x + direction] == nullptr) {
        std::swap(grid[y][x], grid[y + 1][x + direction]);
        x += direction;
        y += 1;
    }

    updated = true;
}
