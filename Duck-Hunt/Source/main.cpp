#include "Main/GameService.h"

//#include <SFML/Graphics.hpp>
using namespace Main;

int main()
{
	GameService* game_service = new GameService();
	game_service->ignite();

	while (game_service->isRunning())
	{
		game_service->update();
		game_service->render();
	}

	return 0;
}