#pragma once

#include "UI/Interface/IUIController.h"
#include "UI/UIElements/ImageView.h"

namespace UI
{
	namespace GameplayUI
	{
		class GameplayUIController : public Interface::IUIController
		{
		private:
			const float player_lives_y_offset = 25.f;
			const float player_lives_x_offset = 1850.f;
			const float player_lives_spacing = 60.f;

			const float lives_sprite_width = 30.f;
			const float lives_sprite_height = 30.f;

			const float normal_bullets_y_offset = 25.f;
			const float radius_bullets_y_offset = 60.f;

			const float bullets_x_offset = 25.f;
			const float bullets_spacing = 60.f;

			const float bullets_sprite_width = 30.f;
			const float bullets_sprite_height = 40.f;

			UI::UIElement::ImageView* player_lives_image;
			UI::UIElement::ImageView* normal_bullets_image;
			UI::UIElement::ImageView* radius_bullets_image;

			void createUIElements();
			void initializeImage();

			void destroy();

		public:
			GameplayUIController();
			~GameplayUIController();

			void initialize() override;
			void update() override;
			void render() override;
			void show() override;

			void drawNormalBullets();
			void drawRadiusBullets();
			void drawPlayerLives();
		};
	}
}