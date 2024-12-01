#include "FireCell.h"
#include <algorithm>

FireCell::FireCell(size_t x, size_t y) : Cell(x, y, CellType::Fire) {
    lifetime = rand() % 30 + 10;
    tickToMove = rand() % 30 + 30;
}

void FireCell::update(std::vector<std::vector<std::shared_ptr<Cell>>>& grid) {
    tickToMove -= 1;
    if (tickToMove > 0) {
        return;
    }
    tickToMove = rand() % 30 + 30;
    lifetime -= 1;
    int width = grid.size();
    int height = grid[0].size();
    int direction = rand() % 2 * 2 - 1;

    if (inBounds(x, y - 1, width, height)) {
        if (grid[x][y - 1] == nullptr) {
            std::swap(grid[x][y], grid[x][y - 1]);
            y -= 1;
        }
        else if (grid[x][y - 1]->type == CellType::Wood) {
            grid[x][y - 1]->fireResist -= 1;
        }
    }

    if (inBounds(x + direction, y - 1, width, height)) {
        if (grid[x + direction][y - 1] == nullptr) {
            std::swap(grid[x][y], grid[x + direction][y - 1]);
            x += direction;
            y -= 1;
        }
        else if (grid[x + direction][y - 1]->type == CellType::Wood) {
            grid[x + direction][y - 1]->fireResist -= 1;
        }
    }

    if (inBounds(x + direction, y, width, height)) {
        if (grid[x + direction][y] == nullptr) {
            std::swap(grid[x][y], grid[x + direction][y]);
            x += direction;
        }
        else if (grid[x + direction][y]->type == CellType::Wood) {
            grid[x + direction][y]->fireResist -= 1;
        }
    }

    if (lifetime < 0) {
        grid[x][y] = nullptr;
    }

    updated = true;
}
