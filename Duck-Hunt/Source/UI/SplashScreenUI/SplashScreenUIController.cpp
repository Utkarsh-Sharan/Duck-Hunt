#include "UI/SplashScreenUI/SplashScreenUIController.h"
#include "Global/ServiceLocator.h"

namespace UI
{
	namespace SplashScreen
	{
		using namespace UI::UIElement;
		using namespace Global;
		using namespace Gameplay;
		using namespace Wave;

		SplashScreenUIController::SplashScreenUIController()
		{
			createUIElements();
		}

		SplashScreenUIController::~SplashScreenUIController()
		{
			destroy();
		}

		void SplashScreenUIController::createUIElements()
		{
			wave_text = new TextView();
		}

		void SplashScreenUIController::initialize()
		{
			initializeText();
		}

		void SplashScreenUIController::initializeText()
		{
			sf::String wave_string = "WAVE  :  1";

			wave_text->initialize(wave_string, sf::Vector2f(wave_text_x_position, text_y_position), FontType::FEASFBRG, font_size, text_color);
		}

		void SplashScreenUIController::update()
		{
			if(ServiceLocator::getInstance()->getGameplayService()->getGameState() == GameState::SPLASH_SCREEN)
				updateWaveText();
		}

		void SplashScreenUIController::updateWaveText()
		{
			sf::String wave_string = "Wave  :  " + std::to_string(ServiceLocator::getInstance()->getWaveService()->getWaveNumber());
			wave_text->setText(wave_string);
		}

		void SplashScreenUIController::render()
		{
			if (ServiceLocator::getInstance()->getGameplayService()->getGameState() == GameState::SPLASH_SCREEN)
				wave_text->render();
		}

		void SplashScreenUIController::show()
		{

		}

		void SplashScreenUIController::destroy()
		{
			delete(wave_text);

			wave_text = nullptr;
		}
	}
}
