#include "Enemy/EnemyModel.h"

namespace Enemy
{
	EnemyModel::EnemyModel(EnemyType type)
	{
		enemy_type = type;
	}

	EnemyModel::~EnemyModel()
	{

	}

	void EnemyModel::initialize()
	{
		movement_direction = getRandomMovementDirection();
		enemy_state = EnemyState::ALIVE;

		has_reached_bottom = true;
		has_reached_top = false;

		enemy_position = reference_position;
	}

	void EnemyModel::update()
	{

	}

	void EnemyModel::render()
	{

	}

	sf::Vector2f EnemyModel::getEnemyPosition()
	{
		return enemy_position;
	}

	void EnemyModel::setEnemyPosition(sf::Vector2f position)
	{
		enemy_position = position;
	}

	sf::Vector2f EnemyModel::getReferencePosition()
	{
		return reference_position;
	}

	void EnemyModel::setReferencePosition(sf::Vector2f position)
	{
		reference_position = position;
	}

	EnemyType EnemyModel::getEnemyType()
	{
		return enemy_type;
	}

	void EnemyModel::setEnemyType(EnemyType type)
	{
		enemy_type = type;
	}

	EnemyState EnemyModel::getEnemyState()
	{
		return enemy_state;
	}

	void EnemyModel::setEnemyState(EnemyState state)
	{
		enemy_state = state;
	}

	MovementDirection EnemyModel::getMovementDirection()
	{
		return movement_direction;
	}

	void EnemyModel::setMovementDirection(MovementDirection direction)
	{
		movement_direction = direction;
	}

	MovementDirection EnemyModel::getRandomMovementDirection()
	{
		int randomType = std::rand() % 2;

		return static_cast<MovementDirection>(randomType);
	}
}