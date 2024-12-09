#pragma once
#include "Cell.h"

class StoneCell : public Cell {
public:
    StoneCell(int x, int y);
    void update(std::vector<std::vector<std::shared_ptr<Cell>>>& grid) override;
};
