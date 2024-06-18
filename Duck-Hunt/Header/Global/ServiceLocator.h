#pragma once

#include "Graphic/GraphicService.h"
#include "Event/EventService.h"

namespace Global
{
	class ServiceLocator
	{
	private:
		Graphic::GraphicService* graphic_service;
		Event::EventService* event_service;

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
	};
}