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

		if (event_service->pressedLeftMouseButton() && PlayerModel::player_normal_bullets > 0)
		{
			decreasePlayerNormalBullets();
			shootNormalBullet();
		}

		if (event_service->pressedRightMouseButton() && PlayerModel::player_radius_bullets > 0)
		{
			decreasePlayerRadiusBullets();
			shootRadiusBullet();
		}
	}

	void PlayerController::decreasePlayerNormalBullets()
	{
		PlayerModel::player_normal_bullets -= 1;
	}

	void PlayerController::shootNormalBullet()
	{
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

		//for mouse hover
		sf::Vector2i mouse_position = sf::Mouse::getPosition(*game_window);
		sf::Vector2f world_position = game_window->mapPixelToCoords(mouse_position);
		
		//getting enemy bounds
		enemy_service =  ServiceLocator::getInstance()->getEnemyService();
		enemy_service->checkEnemyBounds(world_position);
	}

	void PlayerController::decreasePlayerRadiusBullets()
	{
		PlayerModel::player_radius_bullets -= 1;
	}

	void PlayerController::shootRadiusBullet()
	{
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

		//for mouse hover
		sf::Vector2i mouse_position = sf::Mouse::getPosition(*game_window);
		sf::Vector2f world_position = game_window->mapPixelToCoords(mouse_position);

		sf::CircleShape radius_bullet(120.0f);  //setting radius
		radius_bullet.setPosition(world_position.x - radius_bullet.getRadius(), world_position.y - radius_bullet.getRadius());

		enemy_service = ServiceLocator::getInstance()->getEnemyService();
		enemy_service->checkEnemyBounds(world_position, radius_bullet.getGlobalBounds());
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