#include "Global/ServiceLocator.h"

namespace Global
{
	using namespace Graphic;
	using namespace Event;
	using namespace Time;
	using namespace Wave;
	using namespace Gameplay;
	using namespace Enemy;
	using namespace UI;

	ServiceLocator::ServiceLocator()
	{
		graphic_service = nullptr;
		event_service = nullptr;
		time_service = nullptr;
		wave_service = nullptr;
		gameplay_service = nullptr;
		enemy_service = nullptr;
		ui_service = nullptr;

		createServices();
	}

	ServiceLocator::~ServiceLocator()
	{
		clearAllServices();
	}

	void ServiceLocator::createServices()
	{
		graphic_service = new GraphicService();
		event_service = new EventService();
		time_service = new TimeService();
		wave_service = new WaveService();
		gameplay_service = new GameplayService();
		enemy_service = new EnemyService();
		ui_service = new UIService();
	}

	ServiceLocator* ServiceLocator::getInstance()
	{
		static ServiceLocator instance;
		return &instance;
	}

	void ServiceLocator::initialize()
	{
		graphic_service->initialize();
		event_service->initialize();
		time_service->initialize();
		wave_service->initialize();
		gameplay_service->initialize();
		enemy_service->initialize();
		ui_service->initialize();
	}

	void ServiceLocator::update()
	{
		graphic_service->update();
		event_service->update();
		time_service->update();
		wave_service->update();

		if (getGameplayService()->getGameState() == GameState::GAMEPLAY)
		{
			gameplay_service->update();
			enemy_service->update();
		}
		
		ui_service->update();
	}

	void ServiceLocator::render()
	{
		graphic_service->render();

		if (getGameplayService()->getGameState() == GameState::GAMEPLAY)
		{
			gameplay_service->render();
			enemy_service->render();
		}

		ui_service->render();
	}

	void ServiceLocator::clearAllServices()
	{
		delete(graphic_service);
		delete(event_service);
		delete(time_service);
		delete(wave_service);
		delete(gameplay_service);
		delete(enemy_service);
		delete(ui_service);

		graphic_service = nullptr;
		event_service = nullptr;
		time_service = nullptr;
		wave_service = nullptr;
		gameplay_service = nullptr;
		enemy_service = nullptr;
		ui_service = nullptr;
	}

	void ServiceLocator::destroy()
	{
		delete(this);
	}

	GraphicService* ServiceLocator::getGraphicService()
	{
		return graphic_service;
	}

	EventService* ServiceLocator::getEventService()
	{
		return event_service;
	}

	TimeService* ServiceLocator::getTimeService()
	{
		return time_service;
	}

	Wave::WaveService* ServiceLocator::getWaveService()
	{
		return wave_service;
	}

	Gameplay::GameplayService* ServiceLocator::getGameplayService()
	{
		return gameplay_service;
	}

	EnemyService* ServiceLocator::getEnemyService()
	{
		return enemy_service;
	}

	UI::UIService* ServiceLocator::getUIService()
	{
		return ui_service;
	}
}