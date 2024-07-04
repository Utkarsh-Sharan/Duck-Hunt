#pragma once

#include "Global/ServiceLocator.h"
#include "Gameplay/GameplayService.h"

#include <SFML/Graphics.hpp>

namespace Main
{
	/*enum class GameState
	{
		BOOT,
		SPLASH_SCREEN,
		GAMEPLAY,
	};*/

	class GameService
	{
	private:
		//static GameState current_state;

		Global::ServiceLocator* service_locator;

		sf::RenderWindow* game_window;

		void initialize();
		void initializeVariables();
		void destroy();

		//void showSplashScreen();

	public:
		GameService();
		~GameService();

		void ignite();
		void update();
		void render();

		bool isRunning();

		//static void setGameState(GameState state);
		//static GameState getGameState();
	};
}