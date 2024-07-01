#pragma once

#include "UI/GameplayUI/GameplayUIController.h"

#include <SFML/Graphics.hpp>

namespace Player
{
	enum class PlayerState
	{
		ALIVE,
		DEAD
	};

	class PlayerModel
	{
	private:
		friend class PlayerController;

		friend void UI::GameplayUI::GameplayUIController::updateEnemiesKilledText();
		friend void UI::GameplayUI::GameplayUIController::drawPlayerLives();
		friend void UI::GameplayUI::GameplayUIController::drawNormalBullets();
		friend void UI::GameplayUI::GameplayUIController::drawRadiusBullets();

		const int max_player_lives = 3;

		PlayerState player_state;

		int player_score;

		static int player_lives;
		static int enemies_killed;
		static int player_normal_bullets;
		static int player_radius_bullets;

	public:
		PlayerModel();
		~PlayerModel();

		void initialize();
		void reset();

		int getPlayerScore();
		void setPlayerScore(int score);

		PlayerState getPlayerState();
		void setPlayerState(PlayerState state);
	};
}