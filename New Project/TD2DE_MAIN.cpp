#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include "TD2DE_Main.h"
#include "TD2DE_Texture.h"

void TD2DE::TD2DE_Main::StartEngine()
{

}

void TD2DE::TD2DE_Main::ShutdownEngine()
{
	//cleanup all textures in storage
	int val = TD2DE_TEXTURE.TotalLoadedTextures();
	for (int i = 0; i < val; i++)
	{
		//TODO: log debug data here
		TD2DE_TEXTURE.RemoveAllTextures();
	}
}