#include "FireCell.h"

FireCell::FireCell(int x, int y) : Cell(x, y, CellType::Fire) {
    lifetime = rand() % 20 + 5;
    tickToMove = rand() % 1 + 0;
}

void FireCell::update(std::vector<std::vector<std::shared_ptr<Cell>>>& grid) {
    if (lifetime < 0) {
        grid[x][y] = nullptr;
        return;
    }
    else if (tickToMove > 0) {
        tickToMove -= 1;
        return;
    }

    int probality = rand() % 3;

    width = grid.size();
    height = grid[0].size();
    direction = rand() % 2 * 2 - 1;
    tickToMove = rand() % 20 + 7;
    lifetime -= 1;

    if (probality == 0 && inBounds(x, y - 1)) {
        if (grid[x][y - 1] == nullptr) {
            std::swap(grid[x][y], grid[x][y - 1]);
            updated = true;
            y -= 1;
        }
    }

    if (probality == 1 && inBounds(x + direction, y - 1)) {
        if (grid[x + direction][y - 1] == nullptr) {
            std::swap(grid[x][y], grid[x + direction][y - 1]);
            updated = true;
            x += direction;
            y -= 1;
        }
    }

    if (probality == 2 && inBounds(x - direction, y)) {
        if (grid[x - direction][y] == nullptr) {
            std::swap(grid[x][y], grid[x - direction][y]);
            updated = true;
            x -= direction;
        }
    }

    updated = true;
}
