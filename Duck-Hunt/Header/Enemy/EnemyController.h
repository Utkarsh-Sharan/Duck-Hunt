#pragma once

#include <SFML/Graphics.hpp>

namespace Enemy
{
	class EnemyModel;
	class EnemyView;

	enum class EnemyType;
	enum class EnemyState;

	class EnemyController
	{
	protected:
		EnemyModel* enemy_model;
		EnemyView* enemy_view;

		virtual void move() = 0;

		sf::Vector2f getRandomInitialPosition();

		virtual void destroy();

	public:
		EnemyController(EnemyType type);
		virtual ~EnemyController();

		virtual void initialize();
		void update();
		void render();

		sf::Vector2f getEnemyPosition();

		EnemyState getEnemyState();
		EnemyType getEnemyType();
	};
}