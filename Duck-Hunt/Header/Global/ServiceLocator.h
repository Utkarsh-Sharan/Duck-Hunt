#pragma once

#include "Graphic/GraphicService.h"
#include "Event/EventService.h"
#include "Time/TimeService.h"
#include "Enemy/EnemyService.h"

namespace Global
{
	class ServiceLocator
	{
	private:
		Graphic::GraphicService* graphic_service;
		Event::EventService* event_service;
		Time::TimeService* time_service;
		Enemy::EnemyService* enemy_service;

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
		Enemy::EnemyService* getEnemyService();
	};
}