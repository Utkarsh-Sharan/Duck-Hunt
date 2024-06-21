#include "Main/GameService.h"

namespace Main
{
	using namespace Global;
	using namespace Gameplay;

	//GameState GameService::current_state = GameState::BOOT;		//initial state

	GameService::GameService()
	{
		service_locator = nullptr;
		gameplay_service = nullptr;
		game_window = nullptr;
	}

	GameService::~GameService()
	{
		destroy();
	}

	void GameService::ignite()
	{
		service_locator = ServiceLocator::getInstance();
		gameplay_service = new GameplayService();

		initialize();
	}

	void GameService::initialize()
	{
		service_locator->getInstance()->initialize();
		gameplay_service->initialize();

		initializeVariables();
		showSplashScreen();
	}

	void GameService::initializeVariables()
	{
		game_window = service_locator->getInstance()->getGraphicService()->getGameWindow();
	}

	void GameService::showSplashScreen()
	{
		gameplay_service->setGameState(GameState::SPLASH_SCREEN);
	}

	void GameService::update()
	{
		service_locator->getEventService()->processEvents();
		service_locator->getInstance()->update();
		gameplay_service->update();
	}

	void GameService::render()
	{
		game_window->clear(service_locator->getInstance()->getGraphicService()->getWindowColor());

		service_locator->getInstance()->render();
		gameplay_service->render();

		game_window->display();
	}

	bool GameService::isRunning()
	{
		return service_locator->getGraphicService()->isGameWindowOpen();
	}

	/*void GameService::setGameState(GameState state)
	{
		current_state = state;
	}

	GameState GameService::getGameState()
	{
		return current_state;
	}*/

	void GameService::destroy()
	{
		service_locator->getInstance()->destroy();
		delete(gameplay_service);
		delete(game_window);

		service_locator = nullptr;
		gameplay_service = nullptr;
		game_window = nullptr;
	}
}