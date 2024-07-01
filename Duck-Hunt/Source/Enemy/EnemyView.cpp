#include "Enemy/EnemyView.h"
#include "Enemy/EnemyController.h"
#include "Enemy/EnemyConfig.h"

#include "Global/Config.h"

namespace Enemy
{
	using namespace UI::UIElement;
	using namespace Global;

	EnemyView::EnemyView()
	{
		createUIElements();
	}

	EnemyView::~EnemyView()
	{
		destroy();
	}

	void EnemyView::createUIElements()
	{
		enemy_image = new ImageView();
	}

	void EnemyView::initialize(EnemyController* controller)
	{
		enemy_controller = controller;

		initializeImage();
	}

	void EnemyView::initializeImage()
	{
		enemy_image->initialize(getEnemyTexturePath(), enemy_sprite_width, enemy_sprite_height, tile_width, tile_height, enemy_controller->getEnemyPosition());
	}

	sf::String EnemyView::getEnemyTexturePath()
	{
		switch (enemy_controller->getEnemyType())
		{
		case EnemyType::BLACK:
			return Config::black_duck_texture_path;

		case EnemyType::RED:
			return Config::red_duck_texture_path;

		case EnemyType::BLUE:
			return Config::blue_duck_texture_path;
		}
	}

	void EnemyView::update()
	{
		enemy_image->setPosition(enemy_controller->getEnemyPosition());
	}

	void EnemyView::render()
	{
		enemy_image->render();
	}

	void EnemyView::destroy()
	{
		delete(enemy_image);

		enemy_image = nullptr;
	}

	const sf::Sprite& EnemyView::getEnemySprite()
	{
		return enemy_image->getSprite();
	}
}