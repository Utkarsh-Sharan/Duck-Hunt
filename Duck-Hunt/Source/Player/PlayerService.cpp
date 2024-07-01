#include "Player/PlayerService.h"
#include "Global/ServiceLocator.h"
#include "Player/PlayerController.h"

namespace Player
{
	using namespace Global;

	PlayerService::PlayerService()
	{
		player_controller = new PlayerController();
	}

	PlayerService::~PlayerService()
	{
		delete(player_controller);

		player_controller = nullptr;
	}

	void PlayerService::initialize()
	{
		player_controller->initialize();
	}

	void PlayerService::update()
	{
		player_controller->update();
	}

	void PlayerService::increaseEnemiesKilled(int val)
	{
		player_controller->increaseEnemiesKilled(val);	//inline function in the controller
	}

	void PlayerService::reset()
	{
		player_controller->reset();
	}
}