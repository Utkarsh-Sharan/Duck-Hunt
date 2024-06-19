#include "Global/ServiceLocator.h"

namespace Global
{
	using namespace Graphic;
	using namespace Event;
	using namespace Time;

	ServiceLocator::ServiceLocator()
	{
		graphic_service = nullptr;
		event_service = nullptr;
		time_service = nullptr;

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
	}

	void ServiceLocator::update()
	{
		graphic_service->update();
		event_service->update();
		time_service->update();
	}

	void ServiceLocator::render()
	{
		graphic_service->render();
	}

	void ServiceLocator::clearAllServices()
	{
		delete(graphic_service);
		delete(event_service);
		delete(time_service);

		graphic_service = nullptr;
		event_service = nullptr;
		time_service = nullptr;
	}

	void ServiceLocator::destroy()
	{
		delete(this);
	}

	Graphic::GraphicService* ServiceLocator::getGraphicService()
	{
		return graphic_service;
	}

	Event::EventService* ServiceLocator::getEventService()
	{
		return event_service;
	}

	Time::TimeService* ServiceLocator::getTimeService()
	{
		return time_service;
	}
}