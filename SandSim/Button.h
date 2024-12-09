#pragma once
#include <SFML\Graphics.hpp>
#include "Cell.h"


class Button {
public:
	Button(sf::Vector2f location, const CellType type, const sf::Texture& normal, const sf::Texture& clicked);
	bool checkClick(sf::Vector2i mousePos = sf::Vector2i(-1, -1)) const;
	sf::Sprite* getSprite() const;
	CellType getCellType() const;
	void setState(bool);
private:
	sf::FloatRect bounds;
	sf::Sprite normal;
	sf::Sprite clicked;
	sf::Sprite* currentSprite;
	CellType cellType;
	bool isClicked = false;
};