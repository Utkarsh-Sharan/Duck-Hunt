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

			if (!enemy_model->has_reached_top)
			{
				if (current_position.y <= enemy_model->top_most_position.y)
				{
					enemy_model->has_reached_bottom = false;
					enemy_model->has_reached_top = true;

					return;
				}

				current_position.x -= enemy_model->enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
				current_position.y -= enemy_model->enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

				enemy_model->setEnemyPosition(current_position);
			}

			else if (!enemy_model->has_reached_bottom)
			{
				if (current_position.y >= enemy_model->bottom_most_position.y)
				{
					enemy_model->has_reached_bottom = true;
					enemy_model->has_reached_top = false;

					return;
				}

				current_position.x -= enemy_model->enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
				current_position.y += enemy_model->enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

				enemy_model->setEnemyPosition(current_position);
			}

			if (current_position.x <= enemy_model->left_most_position.x)
			{
				enemy_model->setEnemyPosition(current_position);

				movement_direction = MovementDirection::RIGHT_DIAGONAL;
			}
		}

		void BlackDuckController::moveRightDiagonal()
		{
			sf::Vector2f current_position = enemy_model->getEnemyPosition();

			if (!enemy_model->has_reached_top)
			{
				if (current_position.y <= enemy_model->top_most_position.y)
				{
					enemy_model->has_reached_bottom = false;
					enemy_model->has_reached_top = true;

					return;
				}

				current_position.x += enemy_model->enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
				current_position.y -= enemy_model->enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

				enemy_model->setEnemyPosition(current_position);
			}

			else if (!enemy_model->has_reached_bottom)
			{
				if (current_position.y >= enemy_model->bottom_most_position.y)
				{
					enemy_model->has_reached_bottom = true;
					enemy_model->has_reached_top = false;

					return;
				}

				current_position.x += enemy_model->enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
				current_position.y += enemy_model->enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

				enemy_model->setEnemyPosition(current_position);
			}

			if (current_position.x >= enemy_model->right_most_position.x)
			{
				enemy_model->setEnemyPosition(current_position);

				movement_direction = MovementDirection::LEFT_DIAGONAL;
			}
		}
	}
}