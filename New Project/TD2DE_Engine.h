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
			//check if there is a internal SDL error currently and print it if so
			std::string sdlError;

			if (SDL_GetError() != "")
			{
				sdlError = SDL_GetError();
				SDL_ClearError();
			}

			TD2DE_DEBUG.LogMessage("[TD2DE_Engine]Error: Initialize-SDL_Init_Video: " + sdlError, DEBUG_LOW);
			return false;
		}
		else
				TD2DE_DEBUG.LogMessage("[TD2DE_Engine]Video initialization success!", DEBUG_LOW);

		//image loader
		int flags = IMG_INIT_PNG;
		int init = IMG_Init(flags);
		if (init != flags)
		{
			//check if there is a internal SDL error currently and print it if so
			std::string sdlError;

			if (SDL_GetError() != "")
			{
				sdlError = SDL_GetError();
				SDL_ClearError();
			}

			TD2DE_DEBUG.LogMessage("[TD2DE_Engine]Error: Initialize-SDL_Init-IMG_INIT: Unable to initialize image loader: " + sdlError, DEBUG_LOW);
			return false;
		}
		else
			TD2DE_DEBUG.LogMessage("[TD2DE_Engine]Image Loading engine initialization success!", DEBUG_LOW);

		//standard audio
		if (SDL_Init(SDL_INIT_AUDIO) != 0)
		{
			//check if there is a internal SDL error currently and print it if so
			std::string sdlError;

			if (SDL_GetError() != "")
			{
				sdlError = SDL_GetError();
				SDL_ClearError();
			}

			TD2DE_DEBUG.LogMessage("[TD2DE_Engine]Error: Initialize-SDL_Init_Audio: " + sdlError, DEBUG_LOW);
			return false;
		}
		else
			TD2DE_DEBUG.LogMessage("[TD2DE_Engine]Audio initialization success!", DEBUG_LOW);

		//sdl_mixer
		if (Mix_OpenAudio(TD2DE::TD2DE_AUDIO.GetMhz(), MIX_DEFAULT_FORMAT, TD2DE::TD2DE_AUDIO.GetChannels(), TD2DE::TD2DE_AUDIO.GetBitRate()) < 0)
		{
			//check if there is a internal SDL error currently and print it if so
			std::string sdlError;

			if (SDL_GetError() != "")
			{
				sdlError = SDL_GetError();
				SDL_ClearError();
			}

			TD2DE_DEBUG.LogMessage("[TD2DE_Engine]Error: Initialize-SDL_Init_Audio_Mixer: " + sdlError, DEBUG_LOW);
			return false;
		}
		else
			TD2DE_DEBUG.LogMessage("[TD2DE_Engine]Mixer sucessfully initialized at settings, " + std::to_string(TD2DE::TD2DE_AUDIO.GetMhz()) + ", " + std::to_string(TD2DE::TD2DE_AUDIO.GetChannels()) + ", " + std::to_string(TD2DE::TD2DE_AUDIO.GetBitRate()), DEBUG_LOW);
				

		//timer
		if (SDL_Init(SDL_INIT_TIMER) != 0)
		{
			//check if there is a internal SDL error currently and print it if so
			std::string sdlError;

			if (SDL_GetError() != "")
			{
				sdlError = SDL_GetError();
				SDL_ClearError();
			}

			TD2DE_DEBUG.LogMessage("[TD2DE_Engine]Error: Initialize-SDL_Init_Timer: " + sdlError, DEBUG_LOW);
			return false;
		}
		else
			TD2DE_DEBUG.LogMessage("[TD2DE_Engine]Timer initialization success!", DEBUG_LOW);

		//ttf loading
		if (TTF_Init() == -1)
		{
			//check if there is a internal SDL error currently and print it if so
			std::string sdlError;

			if (SDL_GetError() != "")
			{
				sdlError = SDL_GetError();
				SDL_ClearError();
			}

			TD2DE_DEBUG.LogMessage("[TD2DE_Engine]Unable to initialize ttf engine: " + sdlError, DEBUG_LOW);
			return false;
		}
		else
			TD2DE_DEBUG.LogMessage("[TD2DE_Engine]TTF engine initialization success!", DEBUG_LOW);


		//start renderer
		if (!TD2DE::TD2DE_RENDER.Start())
		{
			//check if there is a internal SDL error currently and print it if so
			std::string sdlError;

			if (SDL_GetError() != "")
			{
				sdlError = SDL_GetError();
				SDL_ClearError();
			}

			TD2DE_DEBUG.LogMessage("[TD2DE_Engine]Unable to initialize render engine: " + sdlError, DEBUG_LOW);
			return false;
		}
		else
			TD2DE_DEBUG.LogMessage("[TD2DE_Engine]Render engine initialization success!", DEBUG_LOW);


		TD2DE_DEBUG.LogMessage("[TD2DE_Engine]Engine started successfully!", DEBUG_LOW);
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