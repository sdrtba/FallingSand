#pragma once
#include "Cell.h"

class FireCell : public Cell {
public:
    FireCell(int x, int y);
    void update(std::vector<std::vector<std::shared_ptr<Cell>>>& grid) override;
};
