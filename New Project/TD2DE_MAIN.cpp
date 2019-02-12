#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include "TD2DE_Debug.h"
#include "TD2DE_Main.h"
#include "TD2DE_Texture.h"

bool TD2DE::TD2DE_Main::EngineIsRunning()
{
	return engineRunnning;
}
