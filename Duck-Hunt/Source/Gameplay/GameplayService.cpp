#include "Gameplay/GameplayService.h"

namespace Gameplay
{
	GameState GameplayService::current_state = GameState::BOOT;

	GameplayService::GameplayService()
	{

	}

	GameplayService::~GameplayService()
	{

	}

	void GameplayService::initialize()
	{
		
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