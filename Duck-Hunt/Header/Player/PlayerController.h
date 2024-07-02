#pragma once

#include "Player/PlayerModel.h"
#include "Wave/WaveService.h"

#include <SFML/Graphics.hpp>

namespace Player
{
	enum class PlayerState;

	class PlayerController
	{
	private:
		PlayerModel* player_model;
		Wave::WaveService* wave_service;

		int wave_number;

	public:
		PlayerController();
		~PlayerController();

		void initialize();
		void update();

		void reset();

		void processBulletsImage();

		void decreasePlayerLive();
		void decreasePlayerNormalBullets();
		void decreasePlayerRadiusBullets();

		inline void increaseEnemiesKilled(int val) { PlayerModel::enemies_killed += val; }
	};
}