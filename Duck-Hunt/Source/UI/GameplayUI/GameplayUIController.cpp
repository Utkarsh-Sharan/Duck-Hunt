#include "UI/GameplayUI/GameplayUIController.h"

#include "Player/PlayerModel.h"

#include "Global/Config.h"
#include "Global/ServiceLocator.h"

namespace UI
{
	namespace GameplayUI
	{
		using namespace Global;
		using namespace UI::UIElement;
		using namespace Player;

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
			normal_bullets_image = new ImageView();
			radius_bullets_image = new ImageView();
		}

		void GameplayUIController::initialize()
		{
			initializeImage();
		}

		void GameplayUIController::initializeImage()
		{
			player_lives_image->initialize(Config::player_life_texture_path, lives_sprite_width, lives_sprite_height, sf::Vector2f(0, 0));
			normal_bullets_image->initialize(Config::normal_bullet_texture_path, bullets_sprite_width, bullets_sprite_height, sf::Vector2f(0, 0));
			radius_bullets_image->initialize(Config::radius_bullet_texture_path, bullets_sprite_width, bullets_sprite_height, sf::Vector2f(0, 0));
		}

		void GameplayUIController::update()
		{

		}

		void GameplayUIController::render()
		{
			drawPlayerLives();
			drawNormalBullets();
			drawRadiusBullets();
		}

		void GameplayUIController::drawPlayerLives()
		{
			sf::RenderWindow* game_window = Global::ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

			for (int i = 0; i < PlayerModel::player_lives; i++)
			{
				player_lives_image->setPosition(sf::Vector2f(player_lives_x_offset - (i * player_lives_spacing), player_lives_y_offset));
				player_lives_image->render();
			}
		}

		void GameplayUIController::updateEnemiesKilledText()
		{
			sf::String enemies_killed_string = "Enemies Killed  :  " + std::to_string(PlayerModel::enemies_killed);
			enemies_killed_text->setText(enemies_killed_string);
		}

		void GameplayUIController::drawNormalBullets()
		{
			sf::RenderWindow* game_window = Global::ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

			for (int i = 0; i < PlayerModel::player_normal_bullets; i++)
			{
				normal_bullets_image->setPosition(sf::Vector2f(bullets_x_offset + (i * bullets_spacing), normal_bullets_y_offset));
				normal_bullets_image->render();
			}
		}

		void GameplayUIController::drawRadiusBullets()
		{
			sf::RenderWindow* game_window = Global::ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

			for (int i = 0; i < PlayerModel::player_radius_bullets; i++)
			{
				radius_bullets_image->setPosition(sf::Vector2f(bullets_x_offset + (i * bullets_spacing), radius_bullets_y_offset));
				radius_bullets_image->render();
			}
		}

		void GameplayUIController::show()
		{

		}

		void GameplayUIController::destroy()
		{
			delete(player_lives_image);
			delete(normal_bullets_image);
			delete(radius_bullets_image);

			player_lives_image = nullptr;
			normal_bullets_image = nullptr;
			radius_bullets_image = nullptr;
		}
	}
}