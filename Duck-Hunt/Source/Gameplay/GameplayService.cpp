#include "Gameplay/GameplayService.h"

namespace Gameplay
{
	GameplayService::GameplayService()
	{

	}

	GameplayService::~GameplayService()
	{

	}

	void GameplayService::initialize()
	{
		current_state = GameState::BOOT;
	}

	void GameplayService::update()
	{

	}

	void GameplayService::render()
	{

	}

	GameState GameplayService::getGameState()
	{
		return current_state;
	}

	void GameplayService::setGameState(GameState state)
	{
		current_state = state;
	}
}