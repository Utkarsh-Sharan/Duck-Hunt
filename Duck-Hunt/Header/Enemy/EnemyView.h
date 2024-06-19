#pragma once

#include "UI/UIElements/ImageView.h"
#include <SFML/Graphics.hpp>

namespace Enemy
{
	class EnemyController;
	enum class EnemyType;

	class EnemyView
	{
	private:
		const float enemy_sprite_width = 30.0f;
		const float enemy_sprite_height = 30.0f;

		UI::UIElement::ImageView* enemy_image;
		EnemyController* enemy_controller;

		void createUIElements();
		void initializeImage();

		sf::String getEnemyTexturePath();

		void destroy();

	public:
		EnemyView();
		~EnemyView();

		void initialize(EnemyController* controller);
		void update();
		void render();

		const sf::Sprite& getEnemySprite();
	};
}