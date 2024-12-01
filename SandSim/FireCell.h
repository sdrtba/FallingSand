#pragma once
#include "Cell.h"

class FireCell : public Cell {
public:
    FireCell(size_t x, size_t y);
    void update(std::vector<std::vector<std::shared_ptr<Cell>>>& grid) override;
};
