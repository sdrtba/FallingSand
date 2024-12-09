#include "SandCell.h"
#include <algorithm>

SandCell::SandCell(int x, int y) : Cell(x, y, CellType::Sand) {}

void SandCell::update(std::vector<std::vector<std::shared_ptr<Cell>>>& grid) {
    int width = grid.size();
    int height = grid[0].size();
    int direction = rand() % 2 * 2 - 1;

    if (inBounds(x, y + 1, width, height) && grid[x][y + 1] == nullptr) {
        std::swap(grid[x][y], grid[x][y + 1]);
        y += 1;
    }

    else if (inBounds(x + direction, y + 1, width, height) && grid[x + direction][y + 1] == nullptr) {
        std::swap(grid[x][y], grid[x + direction][y + 1]);
        x += direction;
        y += 1;
    }

    if (grid[x][y + 1] && inBounds(x, y + 1, width, height) && grid[x][y + 1]->type == CellType::Water) {
        std::swap(grid[x][y], grid[x][y + 1]);
        grid[x][y]->y -=  1;
        grid[x][y]->updated = false;
        y += 1;
    }

    updated = true;
}
