#include "PowderCell.h"
#include "FireCell.h"

PowderCell::PowderCell(int x, int y) : Cell(x, y, CellType::Powder) {
    fireResist = rand() % 5;
}

void PowderCell::update(std::vector<std::vector<std::shared_ptr<Cell>>>& grid) {
    if (fireResist < 0) {
        grid[x][y] = std::make_shared<FireCell>(x, y);

        for (int dx = -2; dx <= 2; dx++) {
            for (int dy = -2; dy <= 2; dy++) {
                if (inBounds(x + dx, y + dy)) {
                    if (grid[x + dx][y + dy] &&
                        !(grid[x + dx][y + dy]->type == CellType::Fire ||
                        grid[x + dx][y + dy]->type == CellType::Powder)) {
                        grid[x + dx][y + dy] = nullptr;
                    }
                }
            }
        }

        return;
    }

    width = grid.size();
    height = grid[0].size();
    direction = rand() % 2 * 2 - 1;

    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (inBounds(x + dx, y + dy)) {
                if (grid[x + dx][y + dy] && grid[x + dx][y + dy]->type == CellType::Fire) {
                    fireResist -= 1;
                }
            }
        }
    }

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
    }
}
