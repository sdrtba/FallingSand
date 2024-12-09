#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>

class AssetManager {
public:
	AssetManager() = default;

	static sf::Texture& GetTexture(std::string const& filename);
	static sf::Font& GetFont(std::string const& filename);
private:
	static AssetManager* getInstance();

	std::unordered_map<std::string, sf::Texture> m_Textures;
	std::unordered_map<std::string, sf::Font> m_Fonts;
};
