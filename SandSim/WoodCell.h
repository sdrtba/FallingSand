#pragma once
#include "Cell.h"

class WoodCell : public Cell {
public:
    WoodCell(int x, int y);
    void update(std::vector<std::vector<std::shared_ptr<Cell>>>& grid) override;
};
