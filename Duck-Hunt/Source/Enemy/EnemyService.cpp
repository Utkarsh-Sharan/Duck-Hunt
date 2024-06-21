#include "Enemy/EnemyService.h"
#include "Enemy/EnemyController.h"
#include "Enemy/EnemyConfig.h"

#include "Enemy/Controllers/BlackDuckController.h"

#include "Global/ServiceLocator.h"

namespace Enemy
{
	using namespace Controller;
	using namespace Global;

	EnemyService::EnemyService()
	{

	}

	EnemyService::~EnemyService()
	{
		destroy();
	}

	void EnemyService::initialize()
	{
		wave_number = 1;
	}

	void EnemyService::update()
	{
		updateWavePauseTimer();

		if (wave_pause_timer >= wave_pause)
		{
			for (int i = 0; i < wave_number + 1; i++)
			{
				processEnemySpawn();
			}

			wave_pause_timer = 0.0f;
		}

		for (int i = 0; i < enemy_list.size(); i++)
		{
			enemy_list[i]->update();
		}
	}

	void EnemyService::updateWavePauseTimer()
	{
		wave_pause_timer += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
	}

	void EnemyService::updateWaveTimer()
	{
		wave_timer += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
	}

	void EnemyService::processEnemySpawn()
	{
		if (wave_timer <= wave_time)
		{
			spawnEnemy();
			wave_timer = 0;
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
		}
	}

	EnemyType EnemyService::getRandomEnemyType()
	{
		int randomType = std::rand() % 1;

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

	}

	void EnemyService::reset()
	{
		destroy();

		wave_timer = 0;
		wave_number = 1;
	}
}