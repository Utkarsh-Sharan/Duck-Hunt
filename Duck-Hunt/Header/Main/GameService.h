#pragma once

#include "Global/ServiceLocator.h"
#include <SFML/Graphics.hpp>

namespace Main
{
	enum class GameState
	{
		BOOT,
		MAIN_MENU,
		GAMEPLAY,
	};

	class GameService
	{
	private:
		static GameState current_state;

		Global::ServiceLocator* service_locator;
		sf::RenderWindow* game_window;

		void initialize();
		void initializeVariables();
		void destroy();

		void showMainMenu();

	public:
		GameService();
		~GameService();

		void ignite();
		void update();
		void render();

		bool isRunning();

		static void setGameState(GameState state);
		static GameState getGameState();
	};
}