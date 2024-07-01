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

		//ServiceLocator::getInstance()->getCollisionService()->addCollider(dynamic_cast<ICollider*>(enemy_controller));
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

	void EnemyService::destroyEnemy(EnemyController* enemy_controller)
	{

	}

	void EnemyService::destroyFlaggedEnemies()
	{

	}

	void EnemyService::destroy()
	{
		for (int i = 0; i < enemy_list.size(); i++)
		{
			//ServiceLocator::getInstance()->getCollisionService()->removeCollider(dynamic_cast<ICollider*>(enemy_list[i]));
			delete(enemy_list[i]);

			enemy_list[i] = nullptr;
		}
		enemy_list.clear();
	}

	void EnemyService::reset()
	{
		destroy();
	}
}