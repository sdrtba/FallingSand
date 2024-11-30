#include "WaterCell.h"
#include <algorithm>

WaterCell::WaterCell(size_t x, size_t y) : Cell(x, y, CellType::Water) {}

void WaterCell::update(std::vector<std::vector<std::shared_ptr<Cell>>>& grid) {
    int width = grid.size();
    int height = grid[0].size();
    int direction = rand() % 2 * 2 - 1;

    if (isEmpty(x, y + 1, width, height) && grid[x][y + 1] == nullptr) {
        std::swap(grid[x][y], grid[x][y + 1]);
        y += 1;
    }

    else if (isEmpty(x + direction, y + 1, width, height) && grid[x + direction][y + 1] == nullptr) {
        std::swap(grid[x][y], grid[x + direction][y + 1]);
        x += direction;
        y += 1;
    }

    else if (isEmpty(x + direction, y, width, height) && grid[x + direction][y] == nullptr) {
        std::swap(grid[x][y], grid[x + direction][y]);
        x += direction;
    }


    updated = true;
}
