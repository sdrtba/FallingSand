#include "SandCell.h"

SandCell::SandCell(int x, int y) : Cell(x, y, CellType::Sand) {}

void SandCell::update(std::vector<std::vector<std::shared_ptr<Cell>>>& grid) {
    width = grid.size();
    height = grid[0].size();
    direction = rand() % 2 * 2 - 1;

    if (!updated && inBounds(x, y + 1)) {
        if (grid[x][y + 1] == nullptr) {
            updated = true;
            std::swap(grid[x][y], grid[x][y + 1]);
            y += 1;
        }
        else if (grid[x][y + 1]->type == CellType::Water) {
            updated = true;
            std::swap(grid[x][y], grid[x][y + 1]);
            grid[x][y]->y -= 1;
            grid[x][y]->updated = false;
            y += 1;
        }
        else if (grid[x][y + 1]->type == CellType::Fire) {
            updated = true;
            grid[x][y + 1] = nullptr;
        }
    }

    if (!updated && inBounds(x + direction, y + 1) && sideIsEmpty(x + direction, y, grid)) {
        if (grid[x + direction][y + 1] == nullptr) {
            updated = true;
            std::swap(grid[x][y], grid[x + direction][y + 1]);
            x += direction;
            y += 1;
        }
        else if (grid[x + direction][y + 1]->type == CellType::Water) {
            std::swap(grid[x][y], grid[x + direction][y + 1]);
            updated = true;
            grid[x][y]->y -= 1;
            grid[x][y]->x -= direction;
            grid[x][y]->updated = false;
            y += 1;
            x += direction;
        }
        else if (grid[x + direction][y + 1]->type == CellType::Fire) {
            updated = true;
            grid[x + direction][y + 1] = nullptr;
        }
    }
}
