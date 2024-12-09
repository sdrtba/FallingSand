#pragma once
#include "Cell.h"

class SandCell : public Cell {
public:
    SandCell(int x, int y);
    void update(std::vector<std::vector<std::shared_ptr<Cell>>>& grid) override;
};
