#ifndef _TD2DE_MAIN_
#define _TD2DE_MAIN_

#include <SDL.h>


namespace TD2DE
{
	class TD2DE_Main
	{
	public:
		bool EngineIsRunning();

		SDL_Renderer* renderer;
		bool engineRunning = false;

	private:
		bool fullScreen;
		bool commandConsoleEnabled;

		int screenWidth;
		int screenHeight;
		int frameRateLimit;
	}TD2DE_MAIN;
}



bool TD2DE::TD2DE_Main::EngineIsRunning()
{
	return engineRunning;
}


#endif