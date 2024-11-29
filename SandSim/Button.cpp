#include "Button.h"

Button::Button(sf::Vector2f location, const sf::Texture& normal, const sf::Texture& clicked) {
	this->normal.setTexture(normal);
	this->clicked.setTexture(clicked);
	this->normal.setPosition(location);
	this->clicked.setPosition(location);
	currentSprite = &this->normal;
}

bool Button::checkClick(sf::Vector2i mousePos) {
	if (mousePos.x >= 0) {
		if ((static_cast<float>(mousePos.x) > currentSprite->getPosition().x &&
			static_cast<float>(mousePos.x) < (currentSprite->getPosition().x + currentSprite->getGlobalBounds().width))
			&& (static_cast<float>(mousePos.y) > currentSprite->getPosition().y &&
				static_cast<float>(mousePos.y) < (currentSprite->getPosition().y + currentSprite->getGlobalBounds().height)))
		{
			setState(!isClicked);
			return true;
		}
		else {
			if (isClicked) {
				setState(!isClicked);
				return false;
			}
		}
	}
	return false;
}

void Button::setState(bool state) {
	isClicked = state;
	if (isClicked) {
		currentSprite = &clicked;
		return;
	}
	currentSprite = &normal;
}

sf::Sprite* Button::getSprite() {
	return currentSprite;
}