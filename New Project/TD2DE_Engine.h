#ifndef _TD2DE_ENGINE_
#define _TD2DE_ENGINE_

#include "TD2DE_Main.h"
#include <time.h>
#include <windows.h>

namespace TD2DE
{
	class TD2DE_Engine
	{
	public:
		bool Start();
		void Stop();
	}TD2DE_ENGINE;

	bool TD2DE::TD2DE_Engine::Start()
	{
		//TODO: start the engine here
		TD2DE::TD2DE_MAIN.engineRunning = true;

		TD2DE::TD2DE_DEBUG.Start();

		TD2DE_DEBUG.LogMessage("[TD2DE_Engine]Starting up engine...", DEBUG_LOW);

		//initialize SDL
		//video
		if (SDL_Init(SDL_INIT_VIDEO) != 0)
		{
			if (SDL_GetError() != "")
					TD2DE_DEBUG.LogMessage("[TD2DE_Engine]Error: Initialize-SDL_Init_Video", DEBUG_LOW);
			return false;
		}
		else
				TD2DE_DEBUG.LogMessage("[TD2DE_Engine]Video initialization success!", DEBUG_LOW);

		//standard audio
		if (SDL_Init(SDL_INIT_AUDIO) != 0)
		{
			if (SDL_GetError() != "")
					TD2DE_DEBUG.LogMessage("[TD2DE_Engine]Error: Initialize-SDL_Init_Audio", DEBUG_LOW);
			return false;
		}
		else
				TD2DE_DEBUG.LogMessage("[TD2DE_Engine]Audio initialization success!", DEBUG_LOW);

		//sdl_mixer
		/*if (Mix_OpenAudio(TD2DE.GetMHZ(), MIX_DEFAULT_FORMAT, TD2DE.GetChannels(), TD2DE.GetBitRate()) < 0)
		{
			if (TD2DE.GetDebugMode() >= DEBUG_LOW)
				TD2DE_DEBUG.LogMessage("Error: Initialize-SDL_Init_Audio_Mixer", true);
			return false;
		}
		else
			if (TD2DE.GetDebugMode() >= DEBUG_LOW)
				TD2DE_DEBUG.LogMessage("Info: Mixer sucessfully initialized at settings, " + to_string(TD2DE.GetMHZ()) + ", " + to_string(TD2DE.GetChannels()) + ", " + to_string(TD2DE.GetBitRate()));
				*/

		//timer
		if (SDL_Init(SDL_INIT_TIMER) != 0)
		{
			if (SDL_GetError() != "")
					TD2DE_DEBUG.LogMessage("[TD2DE_Engine]Error: Initialize-SDL_Init_Timer", DEBUG_LOW);
			return false;
		}
		else
			TD2DE_DEBUG.LogMessage("[TD2DE_Engine]Timer initialization success!", DEBUG_LOW);

		//ttf loading
		if (TTF_Init() == -1)
		{
			TD2DE_DEBUG.LogMessage("[TD2DE_Engine]Unable to initialize ttf engine", DEBUG_LOW);
			return false;
		}
		else
				TD2DE_DEBUG.LogMessage("[TD2DE_Engine]: TTF Engine initialization success!", DEBUG_LOW);

		TD2DE_DEBUG.LogMessage("[TD2DE_Engine]Engine started!", DEBUG_LOW);

		return true;
	}

	void TD2DE::TD2DE_Engine::Stop()
	{
		TD2DE_DEBUG.LogMessage("[TD2DE_Engine]Shutting down engine...", DEBUG_HIGH);

		//cleanup all textures in storage
		TD2DE_DEBUG.LogMessage("[TD2DE_Engine]Clearing textures from list...", DEBUG_HIGH);
		TD2DE_TEXTURE.RemoveAllTextures();

		TD2DE_DEBUG.LogMessage("[TD2DE_Engine]Engine has shut down, shutting down debug logging...", DEBUG_LOW);

		TD2DE::TD2DE_DEBUG.Stop();

		TD2DE::TD2DE_MAIN.engineRunning = false;		
	}

}


#endif