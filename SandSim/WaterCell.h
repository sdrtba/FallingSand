#pragma once
#include "Cell.h"

class WaterCell : public Cell {
public:
    WaterCell(int x, int y);
    void update(std::vector<std::vector<std::shared_ptr<Cell>>>& grid) override;
};
