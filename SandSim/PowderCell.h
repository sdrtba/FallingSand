#pragma once
#include "Cell.h"

class PowderCell : public Cell {
public:
    PowderCell(int x, int y);
    void update(std::vector<std::vector<std::shared_ptr<Cell>>>& grid) override;
};