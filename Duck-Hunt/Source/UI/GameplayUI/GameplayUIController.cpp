#include "UI/GameplayUI/GameplayUIController.h"

#include "Global/Config.h"
#include "Global/ServiceLocator.h"

namespace UI
{
	namespace GameplayUI
	{
		using namespace Global;
		using namespace UI::UIElement;

		GameplayUIController::GameplayUIController()
		{
			createUIElements();
		}

		GameplayUIController::~GameplayUIController()
		{
			destroy();
		}

		void GameplayUIController::createUIElements()
		{
			player_lives_image = new ImageView();
			bullets_image = new ImageView();
		}

		void GameplayUIController::initialize()
		{
			initializeImage();
		}

		void GameplayUIController::initializeImage()
		{
			player_lives_image->initialize(Config::player_life_texture_path, lives_sprite_width, lives_sprite_height, 35, 35, sf::Vector2f(0, 0));
			bullets_image->initialize(Config::normal_bullet_texture_path, bullets_sprite_width, bullets_sprite_height, 35, 35, sf::Vector2f(0, 0));
			bullets_image->initialize(Config::radius_bullet_texture_path, bullets_sprite_width, bullets_sprite_height, 35, 35, sf::Vector2f(0, 0));
		}

		void GameplayUIController::update()
		{

		}

		void GameplayUIController::render()
		{
			drawPlayerLives();
			drawBullets();
		}

		void GameplayUIController::drawPlayerLives()
		{
			sf::RenderWindow* game_window = Global::ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

			for (int i = 0; i < 3 /*PlayerModel::player_lives*/; i++)
			{
				player_lives_image->setPosition(sf::Vector2f(player_lives_x_offset - (i * player_lives_spacing), player_lives_y_offset));
				player_lives_image->render();
			}
		}

		void GameplayUIController::drawBullets()
		{
			sf::RenderWindow* game_window = Global::ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

			for (int i = 0; i < 3 /*PlayerModel::player_bullets*/; i++)
			{
				bullets_image->setPosition(sf::Vector2f(bullets_x_offset - (i * bullets_spacing), bullets_y_offset));
				bullets_image->render();
			}
		}

		void GameplayUIController::show()
		{

		}

		void GameplayUIController::destroy()
		{
			delete(player_lives_image);
			delete(bullets_image);

			player_lives_image = nullptr;
			bullets_image = nullptr;
		}
	}
}