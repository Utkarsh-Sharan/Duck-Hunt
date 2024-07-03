#include "Player/PlayerController.h"

#include "Enemy/EnemyController.h"
#include "Enemy/EnemyConfig.h"

#include "Global/ServiceLocator.h"

namespace Player
{
	using namespace Global;
	using namespace Gameplay;
	using namespace Wave;
	using namespace Event;
	using namespace Graphic;
	using namespace Enemy;

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

	void PlayerController::processBulletsImage()
	{
		wave_number = wave_service->getWaveNumber();

		PlayerModel::player_normal_bullets = wave_number;
		PlayerModel::player_radius_bullets = 1;
	}

	void PlayerController::update()
	{
		processPlayerInput();
	}

	void PlayerController::processPlayerInput()
	{
		EventService* event_service = ServiceLocator::getInstance()->getEventService();

		if (event_service->pressedLeftMouseButton())
		{
			decreasePlayerNormalBullets();
			shootNormalBullet();
		}

		if (event_service->pressedRightMouseButton())
		{
			decreasePlayerRadiusBullets();
			shootRadiusBullet();
		}
	}

	void PlayerController::decreasePlayerNormalBullets()
	{
		if (PlayerModel::player_normal_bullets <= 0)
		{
			PlayerModel::player_normal_bullets = 0;
			return;
		}
		PlayerModel::player_normal_bullets -= 1;
	}

	void PlayerController::shootNormalBullet()
	{
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

		//for mouse hover
		sf::Vector2i mouse_position = sf::Mouse::getPosition();
		sf::Vector2f world_position = game_window->mapPixelToCoords(mouse_position);

		//printf("xpos: %f, ypos: %f", worldPosition.x, worldPosition.y);
		//getting enemy bounds
		/*enemy_bounds =*/ enemy_service->getEnemyBounds(world_position);

		//if (enemy_bounds.contains(world_position))	//checks if mouse is hovering over the enemy bounds
		//{
		//	//set enemy state as DEAD for that perticular enemy controller
		//	enemy_controller->getInstance()->setEnemyState(EnemyState::DEAD);
		//}
	}

	void PlayerController::decreasePlayerRadiusBullets()
	{
		if (PlayerModel::player_radius_bullets <= 0)
		{
			PlayerModel::player_radius_bullets = 0;
			return;
		}
		PlayerModel::player_radius_bullets -= 1;
	}

	void PlayerController::shootRadiusBullet()
	{

	}

	void PlayerController::decreasePlayerLife()
	{
		PlayerModel::player_lives -= 1;

		if (PlayerModel::player_lives <= 0)
		{
			player_model->setPlayerState(PlayerState::DEAD);
			ServiceLocator::getInstance()->getGameplayService()->restart();
		}
	}

	void PlayerController::reset()
	{
		player_model->reset();
		player_model->resetAllBullets();
	}
}