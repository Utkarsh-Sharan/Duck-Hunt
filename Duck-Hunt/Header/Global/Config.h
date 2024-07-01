#pragma once

#include <SFML/Graphics.hpp>

namespace Global
{
	class Config
	{
	public:
		static const sf::String background_texture_path;
		static const sf::String player_life_texture_path;

		static const sf::String black_duck_texture_path;
		static const sf::String blue_duck_texture_path;
		static const sf::String red_duck_texture_path;

		static const sf::String normal_bullet_texture_path;
		static const sf::String radius_bullet_texture_path;

		static const sf::String feasfbrg_font_path;
	};
}