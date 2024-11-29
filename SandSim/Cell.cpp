#include "Cell.h"

Cell::Cell(size_t x, size_t y, CellType type) : x(x), y(y), type(type) {}

bool Cell::isEmpty(size_t nx, size_t ny, size_t width, size_t height) {
    return nx >= 0 && nx < width && ny >= 0 && ny < height;
}

bool Cell::moveRight() {
    return rand() % 2;
}
