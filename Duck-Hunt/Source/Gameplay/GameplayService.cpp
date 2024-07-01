#include "Gameplay/GameplayService.h"
#include "Gameplay/GameplayController.h"

#include "Global/ServiceLocator.h"

namespace Gameplay
{
	GameState GameplayService::current_state = GameState::BOOT;

	using namespace Global;

	GameplayService::GameplayService()
	{
		gameplay_controller = new GameplayController();
	}

	GameplayService::~GameplayService()
	{
		delete(gameplay_controller);

		gameplay_controller = nullptr;
	}

	void GameplayService::initialize()
	{
		gameplay_controller->initialize();
	}

	void GameplayService::update()
	{
		gameplay_controller->update();
	}

	void GameplayService::render()
	{
		gameplay_controller->render();
	}

	GameState GameplayService::getGameState()
	{
		return current_state;
	}

	void GameplayService::setGameState(GameState state)
	{
		current_state = state;
	}

	void GameplayService::restart()
	{
		ServiceLocator::getInstance()->getPlayerService()->reset();
		ServiceLocator::getInstance()->getEnemyService()->reset();
	}
}