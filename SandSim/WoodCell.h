#pragma once
#include "Cell.h"

class WoodCell : public Cell {
public:
    WoodCell(size_t x, size_t y);
    void update(std::vector<std::vector<std::shared_ptr<Cell>>>& grid) override;
};
