#ifndef _TD2DE_MAIN_
#define _TD2DE_MAIN_

#include <SDL.h>

//TODO: remvoe this class, there is no reaso nfor it to exist in its current state
namespace TD2DE
{
	class TD2DE_Main
	{
	public:
		bool EngineIsRunning();
		bool engineRunning = false;//TODO: move this into TD2DE_Engine instead, there is no reason for this class to exist

		float avgFPS;
		
	private:
		
		bool commandConsoleEnabled;
	}TD2DE_MAIN;
}



bool TD2DE::TD2DE_Main::EngineIsRunning()
{
	return engineRunning;
}
#endif