#include "Enemy/EnemyView.h"
#include "Enemy/EnemyController.h"

namespace Enemy
{
	using namespace UI::UIElement;

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
		enemy_image->initialize(getEnemyTexturePath(), enemy_sprite_width, enemy_sprite_height, enemy_controller->getEnemyPosition());
	}

	sf::String EnemyView::getEnemyTexturePath()
	{
		return "assets/textures/Ducks.png";
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