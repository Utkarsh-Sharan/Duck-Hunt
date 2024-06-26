#pragma once

#include "UI/UIElements/UIView.h"

namespace UI
{
	namespace UIElement
	{
		enum class FontType
		{
			FEASFBRG
		};

		class TextView : public UIView
		{
		private:
			static const int default_font_size = 55;

			static sf::Font font_feasfbrg;

			sf::Text text;

			static void loadFont();

			void setFont();
			void setFontSize(int font_size);
			void setTextPosition(sf::Vector2f position);
			void setTextColor(sf::Color color);

		public:
			TextView();
			virtual ~TextView();

			static void initializeTextView();

			virtual void initialize(sf::String text_value, sf::Vector2f position, FontType font_type = FontType::FEASFBRG, int font_size = default_font_size, sf::Color color = sf::Color::White);
			virtual void update() override;
			virtual void render() override;

			void setText(sf::String text_value);
			void setTextCentreAligned();
		};
	}
}