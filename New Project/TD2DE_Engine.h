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

	private:
		bool CheckPrerequisites();

	private:
	}TD2DE_ENGINE;

}

bool TD2DE::TD2DE_Engine::CheckPrerequisites()
{
	//check if the engien is already marked as running
	if (TD2DE::TD2DE_MAIN.EngineIsRunning())
	{
		TD2DE_DEBUG.LogMessage("[TD2DE_Engine]Error: Attempt to start engine when engine is already running!", DEBUG_LOW);
		return false;
	}

	if (TD2DE::TD2DE_RENDER.GetFrameRateLimit() <= 0)
	{
		TD2DE_DEBUG.LogMessage("[TD2DE_Engine]Error: Engine framerate of " + std::to_string(TD2DE::TD2DE_RENDER.GetFrameRateLimit()) + " is not valid. Please set engines target framerate to an acceptible level", DEBUG_LOW);
		return false;
	}

	return true;
}

bool TD2DE::TD2DE_Engine::Start()
{
	TD2DE::TD2DE_DEBUG.Start();

	TD2DE_DEBUG.LogMessage("[TD2DE_Engine]Attempting to start engine...", DEBUG_LOW);

	//presetup checklist
	if (!CheckPrerequisites())
	{
		return false;
		TD2DE_DEBUG.LogMessage("[TD2DE_Engine]Error: Pre-Requisite checklist has failed", DEBUG_LOW);
	}
	else
		TD2DE_DEBUG.LogMessage("[TD2DE_Engine]Pre-Requisite checklist success!", DEBUG_LOW);


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
	/*if (Mix_OpenAudio(TD2DE::TD2DE_AUDIO.GetFrequency(), MIX_DEFAULT_FORMAT, TD2DE::TD2DE_AUDIO.GetChannels(), TD2DE::TD2DE_AUDIO.GetChunkSize()) < 0)
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
		TD2DE_DEBUG.LogMessage("[TD2DE_Engine]Mixer sucessfully initialized at settings, " + std::to_string(TD2DE::TD2DE_AUDIO.GetFrequency()) + ", " + std::to_string(TD2DE::TD2DE_AUDIO.GetChannels()) + ", " + std::to_string(TD2DE::TD2DE_AUDIO.GetChunkSize()), DEBUG_LOW);
		*/		

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
	{
		TD2DE::TD2DE_StartTimers(true, true);//TODO: give the option in the engine to choose not to cap fps or to not check fps
		TD2DE_DEBUG.LogMessage("[TD2DE_Engine]Timer initialization success!", DEBUG_LOW);
	}

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

	TD2DE::TD2DE_MAIN.engineRunning = true;

	TD2DE_DEBUG.LogMessage("[TD2DE_Engine]Engine started successfully!", DEBUG_LOW);

	return true;
}

void TD2DE::TD2DE_Engine::Stop()//TODO: add the rest of the stuff that needs to be shutdown before exit here
{
	TD2DE_DEBUG.LogMessage("[TD2DE_Engine]Shutting down engine...", DEBUG_HIGH);

	//cleanup all textures in storage
	TD2DE_DEBUG.LogMessage("[TD2DE_Engine]Clearing textures from list...", DEBUG_HIGH);
	TD2DE_TEXTURE.RemoveAllTextures();

	TD2DE::TD2DE_StopTimers(true, true);

	TD2DE_DEBUG.LogMessage("[TD2DE_Engine]Engine has shut down, shutting down debug logging...", DEBUG_LOW);

	TD2DE::TD2DE_DEBUG.Stop();

	TD2DE::TD2DE_MAIN.engineRunning = false;		
}


#endif