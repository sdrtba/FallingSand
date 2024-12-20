#include "Game.h"

Game::Game(sf::RenderWindow& window) : window(window) {
    radius = 1;
    scale = 4;
    width = window.getSize().x / scale;
    height = (window.getSize().y - 50) / scale;
    grid.resize(width, std::vector<std::shared_ptr<Cell>>(height, nullptr));
    type = CellType::Empty;
    textureAtlas = AssetManager::GetTexture("image/atlas.png");
    sandRect = sf::IntRect(0, 0, 1, 1);
    waterRect = sf::IntRect(1, 0, 1, 1);
    stoneRect = sf::IntRect(2, 0, 1, 1);
    fireRect = sf::IntRect(3, 0, 1, 1);
    woodRect = sf::IntRect(4, 0, 1, 1);
    powderRect = sf::IntRect(5, 0, 1, 1);
}

bool Game::InBounds(int x, int y) const {
    return x >= 0 && x < width && y >= 0 && y < height;
}

bool Game::IsEmpty(int x, int y) const {
    return InBounds(x, y) && !grid[x][y];
}

void Game::setCell(sf::Vector2i position) {
    int x = std::clamp(position.x / scale, 0, width - 1);
    int y = std::clamp(position.y / scale, 0, height - 1);

    for (int dx = -radius; dx <= radius; dx++) {
        for (int dy = -radius; dy <= radius; dy++) {
            if (dx * dx + dy * dy <= radius * radius) {
                int nx = x + dx;
                int ny = y + dy;
                if (InBounds(nx, ny)) grid[nx][ny] = createCell(nx, ny);
            }
        }
    }
}

std::shared_ptr<Cell> Game::createCell(int x, int y) {
    switch (type) {
    case CellType::Sand:
        return std::make_shared<SandCell>(x, y);
    case CellType::Water:
        return std::make_shared<WaterCell>(x, y);
    case CellType::Stone:
        return std::make_shared<StoneCell>(x, y);
    case CellType::Fire:
        return std::make_shared<FireCell>(x, y);
    case CellType::Wood:
        return std::make_shared<WoodCell>(x, y);
    case CellType::Powder:
        return std::make_shared<PowderCell>(x, y);
    default:
        return nullptr;
    }
}

void Game::setType(CellType newType) {
    type = newType;
}

void Game::updateRadius(int dr) {
    radius += dr;
    if (radius <= 0) radius = 0;
    else if (radius >= 6) radius = 6;
}

void Game::update(sf::Time const& deltaTime) {
    for (auto& col : grid) {
        for (auto& cell : col) {
            if (cell) {
                if (!cell->updated) cell->update(grid);
                else cell->updated = false;
            }
        }
    }
}

void Game::clear() {
    for (auto& col : grid) {
        for (auto& cell : col) {
        cell = nullptr;
        }
    }
}

void Game::draw() {
    sf::Sprite sprite;
    sprite.setTexture(textureAtlas);
    sprite.setScale(scale, scale);
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            if (grid[x][y]) {
                sprite.setTextureRect(getRectForCell(grid[x][y]->type));
                sprite.setPosition(x * scale, y * scale);
                window.draw(sprite);
            }
        }
    }
}

sf::IntRect Game::getRectForCell(CellType cellType) const {
    switch (cellType) {
    case CellType::Sand:
        return sandRect;
    case CellType::Water:
        return waterRect;
    case CellType::Stone:
        return stoneRect;
    case CellType::Fire:
        return fireRect;
    case CellType::Wood:
        return woodRect;
    case CellType::Powder:
        return powderRect;
    }
}