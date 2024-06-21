#pragma once

#include "Enemy/EnemyController.h"

namespace Enemy
{
	namespace Controller
	{
		class BlackDuckController : public EnemyController
		{
		private:
			void move() override;

		public:
			BlackDuckController(EnemyType type);
			~BlackDuckController();

			void initialize() override;
		};
	}
}