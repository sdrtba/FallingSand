#include "Button.h"

Button::Button(sf::Vector2f location, const CellType type, const sf::Texture& normal, const sf::Texture& clicked)
	: normal(normal), clicked(clicked), cellType(type), currentSprite(&this->normal) {
	this->normal.setPosition(location);
	this->clicked.setPosition(location);
	bounds = currentSprite->getGlobalBounds();
}


bool Button::checkClick(sf::Vector2i mousePos) const {
	return bounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
}

void Button::setState(bool state) {
	isClicked = state;
	currentSprite = isClicked ? &clicked : &normal;
}


sf::Sprite* Button::getSprite() const {
	return currentSprite;
}

CellType Button::getCellType() const { 
	return cellType; 
}