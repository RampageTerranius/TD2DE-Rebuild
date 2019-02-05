#ifndef _TD2DE_MAIN_
#define _TD2DE_MAIN_

#include <SDL.h>


namespace TD2DE
{
	class TD2DE_Main
	{
	public:

		void StartEngine();
		void ShutdownEngine();

		bool EngineIsRunning();

		SDL_Renderer* renderer;

	private:
		bool engineRunnning = false;
		bool fullScreen;
		bool commandConsoleEnabled;

		int screenWidth;
		int screenHeight;
		int frameRateLimit;


	}TD2DE_MAIN;
}


#endif