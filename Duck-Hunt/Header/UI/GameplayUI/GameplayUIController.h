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

			const float bullets_y_offset = 25.f;
			const float bullets_x_offset = 25.f;
			const float bullets_spacing = 60.f;

			const float bullets_sprite_width = 30.f;
			const float bullets_sprite_height = 30.f;

			UI::UIElement::ImageView* player_lives_image;
			UI::UIElement::ImageView* bullets_image;

			void createUIElements();
			void initializeImage();

			void destroy();

		public:
			GameplayUIController();
			~GameplayUIController();

			void initialize();
			void update();
			void render();
			void show();

			void drawBullets();
			void drawPlayerLives();
		};
	}
}