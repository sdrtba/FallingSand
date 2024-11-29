#pragma once
#include <array>
#include <SFML\Audio.hpp>
#include "AssetManager.h"

class GameSound {
private:
	static const int sCount = 1;
	std::array<sf::Sound, sCount> GSound;
public:
	GameSound() {
		std::array<std::string, sCount> namefilebuf{ "sound/back.ogg" };
		for (int i = 0; i < sCount; i++) {
			GSound[i].setBuffer(AssetManager::GetSoundBuffer(namefilebuf[i]));
		}
		GSound[0].setLoop(true);
	};

	void play(int index);
	void stop(int index);
	void AllStop();
};