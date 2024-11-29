#include "GameEngine.h"

int main() {
	auto myGame = std::make_unique<GameEngine>();

	myGame->run();

	return 0;
}