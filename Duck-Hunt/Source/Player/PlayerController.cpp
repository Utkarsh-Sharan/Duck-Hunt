#include "Player/PlayerController.h"
#include "Player/PlayerModel.h"

#include "Global/ServiceLocator.h"

namespace Player
{
	using namespace Global;

	PlayerController::PlayerController()
	{
		player_model = new PlayerModel();
	}

	PlayerController::~PlayerController()
	{
		delete(player_model);

		player_model = nullptr;
	}

	void PlayerController::initialize()
	{
		player_model->initialize();
	}

	void PlayerController::update()
	{

	}

	void PlayerController::decreasePlayerLive()
	{
		PlayerModel::player_lives -= 1;

		if (PlayerModel::player_lives <= 0)
		{
			player_model->setPlayerState(PlayerState::DEAD);
			//ServiceLocator::getInstance()->getGameplayService()->restart();
		}
	}

	void PlayerController::reset()
	{
		player_model->reset();
	}
}