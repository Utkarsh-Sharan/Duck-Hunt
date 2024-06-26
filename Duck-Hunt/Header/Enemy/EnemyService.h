#pragma once

#include "Gameplay/GameplayService.h"

#include <SFML/Graphics.hpp>
#include <vector>

namespace Enemy
{
	class EnemyController;
	enum class EnemyType;

	class EnemyService
	{
	private:
		/*const float wave_time = 10.0f;
		const float wave_pause = 4.0f;

		float wave_timer;
		float wave_pause_timer;
		float wave_number;*/
		float number_of_enemies;

		//Gameplay::GameplayService* gameplay_service;

		std::vector<EnemyController*> enemy_list;
		std::vector<EnemyController*> flagged_enemy_list;

		EnemyType getRandomEnemyType();
		EnemyController* createEnemy(EnemyType enemy_type);

		//void updateWaveTimer();
		//void updateWavePauseTimer();
		void processEnemySpawn();

		void destroyFlaggedEnemies();
		void destroy();

	public:
		EnemyService();
		virtual ~EnemyService();

		void initialize();
		void update();
		void render();

		void reset();

		EnemyController* spawnEnemy();
		void destroyEnemy(EnemyController* enemy_controller);
	};
}