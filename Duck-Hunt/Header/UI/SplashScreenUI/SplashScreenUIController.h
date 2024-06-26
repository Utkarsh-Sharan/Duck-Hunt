#pragma once

#include "UI/Interface/IUIController.h"
#include "UI/UIElements/TextView.h"

namespace UI
{
	namespace SplashScreen
	{
		class SplashScreenUIController : public Interface::IUIController
		{
		private:
			const float font_size = 60.f;

			const float text_y_position = 540.f;
			const float wave_text_x_position = 960.f;

			const sf::Color text_color = sf::Color::White;

			UI::UIElement::TextView* wave_text;

			void createUIElements();
			void initializeText();

			void destroy();

		public:
			SplashScreenUIController();
			~SplashScreenUIController();

			void initialize() override;
			void update() override;
			void render() override;
			void show() override;

			void updateWaveText();
		};
	}
}