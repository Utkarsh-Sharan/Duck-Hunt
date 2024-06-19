#pragma once

namespace Enemy
{
	enum class EnemyType
	{
		BLACK,
		RED,
		BLUE,
	};

	enum class EnemyState
	{
		ALIVE,
		DEAD,
	};

	enum class MovementDirection
	{
		LEFT_DIAGONAL,
		RIGHT_DIAGONAL,
	};
}