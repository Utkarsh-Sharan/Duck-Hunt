#include "Player/PlayerController.h"

#include "Global/ServiceLocator.h"

namespace Player
{
	using namespace Global;
	using namespace Gameplay;
	using namespace Wave;

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
		wave_service = ServiceLocator::getInstance()->getWaveService();
	}

	void PlayerController::update()
	{

	}

	void PlayerController::processBulletsImage()
	{
		wave_number = wave_service->getWaveNumber();

		PlayerModel::player_normal_bullets = wave_number;
		PlayerModel::player_radius_bullets = 1;
	}

	void PlayerController::decreasePlayerLive()
	{
		PlayerModel::player_lives -= 1;

		if (PlayerModel::player_lives <= 0)
		{
			player_model->setPlayerState(PlayerState::DEAD);
			ServiceLocator::getInstance()->getGameplayService()->restart();
		}
	}

	void PlayerController::decreasePlayerNormalBullets()
	{
		PlayerModel::player_normal_bullets -= 1;
	}

	void PlayerController::decreasePlayerRadiusBullets()
	{
		PlayerModel::player_radius_bullets -= 1;
	}

	void PlayerController::reset()
	{
		player_model->reset();
		player_model->resetAllBullets();
	}
}