#pragma once

#include "UI/Interface/IUIController.h"

#include "UI/UIElements/ImageView.h"
#include "UI/UIElements/TextView.h"

namespace UI
{
	namespace GameplayUI
	{
		class GameplayUIController : public Interface::IUIController
		{
		private:
			const float font_size = 40.f;

			const float player_lives_y_offset = 25.f;
			const float player_lives_x_offset = 1850.f;
			const float player_lives_spacing = 60.f;

			const float lives_sprite_width = 30.f;
			const float lives_sprite_height = 30.f;

			const float normal_bullets_y_offset = 25.f;
			const float radius_bullets_y_offset = 70.f;

			const float bullets_x_offset = 25.f;
			const float bullets_spacing = 30.f;

			const float bullets_sprite_width = 30.f;
			const float bullets_sprite_height = 40.f;

			const float enemies_killed_text_y_position = 1035.f;
			const float enemies_killed_text_x_position = 840.f;

			const sf::Color text_color = sf::Color::White;

			UI::UIElement::ImageView* player_lives_image;
			UI::UIElement::ImageView* normal_bullets_image;
			UI::UIElement::ImageView* radius_bullets_image;

			UI::UIElement::TextView* enemies_killed_text;

			void createUIElements();
			void initializeImage();
			void initializeText();

			void destroy();

		public:
			GameplayUIController();
			~GameplayUIController();

			void initialize() override;
			void update() override;
			void render() override;
			void show() override;

			void updateEnemiesKilledText();
			void drawNormalBullets();
			void drawRadiusBullets();
			void drawPlayerLives();
		};
	}
}