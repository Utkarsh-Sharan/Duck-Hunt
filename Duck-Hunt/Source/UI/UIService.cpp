#include "UI/UIService.h"
#include "Global/ServiceLocator.h"
#include "Gameplay/GameplayService.h"

namespace UI
{
	using namespace Interface;
	using namespace GameplayUI;
	using namespace SplashScreen;
	using namespace Global;
	using namespace Gameplay;

	UIService::UIService()
	{
		gameplay_ui_controller = nullptr;
		splash_screen_ui_controller = nullptr;

		createControllers();
	}

	UIService::~UIService()
	{
		destroy();
	}

	void UI::UIService::createControllers()
	{
		gameplay_ui_controller = new GameplayUIController();
		splash_screen_ui_controller = new SplashScreenUIController();
	}

	void UIService::initialize()
	{
		initializeControllers();
	}

	void UIService::initializeControllers()
	{
		gameplay_ui_controller->initialize();
		splash_screen_ui_controller->initialize();
	}

	void UIService::update()
	{
		IUIController* ui_controller = getCurrentUIController();

		if (ui_controller)
			ui_controller->update();
	}

	void UIService::render()
	{
		IUIController* ui_controller = getCurrentUIController();

		if (ui_controller)
			ui_controller->render();
	}

	IUIController* UIService::getCurrentUIController()
	{
		switch (ServiceLocator::getInstance()->getGameplayService()->getGameState())
		{
		case GameState::SPLASH_SCREEN:
			return splash_screen_ui_controller;

		case GameState::GAMEPLAY:
			return gameplay_ui_controller;

		default:
			return nullptr;
		}
	}

	void UIService::showScreen()
	{
		IUIController* ui_controller = getCurrentUIController();

		if (ui_controller)
			ui_controller->show();
	}

	void UIService::destroy()
	{
		delete(gameplay_ui_controller);
		delete(splash_screen_ui_controller);

		gameplay_ui_controller = nullptr;
		splash_screen_ui_controller = nullptr;
	}
}

