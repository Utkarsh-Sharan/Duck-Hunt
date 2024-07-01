#pragma once

#include "Enemy/EnemyController.h"
#include "Enemy/EnemyConfig.h"

namespace Enemy
{
	namespace Controller
	{
		class BlueDuckController : public EnemyController
		{
		private:
			MovementDirection movement_direction;

			void move() override;
			void moveLeftDiagonal();
			void moveRightDiagonal();

		public:
			BlueDuckController(EnemyType type);
			~BlueDuckController();

			void initialize() override;
		};
	}
}