#pragma once
#include "Cell.h"

class StoneCell : public Cell {
public:
    StoneCell(size_t x, size_t y);
    void update(std::vector<std::vector<std::shared_ptr<Cell>>>& grid) override;

    bool canSwap(std::vector<std::vector<std::shared_ptr<Cell>>>& grid);
};
