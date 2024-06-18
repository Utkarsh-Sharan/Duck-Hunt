#include "Event/EventService.h"
#include "Global/ServiceLocator.h"

namespace Event
{
	using namespace Global;

	EventService::EventService()
	{
		game_window = nullptr;
	}

	EventService::~EventService() = default;

	void EventService::initialize()
	{
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
	}

	void EventService::processEvents()
	{
		if (isGameWindowOpen())
		{
			while (game_window->pollEvent(game_event))
			{
				if (gameWindowWasClosed() || hasQuitGame())
					game_window->close();
			}
		}
	}

	bool EventService::isGameWindowOpen()
	{
		return (game_window != nullptr);
	}

	bool EventService::gameWindowWasClosed()
	{
		return (game_event.type == sf::Event::Closed);
	}

	bool EventService::hasQuitGame()
	{
		return (isKeyboardEvent() && pressedEscapeKey());
	}

	bool EventService::isKeyboardEvent()
	{
		return (game_event.type == sf::Event::KeyPressed);
	}

	bool EventService::pressedEscapeKey()
	{
		return (game_event.key.code == sf::Keyboard::Escape);
	}

	void EventService::update()
	{
		updateMouseButtonState(left_mouse_button_state, sf::Mouse::Left);
		updateMouseButtonState(right_mouse_button_state, sf::Mouse::Right);
	}

	void EventService::updateMouseButtonState(ButtonState& current_button_state, sf::Mouse::Button mouse_button)
	{
		if (sf::Mouse::isButtonPressed(mouse_button))
		{
			switch (current_button_state)
			{
			case ButtonState::RELEASED:
				current_button_state = ButtonState::PRESSED;
				break;

			case ButtonState::PRESSED:
				current_button_state = ButtonState::HELD;
				break;
			}
		}
		else
		{
			current_button_state = ButtonState::RELEASED;
		}
	}

	bool EventService::pressedLeftMouseButton()
	{
		return left_mouse_button_state == ButtonState::PRESSED;
	}

	bool EventService::pressedRightMouseButton()
	{
		return right_mouse_button_state == ButtonState::PRESSED;
	}
}