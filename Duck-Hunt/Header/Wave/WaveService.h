#pragma once

#include "Gameplay/GameplayService.h"

namespace Wave
{
	class WaveService
	{
	private:
		const float wave_time = 10.0f;  //for gameplay screen
		const float wave_pause = 4.0f;  //for splash screen

		float wave_timer;
		float wave_pause_timer;
		int wave_number;

		Gameplay::GameplayService* gameplay_service;

		void updateWaveTimer();
		void updateWavePauseTimer();

	public:
		WaveService();
		~WaveService();

		void initialize();
		void update();

		int getWaveNumber();
	};
}