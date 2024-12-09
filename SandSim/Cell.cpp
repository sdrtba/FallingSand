#include "Cell.h"

Cell::Cell(int x, int y, CellType type) : x(x), y(y), type(type) {}

bool Cell::inBounds(int nx, int ny, int width, int height) {
    return nx >= 0 && nx < width && ny >= 0 && ny < height;
}