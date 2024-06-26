#pragma once

#include "Graphic/GraphicService.h"
#include "Event/EventService.h"
#include "Time/TimeService.h"
#include "Gameplay/GameplayService.h"
#include "Enemy/EnemyService.h"
#include "UI/UIService.h"

namespace Global
{
	class ServiceLocator
	{
	private:
		Graphic::GraphicService* graphic_service;
		Event::EventService* event_service;
		Time::TimeService* time_service;
		Gameplay::GameplayService* gameplay_service;
		Enemy::EnemyService* enemy_service;
		UI::UIService* ui_service;

		ServiceLocator();
		~ServiceLocator();

		void createServices();
		void clearAllServices();

	public:
		static ServiceLocator* getInstance();

		void initialize();
		void update();
		void render();

		void destroy();

		Graphic::GraphicService* getGraphicService();
		Event::EventService* getEventService();
		Time::TimeService* getTimeService();
		Gameplay::GameplayService* getGameplayService();
		Enemy::EnemyService* getEnemyService();
		UI::UIService* getUIService();
	};
}