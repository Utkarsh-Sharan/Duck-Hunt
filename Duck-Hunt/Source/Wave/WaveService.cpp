#include "Wave/WaveService.h"
#include "Global/ServiceLocator.h"

namespace Wave
{
	using namespace Global;
	using namespace Gameplay;

	WaveService::WaveService()
	{

	}

	WaveService::~WaveService()
	{

	}

	void WaveService::initialize()
	{
		gameplay_service = ServiceLocator::getInstance()->getGameplayService();
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
		}
	}

	void WaveService::updateWaveTimer()
	{
		wave_timer += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		if (wave_timer >= wave_time)
		{
			wave_timer = 0.0f;
			gameplay_service->setGameState(GameState::SPLASH_SCREEN);
			wave_number++;
		}
	}

	int WaveService::getWaveNumber()
	{
		return wave_number;
	}
}