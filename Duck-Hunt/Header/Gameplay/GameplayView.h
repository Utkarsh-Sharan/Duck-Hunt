#pragma once

#include "UI/UIElements/ImageView.h"

#include <SFML/Graphics.hpp>

namespace Gameplay
{
	class GameplayView
	{
	private:
		UI::UIElement::ImageView* background_image;

		float tile_width = 200.0f;
		float tile_height = 152.0f;

		void createUIElements();
		void initializeImage();
		void destroy();

	public:
		GameplayView();
		~GameplayView();

		void initialize();
		void update();
		void render();
	};
}