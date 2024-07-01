#pragma once

#include "Player/PlayerModel.h"
#include <SFML/Graphics.hpp>

namespace Player
{
	enum class PlayerState;

	class PlayerController
	{
	private:
		PlayerModel* player_model;

	public:
		PlayerController();
		~PlayerController();

		void initialize();
		void update();

		void reset();

		void decreasePlayerLive();
		inline void increaseEnemiesKilled(int val) { PlayerModel::enemies_killed += val; }
	};
}