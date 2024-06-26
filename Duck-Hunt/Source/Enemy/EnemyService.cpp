#include "Enemy/EnemyService.h"
#include "Enemy/EnemyController.h"
#include "Enemy/EnemyConfig.h"

#include "Enemy/Controllers/BlackDuckController.h"

#include "Global/ServiceLocator.h"

namespace Enemy
{
	using namespace Controller;
	using namespace Global;
	using namespace Gameplay;

	EnemyService::EnemyService()
	{

	}

	EnemyService::~EnemyService()
	{
		destroy();
	}

	void EnemyService::initialize()
	{
		/*gameplay_service = ServiceLocator::getInstance()->getGameplayService();
		gameplay_service->setGameState(GameState::SPLASH_SCREEN);
		wave_number = 1;*/
	}

	void EnemyService::update()
	{
		processEnemySpawn();

		/*switch (gameplay_service->getGameState())
		{
		case GameState::SPLASH_SCREEN:
			updateWavePauseTimer();
			break;

		case GameState::GAMEPLAY:
			updateWaveTimer();
			break;
		}*/
		
		for (int i = 0; i < enemy_list.size(); i++)
		{
			enemy_list[i]->update();
		}
	}

	/*void EnemyService::updateWavePauseTimer()
	{
		wave_pause_timer += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
		if (wave_pause_timer >= wave_pause)
		{
			wave_pause_timer = 0.0f;
			gameplay_service->setGameState(GameState::GAMEPLAY);
		}
	}*/

	/*void EnemyService::updateWaveTimer()
	{
		wave_timer += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		if (wave_timer >= wave_time)
		{
			wave_timer = 0.0f;
			gameplay_service->setGameState(GameState::SPLASH_SCREEN);
			wave_number++;
		}

		
	}*/

	void EnemyService::processEnemySpawn()
	{
		if (number_of_enemies != ServiceLocator::getInstance()->getWaveService()->getWaveNumber() + 1)
		{
			spawnEnemy();
			number_of_enemies++;
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

		/*wave_timer = 0;
		wave_number = 1;*/
	}
}