#pragma once

#include "Player/PlayerModel.h"
#include "Wave/WaveService.h"

#include <SFML/Graphics.hpp>

namespace Player
{
	enum class PlayerState;
	class EnemyService;

	class PlayerController
	{
	private:
		PlayerModel* player_model;
		sf::RenderWindow* game_window;
		Wave::WaveService* wave_service;
		Enemy::EnemyService* enemy_service;

		//sf::FloatRect enemy_bounds;

		int wave_number;

		void processPlayerInput();
		void decreasePlayerNormalBullets();
		void decreasePlayerRadiusBullets();
		void shootNormalBullet();
		void shootRadiusBullet();

	public:
		PlayerController();
		~PlayerController();

		void initialize();
		void update();

		void reset();

		void processBulletsImage();

		void decreasePlayerLife();

		inline void increaseEnemiesKilled(int val) { PlayerModel::enemies_killed += val; }
	};
}