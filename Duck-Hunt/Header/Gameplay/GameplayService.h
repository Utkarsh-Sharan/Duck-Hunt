#pragma once

#include <SFML/Graphics.hpp>

namespace Gameplay
{
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

	public:
		GameplayService();
		~GameplayService();

		void initialize();
		void update();
		void render();

		static GameState getGameState();
		static void setGameState(GameState state);
	};
}