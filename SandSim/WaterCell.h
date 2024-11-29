#pragma once
#include "Cell.h"

class WaterCell : public Cell {
public:
    WaterCell(size_t x, size_t y);
    void update(std::vector<std::vector<std::shared_ptr<Cell>>>& grid) override;
};
