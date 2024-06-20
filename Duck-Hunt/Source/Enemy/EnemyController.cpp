#include "Enemy/EnemyController.h"
#include "Enemy/EnemyModel.h"
#include "Enemy/EnemyView.h"

#include "Global/ServiceLocator.h"

namespace Enemy
{
	using namespace Global;

	EnemyController::EnemyController(EnemyType type)
	{
		enemy_model = new EnemyModel(type);
		enemy_view = new EnemyView();
	}

	EnemyController::~EnemyController()
	{
		delete(enemy_model);
		delete(enemy_view);

		enemy_model = nullptr;
		enemy_view = nullptr;
	}

	void EnemyController::initialize()
	{
		enemy_model->initialize();
		enemy_model->setEnemyPosition(getRandomInitialPosition());

		enemy_view->initialize(this);
	}

	sf::Vector2f EnemyController::getRandomInitialPosition()
	{
		float x_offset_distance = (std::rand() % static_cast<int>(enemy_model->right_most_position.x - enemy_model->left_most_position.x));

		float x_position = enemy_model->left_most_position.x + x_offset_distance;

		float y_position = enemy_model->left_most_position.y;

		return sf::Vector2f(x_position, y_position);
	}

	void EnemyController::update()
	{
		move();

		enemy_view->update();
	}

	void EnemyController::render()
	{
		enemy_view->render();
	}

	sf::Vector2f EnemyController::getEnemyPosition()
	{
		return enemy_model->getEnemyPosition();
	}

	EnemyState EnemyController::getEnemyState()
	{
		return enemy_model->getEnemyState();
	}

	EnemyType EnemyController::getEnemyType()
	{
		return enemy_model->getEnemyType();
	}

	void EnemyController::destroy()
	{
		ServiceLocator::getInstance()->getEnemyService()->destroyEnemy(this);
	}
}