#include "AssetManager.h"

AssetManager* AssetManager::getInstance()
{
	static AssetManager instance;
	return &instance;
}

sf::Texture& AssetManager::GetTexture(std::string const& filename)
{
	auto& texMap = getInstance()->m_Textures;
	auto pairFound = texMap.find(filename);

	if (pairFound != texMap.end())
	{
		return pairFound->second;
	}

	sf::Texture texture;
	texture.loadFromFile(filename);
	texMap[filename] = texture;
	return texMap[filename];
}

sf::Font& AssetManager::GetFont(std::string const& filename)
{
	auto& fontMap = getInstance()->m_Fonts;
	auto pairFound = fontMap.find(filename);

	if (pairFound != fontMap.end())
	{
		return pairFound->second;
	}
	
	sf::Font font;
	font.loadFromFile(filename);
	fontMap[filename] = font;
	return fontMap[filename];
}