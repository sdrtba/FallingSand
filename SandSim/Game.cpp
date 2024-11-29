#include "game.h"

Game::Game(sf::RenderWindow& window) : window(window) {
    scale = 4;
    width = window.getSize().x / scale;
    height = (window.getSize().y - 50) / scale;
    grid.resize(height, std::vector<std::shared_ptr<Cell>>(width, nullptr));
    type = CellType::Sand;
}

bool Game::InBounds(int x, int y) {
    return x >= 0 && x < width && y >= 0 && y < height;
}

bool Game::IsEmpty(int x, int y) {
    //return InBounds(x, y) && grid[x][y]->type == CellType::Empty;
    return grid[x][y]->type == CellType::Empty;
}

bool Game::IsUpdatableCell(int x, int y) {
    return grid[y][x] && !(grid[y][x]->type == CellType::Stone || grid[y][x]->type == CellType::Empty);
}

void Game::setCell(sf::Vector2i position) {
    int x = position.x / scale;
    int y = position.y / scale;
    if (x >= width) { x = width - 1; }
    else if (x < 0) { x = 0; }
    if (y >= height) { y = height - 1; }
    else if (y < 0) { y = 0; }

    for (int dx = -radius; dx <= radius; dx++) {
        for (int dy = -radius; dy <= radius; dy++) {
            if (dx * dx + dy * dy <= radius * radius) {
                if (InBounds(x + dx, y + dy)) {
                    if (grid[y + dy][x + dx] == nullptr || type == CellType::Empty) {
                        switch (type) {
                        case CellType::Sand:
                            grid[y + dy][x + dx] = std::make_shared<SandCell>(x + dx, y + dy);
                            break;
                        case CellType::Water:
                            grid[y + dy][x + dx] = std::make_shared<WaterCell>(x + dx, y + dy);
                            break;
                        case CellType::Stone:
                            grid[y + dy][x + dx] = std::make_shared<StoneCell>(x + dx, y + dy);
                            break;
                        case CellType::Empty:
                            grid[y + dy][x + dx] = nullptr;
                            break;
                        default:
                            break;
                        }
                    }
                }
            }
        }
    }
}

void Game::setType(CellType newType) {
    type = newType;
}

void Game::updateRadius(int dr) {
    radius += dr;
    if (radius <= 0) radius = 0;
    else if (radius >= 3) radius = 3;
}

void Game::update(sf::Time const& deltaTime) {
    for (int y = height - 1; y >= 0; y--) {
        for (int x = 0; x < width; x++) {
            // IsUpdatableCell(x, y) && !grid[y][x]->updated;
            if (IsUpdatableCell(x, y) ) {
                grid[y][x]->update(grid);
            }
        }
    }
    /*for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (grid[y][x]) {
                grid[y][x]->updated = false;
            }
        }
    }*/
}

void Game::draw() {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (grid[y][x]) {
                sf::RectangleShape cellShape(sf::Vector2f(scale, scale));
                cellShape.setPosition(x * scale, y * scale);
                switch (grid[y][x]->type) {
                case CellType::Sand:
                    cellShape.setFillColor(sf::Color::Yellow);
                    break;
                case CellType::Water:
                    cellShape.setFillColor(sf::Color::Blue);
                    break;
                case CellType::Stone:
                    cellShape.setFillColor(sf::Color::White);
                    break;
                default:
                    break;
                }
                window.draw(cellShape);
            }
        }
    }
}