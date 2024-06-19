#include "Enemy/EnemyService.h"

namespace Enemy
{
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

	EnemyType EnemyService::getRandomEnemyType()
	{
		return EnemyType();
	}

	EnemyController* EnemyService::createEnemy(EnemyType enemy_type)
	{
		return nullptr;
	}

	void EnemyService::updateWaveTimer()
	{

	}

	void EnemyService::processEnemySpawn()
	{

	}

	void EnemyService::destroyFlaggedEnemies()
	{

	}

	void EnemyService::destroy()
	{

	}

	void EnemyService::update()
	{

	}

	void EnemyService::render()
	{

	}

	EnemyController* EnemyService::spawnEnemy()
	{
		return nullptr;
	}

	void EnemyService::destroyEnemy(EnemyController* enemy_controller)
	{

	}

	void EnemyService::reset()
	{

	}
}