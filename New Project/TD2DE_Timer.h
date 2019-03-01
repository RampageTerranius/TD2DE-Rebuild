//header guard
#ifndef _TD2DE_TIMER_
#define _TD2DE_TIMER_

namespace TD2DE
{
	Uint32 TD2DE_CurrentFrames;

	class TD2DE_Timer
	{
	public:
		TD2DE_Timer();

		void Start();
		void Stop();
		void Pause();
		void Unpause();
		bool IsStarted();
		bool IsPaused();

		Uint32  GetTicks();

	private:
		Uint32 PauseTick,
				StartTick;

		bool Started,
			Paused;

	}TD2DE_FPSTIMER, TD2DE_CAPTIMER;
}

TD2DE::TD2DE_Timer::TD2DE_Timer()
{
	PauseTick = 0;
	StartTick = 0;
	Started = false;
	Paused = false;
}

Uint32  TD2DE::TD2DE_Timer::GetTicks()
{
	if (Started)
	{
		if (Paused)
			return PauseTick;
		else
			return SDL_GetTicks() - StartTick;
	}

	return 0;
}

void TD2DE::TD2DE_Timer::Start()
{
	StartTick = SDL_GetTicks();
	PauseTick = 0;
	Started = true;
	Paused = false;
}

void TD2DE::TD2DE_Timer::Stop()
{
	StartTick = 0;
	PauseTick = 0;
	Started = false;
	Paused = false;
}

void TD2DE::TD2DE_Timer::Pause()
{
	if (!Paused)
	{
		PauseTick = SDL_GetTicks() - StartTick;
		Paused = true;
	}
	else
		TD2DE::TD2DE_DEBUG.LogMessage("[TD2DE_Timer]Attempting to unpause timer that is not started", TD2DE::DEBUG_MEDIUM);
}

void TD2DE::TD2DE_Timer::Unpause()
{
	if (Paused)
	{
		StartTick = SDL_GetTicks() - PauseTick;
		Paused = false;
	}
	else
		TD2DE::TD2DE_DEBUG.LogMessage("[TD2DE_Timer]TimeClass Attempting to unpause Timer that is not paused", TD2DE::DEBUG_MEDIUM);
}

bool TD2DE::TD2DE_Timer::IsPaused()
{
	return Paused;
}

bool TD2DE::TD2DE_Timer::IsStarted()
{
	return Started;
}

namespace TD2DE
{
	
	void TD2DE_TimeHandle()
	{
		TD2DE::TD2DE_DEBUG.LogMessage("[TD2DE_Timer]TimeHandle begin", TD2DE::DEBUG_HIGH);

		TD2DE::TD2DE_MAIN.avgFPS = TD2DE_CurrentFrames / (TD2DE_FPSTIMER.GetTicks() / 1000.f);

		if (TD2DE::TD2DE_MAIN.avgFPS > 2000000)
			TD2DE::TD2DE_MAIN.avgFPS = 0;

		TD2DE::TD2DE_DEBUG.LogMessage("[TD2DE_Timer]fps: " + std::to_string(TD2DE::TD2DE_MAIN.avgFPS), TD2DE::DEBUG_HIGH);

		++TD2DE_CurrentFrames;

		TD2DE::TD2DE_DEBUG.LogMessage("[TD2DE_Timer]TimeHandle end", TD2DE::DEBUG_HIGH);
	}


	void TD2DE_StartFPSTimer()
	{
		//fps timer only needs to be activated once in its life and can determine the fps from there on
		if (TD2DE::TD2DE_FPSTIMER.IsStarted() == false)
		TD2DE::TD2DE_FPSTIMER.Start();
	}

	//shutdown fps and cap timers (this will automatically be called by the cleanup procedure so its not nessicary to use it yourself)
	void TD2DE_StopTimers(bool Cap, bool Fps)
	{
		if (Cap == true)
			if (TD2DE::TD2DE_CAPTIMER.IsStarted() == true)
				TD2DE::TD2DE_CAPTIMER.Stop();
		if (Fps == true)
			if (TD2DE::TD2DE_FPSTIMER.IsStarted() == true)
				TD2DE::TD2DE_FPSTIMER.Stop();
	}
}


#endif