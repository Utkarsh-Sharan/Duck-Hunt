#include "Wave/WaveService.h"
#include "Global/ServiceLocator.h"

namespace Wave
{
	using namespace Global;
	using namespace Gameplay;
	using namespace Enemy;
	using namespace Player;

	WaveService::WaveService()
	{

	}

	WaveService::~WaveService()
	{

	}

	void WaveService::initialize()
	{
		enemy_service = ServiceLocator::getInstance()->getEnemyService();
		gameplay_service = ServiceLocator::getInstance()->getGameplayService();
		player_service = ServiceLocator::getInstance()->getPlayerService();
		
		gameplay_service->setGameState(GameState::SPLASH_SCREEN);
		wave_number = 1;
	}

	void WaveService::update()
	{
		switch (gameplay_service->getGameState())
		{
		case GameState::SPLASH_SCREEN:
			updateWavePauseTimer();
			break;

		case GameState::GAMEPLAY:
			updateWaveTimer();
			break;
		}
	}

	void WaveService::updateWavePauseTimer()
	{
		wave_pause_timer += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
		if (wave_pause_timer >= wave_pause)
		{
			wave_pause_timer = 0.0f;
			gameplay_service->setGameState(GameState::GAMEPLAY);
			enemy_service->processEnemySpawn();
			player_service->processBulletsImage();
		}
	}

	void WaveService::updateWaveTimer()
	{
		wave_timer += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		if (wave_timer >= wave_time)
		{
			wave_timer = 0.0f;

			if (enemy_service->allEnemiesKilled())	//if all enemies of that wave are DEAD, then only get to next wave
				wave_number++;
			else
				player_service->decreasePlayerLife();

			enemy_service->reset();
			gameplay_service->setGameState(GameState::SPLASH_SCREEN);
		}
	}

	int WaveService::getWaveNumber()
	{
		return wave_number;
	}

	void WaveService::reset()
	{
		wave_number = 1;
	}
}