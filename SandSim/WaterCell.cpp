#include "WaterCell.h"
#include <algorithm>

WaterCell::WaterCell(size_t x, size_t y) : Cell(x, y, CellType::Water) {}

void WaterCell::update(std::vector<std::vector<std::shared_ptr<Cell>>>& grid) {
    int width = grid[0].size();
    int height = grid.size();

    // ѕровер€ем возможность перемещени€ вниз
    if (isEmpty(x, y + 1, width, height) && grid[y + 1][x] == nullptr) {
        std::swap(grid[y][x], grid[y + 1][x]);
        y += 1;
    }
    // ѕровер€ем возможность перемещени€ вниз-влево
    else if (isEmpty(x - 1, y + 1, width, height) && grid[y + 1][x - 1] == nullptr) {
        if (isEmpty(x + 1, y + 1, width, height) && grid[y + 1][x + 1] == nullptr) {
            if (moveRight()) {
                std::swap(grid[y][x], grid[y + 1][x + 1]);
                x += 1;
                y += 1;
            }
            else {
                std::swap(grid[y][x], grid[y + 1][x - 1]);
                x -= 1;
                y += 1;
            }
        }
        else {
            std::swap(grid[y][x], grid[y + 1][x - 1]);
            x -= 1;
            y += 1;
        }
    }
    // ѕровер€ем возможность перемещени€ вниз-вправо
    else if (isEmpty(x + 1, y + 1, width, height) && grid[y + 1][x + 1] == nullptr) {
        if (isEmpty(x - 1, y + 1, width, height) && grid[y + 1][x - 1] == nullptr) {
            if (moveRight()) {
                std::swap(grid[y][x], grid[y + 1][x + 1]);
                x += 1;
                y += 1;
            }
            else {
                std::swap(grid[y][x], grid[y + 1][x - 1]);
                x -= 1;
                y += 1;
            }
        }
        else {
            std::swap(grid[y][x], grid[y + 1][x + 1]);
            x += 1;
            y += 1;
        }
    }
    // ѕровер€ем возможность перемещени€ влево
    else if (isEmpty(x - 1, y, width, height) && grid[y][x - 1] == nullptr) {
        if (isEmpty(x + 1, y, width, height) && grid[y][x + 1] == nullptr) {
            if (moveRight()) {
                std::swap(grid[y][x], grid[y][x + 1]);
                x += 1;
            }
            else {
                std::swap(grid[y][x], grid[y][x - 1]);
                x -= 1;
            }
        }
        else {
            std::swap(grid[y][x], grid[y][x - 1]);
            x -= 1;
        }
    }
    // ѕровер€ем возможность перемещени€ вправо
    else if (isEmpty(x + 1, y, width, height) && grid[y][x + 1] == nullptr) {
        if (isEmpty(x - 1, y, width, height) && grid[y][x - 1] == nullptr) {
            if (moveRight()) {
                std::swap(grid[y][x], grid[y][x + 1]);
                x += 1;
            }
            else {
                std::swap(grid[y][x], grid[y][x - 1]);
                x -= 1;
            }
        }
        else {
            std::swap(grid[y][x], grid[y][x + 1]);
            x += 1;
        }
    }

    updated = true;  // ќтметить клетку как обновленную дл€ текущего кадра
}
