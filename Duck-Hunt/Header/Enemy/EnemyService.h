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
		int number_of_enemies = 0;

		std::vector<EnemyController*> enemy_list;
		std::vector<EnemyController*> flagged_enemy_list;

		EnemyType getRandomEnemyType();
		EnemyController* createEnemy(EnemyType enemy_type);

		void destroyFlaggedEnemies();
		void destroy();

	public:
		EnemyService();
		virtual ~EnemyService();

		void initialize();
		void update();
		void render();

		void processEnemySpawn();

		void reset();

		EnemyController* spawnEnemy();
		void destroyEnemy(EnemyController* enemy_controller);

		void checkEnemyBounds(sf::Vector2f world_position);
	};
}