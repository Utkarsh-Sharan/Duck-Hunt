#pragma once

#include <SFML/Graphics.hpp>

namespace Gameplay
{
	class GameplayController;

	enum class GameState
	{
		BOOT,
		SPLASH_SCREEN,
		GAMEPLAY,
	};

	class GameplayService
	{
	private:
		static GameState current_state;
		GameplayController* gameplay_controller;

	public:
		GameplayService();
		~GameplayService();

		void initialize();
		void update();
		void render();

		void restart();

		static GameState getGameState();
		static void setGameState(GameState state);
	};
}