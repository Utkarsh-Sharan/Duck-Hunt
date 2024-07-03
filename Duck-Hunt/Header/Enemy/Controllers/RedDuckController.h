#pragma once

#include "Enemy/EnemyController.h"
#include "Enemy/EnemyConfig.h"

namespace Enemy
{
	namespace Controller
	{
		class RedDuckController : public EnemyController
		{
		private:
			MovementDirection movement_direction;

			void move() override;
			void moveLeftDiagonal();
			void moveRightDiagonal();
			void moveDown();

		public:
			RedDuckController(EnemyType type);
			~RedDuckController();

			void initialize() override;
		};
	}
}