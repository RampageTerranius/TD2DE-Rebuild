#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include "TD2DE_Debug.h"
#include "TD2DE_Main.h"
#include "TD2DE_Texture.h"


void TD2DE::TD2DE_Main::StartEngine()
{
	engineRunnning = true;
}

void TD2DE::TD2DE_Main::ShutdownEngine()
{
	//cleanup all textures in storage
	int val = TD2DE_TEXTURE.TotalLoadedTextures();
	if (TD2DE_DEBUG.GetDebugMode() >= TD2DE::eDebug::DEBUG_HIGH)	
		TD2DE_DEBUG.LogMessage("[TD2DE_Main]Shutting down engine...");
	

	if (TD2DE_DEBUG.GetDebugMode() >= TD2DE::eDebug::DEBUG_HIGH)
		TD2DE_DEBUG.LogMessage("[TD2DE_Main]Clearing textures from list...");

	for (int i = 0; i < val; i++)			
		TD2DE_TEXTURE.RemoveAllTextures();
	

	engineRunnning = false;
}

bool TD2DE::TD2DE_Main::EngineIsRunning()
{
	return engineRunnning;
}