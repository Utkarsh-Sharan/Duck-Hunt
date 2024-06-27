#include "Enemy/Controllers/BlackDuckController.h"
#include "Enemy/EnemyModel.h"

#include "Global/ServiceLocator.h"

namespace Enemy
{
	namespace Controller
	{
		using namespace Global;

		BlackDuckController::BlackDuckController(EnemyType type) : EnemyController(type)
		{
			
		}

		BlackDuckController::~BlackDuckController()
		{

		}

		void BlackDuckController::initialize()
		{
			EnemyController::initialize();

			movement_direction = enemy_model->getMovementDirection();
		}

		void BlackDuckController::move()
		{
			switch (movement_direction)
			{
			case MovementDirection::LEFT_DIAGONAL:
				moveLeftDiagonal();
				break;

			case MovementDirection::RIGHT_DIAGONAL:
				moveRightDiagonal();
				break;
			}
		}

		void BlackDuckController::moveLeftDiagonal()
		{
			sf::Vector2f current_position = enemy_model->getEnemyPosition();

			current_position.x -= enemy_model->enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
			current_position.y += enemy_model->enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			enemy_model->setEnemyPosition(current_position);
		}

		void BlackDuckController::moveRightDiagonal()
		{
			sf::Vector2f current_position = enemy_model->getEnemyPosition();

			current_position.x += enemy_model->enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
			current_position.y += enemy_model->enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			enemy_model->setEnemyPosition(current_position);
		}
	}
}