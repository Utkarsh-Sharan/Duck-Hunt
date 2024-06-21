#include "Main/GameService.h"

namespace Main
{
	using namespace Global;

	GameState GameService::current_state = GameState::BOOT;		//initial state

	GameService::GameService()
	{
		service_locator = nullptr;
		game_window = nullptr;
	}

	GameService::~GameService()
	{
		destroy();
	}

	void GameService::ignite()
	{
		service_locator = ServiceLocator::getInstance();
		initialize();
	}

	void GameService::initialize()
	{
		service_locator->getInstance()->initialize();
		initializeVariables();
		showSplashScreen();
	}

	void GameService::initializeVariables()
	{
		game_window = service_locator->getInstance()->getGraphicService()->getGameWindow();
	}

	void GameService::showSplashScreen()
	{
		setGameState(GameState::SPLASH_SCREEN);
	}

	void GameService::update()
	{
		service_locator->getEventService()->processEvents();
		service_locator->getInstance()->update();
	}

	void GameService::render()
	{
		game_window->clear(service_locator->getInstance()->getGraphicService()->getWindowColor());
		service_locator->getInstance()->render();
		game_window->display();
	}

	bool GameService::isRunning()
	{
		return service_locator->getGraphicService()->isGameWindowOpen();
	}

	void GameService::setGameState(GameState state)
	{
		current_state = state;
	}

	GameState GameService::getGameState()
	{
		return current_state;
	}

	void GameService::destroy()
	{
		service_locator->getInstance()->destroy();
		delete(game_window);

		service_locator = nullptr;
		game_window = nullptr;
	}
}