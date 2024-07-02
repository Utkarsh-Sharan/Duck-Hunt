#include "Player/PlayerModel.h"

namespace Player
{
	int PlayerModel::player_lives;
	int PlayerModel::enemies_killed;
	int PlayerModel::player_normal_bullets;
	int PlayerModel::player_radius_bullets;

	PlayerModel::PlayerModel()
	{

	}

	PlayerModel::~PlayerModel()
	{

	}

	void PlayerModel::initialize()
	{
		reset();
	}

	void PlayerModel::reset()
	{
		player_state = PlayerState::ALIVE;

		player_score = 0;

		player_lives = max_player_lives;
		enemies_killed = 0;
	}

	void PlayerModel::resetAllBullets()
	{
		player_normal_bullets = 0;
		player_radius_bullets = 0;
	}

	int PlayerModel::getPlayerScore()
	{
		return player_score;
	}

	void PlayerModel::setPlayerScore(int score)
	{
		player_score = score;
	}

	/*int PlayerModel::getPlayerNormalBullets()
	{
		return player_normal_bullets;
	}

	void PlayerModel::setPlayerNormalBullets(int bullets)
	{
		player_normal_bullets = bullets;
	}

	int PlayerModel::getPlayerRadiusBullets()
	{
		return player_radius_bullets;
	}

	void PlayerModel::setPlayerRadiusBullets(int bullets)
	{
		player_radius_bullets = bullets;
	}*/

	PlayerState PlayerModel::getPlayerState()
	{
		return player_state;
	}

	void PlayerModel::setPlayerState(PlayerState state)
	{
		player_state = state;
	}
}