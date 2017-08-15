#include <SFML/Graphics.hpp>
#include "Game.h"
#include "config.h"


int main()
{
	Game game(constants::GLOBAL_SCREEN_WIDTH, constants::GLOBAL_SCREEN_HEIGHT, true, "resources/space.png");
	
	game.run();
	return 0;
}