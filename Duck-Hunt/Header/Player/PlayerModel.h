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
	};
}