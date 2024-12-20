#include "WoodCell.h"
#include "FireCell.h"

WoodCell::WoodCell(int x, int y) : Cell(x, y, CellType::Wood) {
    fireResist = rand() % 10 + 200;
}

void WoodCell::update(std::vector<std::vector<std::shared_ptr<Cell>>>& grid) {
    if (fireResist < 0) {
        grid[x][y] = std::make_shared<FireCell>(x, y);
        return;
    }

    width = grid.size();
    height = grid[0].size();

    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (inBounds(x + dx, y + dy)) {
                if (grid[x+ dx][y + dy] && grid[x + dx][y + dy]->type == CellType::Fire) {
                    fireResist -= 1;
                }
            }
        }
    }
}
