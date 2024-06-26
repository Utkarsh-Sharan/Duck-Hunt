#pragma once

#include "UI/SplashScreenUI/SplashScreenUIController.h"
#include "UI/GameplayUI/GameplayUIController.h"

#include "UI/Interface/IUIController.h"

namespace UI
{
	class UIService
	{
	private:
		GameplayUI::GameplayUIController* gameplay_ui_controller;
		SplashScreen::SplashScreenUIController* splash_screen_ui_controller;

		void createControllers();
		void initializeControllers();
		void destroy();

		Interface::IUIController* getCurrentUIController();

	public:
		UIService();
		~UIService();

		void initialize();
		void update();
		void render();

		void showScreen();
	};
}