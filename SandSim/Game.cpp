#include "game.h"

Game::Game(sf::RenderWindow& window) : window(window) {
    scale = 4;
    width = window.getSize().x / scale;
    height = (window.getSize().y - 50) / scale;
    grid.resize(width, std::vector<std::shared_ptr<Cell>>(height, nullptr));
    type = CellType::Empty;
    
    textureAtlas = AssetManager::GetTexture("image/atlas.png");
    sandRect = sf::IntRect(0, 0, 1, 1);
    waterRect = sf::IntRect(1, 0, 1, 1);
    stoneRect = sf::IntRect(2, 0, 1, 1);
}

bool Game::InBounds(int x, int y) {
    return x >= 0 && x < width && y >= 0 && y < height;
}

bool Game::IsEmpty(int x, int y) {
    return InBounds(x, y) && !grid[x][y];
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
                    if (grid[x + dx][y + dy] == nullptr || type == CellType::Empty) {
                        switch (type) {
                        case CellType::Sand:
                            grid[x + dx][y + dy] = std::make_shared<SandCell>(x + dx, y + dy);
                            break;
                        case CellType::Water:
                            grid[x + dx][y + dy] = std::make_shared<WaterCell>(x + dx, y + dy);
                            break;
                        case CellType::Stone:
                            grid[x + dx][y + dy] = std::make_shared<StoneCell>(x + dx, y + dy);
                            break;
                        case CellType::Empty:
                            grid[x + dx][y + dy] = nullptr;
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
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            if (grid[x][y] && !grid[x][y]->updated) {
                grid[x][y]->update(grid);
            }
        }
    }

    for (auto& col : grid) {
        for (auto& cell : col) {
            if (cell) cell->updated = false;
        }
    }
}

void Game::draw() {
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            if (grid[x][y]) {
                sf::Sprite sprite;
                sprite.setTexture(textureAtlas);
                sprite.setScale(scale, scale);
                switch (grid[x][y]->type) {
                case CellType::Sand:
                    sprite.setTextureRect(sandRect);
                    break;
                case CellType::Water:
                    sprite.setTextureRect(waterRect);
                    break;
                case CellType::Stone:
                    sprite.setTextureRect(stoneRect);
                    break;
                default:
                    break;
                }
                sprite.setPosition(x * scale, y * scale);
                window.draw(sprite);
            }
        }
    }
}