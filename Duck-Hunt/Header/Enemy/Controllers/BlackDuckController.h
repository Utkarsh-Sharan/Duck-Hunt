#pragma once

#include "Enemy/EnemyController.h"
#include "Enemy/EnemyConfig.h"

namespace Enemy
{
	namespace Controller
	{
		class BlackDuckController : public EnemyController
		{
		private:
			MovementDirection movement_direction;

			void move() override;
			void moveLeftDiagonal();
			void moveRightDiagonal();

		public:
			BlackDuckController(EnemyType type);
			~BlackDuckController();

			void initialize() override;
		};
	}
}