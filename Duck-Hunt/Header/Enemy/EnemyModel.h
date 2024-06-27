#pragma once

#include "Enemy/EnemyConfig.h"
#include <SFML/Graphics.hpp>

namespace Enemy
{
	class EnemyModel
	{
	private:
		sf::Vector2f reference_position = sf::Vector2f(50.0f, 50.0f);
		sf::Vector2f enemy_position;

		EnemyType enemy_type;
		EnemyState enemy_state;
		MovementDirection movement_direction;

	public:
		const sf::Vector2f left_most_position = sf::Vector2f(50.f, 900.f);
		const sf::Vector2f right_most_position = sf::Vector2f(1800.f, 50.f);
		const sf::Vector2f top_most_position = sf::Vector2f(0.0f, 50.0f);
		const sf::Vector2f bottom_most_position = sf::Vector2f(0.0f, 900.0f);

		bool has_reached_top;
		bool has_reached_bottom;

		const float enemy_movement_speed = 500.0f;

		EnemyModel(EnemyType type);
		~EnemyModel();

		void initialize();
		void update();
		void render();

		sf::Vector2f getEnemyPosition();
		void setEnemyPosition(sf::Vector2f position);

		sf::Vector2f getReferencePosition();
		void setReferencePosition(sf::Vector2f position);

		EnemyType getEnemyType();
		void setEnemyType(EnemyType type);

		EnemyState getEnemyState();
		void setEnemyState(EnemyState state);

		MovementDirection getMovementDirection();
		void setMovementDirection(MovementDirection direction);

		MovementDirection getRandomMovementDirection();
	};
}