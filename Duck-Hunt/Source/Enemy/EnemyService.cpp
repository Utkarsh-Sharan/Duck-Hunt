#include "Enemy/EnemyService.h"
#include "Enemy/EnemyController.h"
#include "Enemy/EnemyConfig.h"

#include "Enemy/Controllers/BlackDuckController.h"
#include "Enemy/Controllers/BlueDuckController.h"
#include "Enemy/Controllers/RedDuckController.h"

#include "Global/ServiceLocator.h"

namespace Enemy
{
	using namespace Controller;
	using namespace Global;
	using namespace Gameplay;
	using namespace Player;

	EnemyService::EnemyService()
	{
		std::srand(static_cast<unsigned>(std::time(nullptr)));
	}

	EnemyService::~EnemyService()
	{
		destroy();
	}

	void EnemyService::initialize()
	{
		
	}

	void EnemyService::update()
	{
		//processEnemySpawn();

		for (int i = 0; i < enemy_list.size(); i++)
		{
			enemy_list[i]->update();
		}

		destroyFlaggedEnemies();
	}

	void EnemyService::processEnemySpawn()
	{
		number_of_enemies = ServiceLocator::getInstance()->getWaveService()->getWaveNumber() + 1;

		for (int i = 0; i < number_of_enemies; i++)
		{
			spawnEnemy();
		}
	}

	EnemyController* EnemyService::spawnEnemy()
	{
		EnemyController* enemy_controller = createEnemy(getRandomEnemyType());
		enemy_controller->initialize();

		enemy_list.push_back(enemy_controller);

		return enemy_controller;
	}

	EnemyController* EnemyService::createEnemy(EnemyType enemy_type)
	{
		switch (enemy_type)
		{
		case EnemyType::BLACK:
			return new BlackDuckController(EnemyType::BLACK);

		case EnemyType::BLUE:
			return new BlueDuckController(EnemyType::BLUE);

		case EnemyType::RED:
			return new RedDuckController(EnemyType::RED);
		}
	}

	EnemyType EnemyService::getRandomEnemyType()
	{
		int randomType = std::rand() % 3;

		return static_cast<EnemyType>(randomType);
	}

	void EnemyService::render()
	{
		for (int i = 0; i < enemy_list.size(); i++)
		{
			enemy_list[i]->render();
		}
	}

	void EnemyService::checkEnemyBounds(sf::Vector2f world_position)
	{
		for (int i = 0; i < enemy_list.size(); i++)
		{
			if (enemy_list[i]->getEnemyBounds().contains(world_position))	//checks if mouse is hovering over the enemy bounds
			{
				enemy_type = enemy_list[i]->getEnemyType();
				player_service = ServiceLocator::getInstance()->getPlayerService();

				switch (enemy_type)
				{
				case EnemyType::RED:
					sf::CircleShape radius_red_enemy(200.0f);  //setting radius
					radius_red_enemy.setPosition(world_position.x - radius_red_enemy.getRadius(), world_position.y - radius_red_enemy.getRadius());

					checkEnemyBounds(world_position, radius_red_enemy.getGlobalBounds());

					return;
				}

				//set enemy state as DEAD for that perticular enemy controller
				enemy_list[i]->setEnemyState(EnemyState::DEAD);
				enemies_killed++;

				//increase player score
				player_service->increaseEnemiesKilled(1);
			}
		}
	}

	void EnemyService::checkEnemyBounds(sf::Vector2f world_position, sf::FloatRect radius_bounds)
	{
		for (int i = 0; i < enemy_list.size(); i++)
		{
			if (radius_bounds.intersects(enemy_list[i]->getEnemyBounds()))
			{
				//set all enemies in that radius as DEAD
				enemy_list[i]->setEnemyState(EnemyState::DEAD);
				enemies_killed++;

				//increase player score
				player_service = ServiceLocator::getInstance()->getPlayerService();
				player_service->increaseEnemiesKilled(1);
			}
		}
	}

	bool EnemyService::allEnemiesKilled()
	{
		printf("killed: %d\n Number: %d\n\n", enemies_killed, number_of_enemies);

		if (enemies_killed != number_of_enemies)
			return false;

		return true;
	}

	void EnemyService::destroyEnemy(EnemyController* enemy_controller)
	{
		if (std::find(flagged_enemy_list.begin(), flagged_enemy_list.end(), enemy_controller) == flagged_enemy_list.end())
		{
			flagged_enemy_list.push_back(enemy_controller);
			enemy_list.erase(std::remove(enemy_list.begin(), enemy_list.end(), enemy_controller), enemy_list.end());
		}
	}

	void EnemyService::destroyFlaggedEnemies()
	{
		for (int i = 0; i < flagged_enemy_list.size(); i++)
		{
			delete (flagged_enemy_list[i]);
		}
		flagged_enemy_list.clear();
	}

	void EnemyService::destroy()
	{
		for (int i = 0; i < enemy_list.size(); i++)
		{
			delete(enemy_list[i]);

			enemy_list[i] = nullptr;
		}
		enemy_list.clear();
	}

	void EnemyService::reset()
	{
		enemies_killed = 0;

		destroy();
	}
}