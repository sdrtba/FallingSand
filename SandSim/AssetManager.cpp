#include "AssetManager.h"

AssetManager* AssetManager::sInstance = nullptr;

AssetManager::AssetManager() {
	assert(sInstance == nullptr);
	sInstance = this;
}

sf::Texture& AssetManager::GetTexture(std::string const& filename) {
	auto& texMap = sInstance->m_Textures;

	auto pairFound = texMap.find(filename);

	if (pairFound != texMap.end()) {
		return pairFound->second;
	}
	else {
		auto& texture = texMap[filename];
		texture.loadFromFile(filename);
		return texture;
	}
}

sf::SoundBuffer& AssetManager::GetSoundBuffer(std::string const& filename) {
	auto& soundMap = sInstance->m_SoundBuffer;
	
	auto pairFound = soundMap.find(filename);

	if (pairFound != soundMap.end()) {
		return pairFound->second;
	}
	else {
		auto soundBuffer = soundMap[filename];
		soundBuffer.loadFromFile(filename);
		return soundBuffer;
	}
}

sf::Font& AssetManager::GetFont(std::string const& filename) {
	auto& fontMap = sInstance->m_Fonts;

	auto pairFound = fontMap.find(filename);

	if (pairFound != fontMap.end()) {
		return pairFound->second;
	}
	else {
		auto font = fontMap[filename];
		font.loadFromFile(filename);
		return font;
	}
}