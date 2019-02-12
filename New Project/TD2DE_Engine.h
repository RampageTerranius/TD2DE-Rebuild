#ifndef _TD2DE_ENGINE_
#define _TD2DE_ENGINE_

#include "TD2DE_Main.h"

namespace TD2DE
{
	class TD2DE_Engine
	{
	public:
		void Start();
		void Stop();
	}TD2DE_ENGINE;

	void TD2DE::TD2DE_Engine::Start()
	{
		//TODO: start the engine here
		TD2DE::TD2DE_MAIN.engineRunning = true;
	}

	void TD2DE::TD2DE_Engine::Stop()
	{
		//cleanup all textures in storage
		int val = TD2DE_TEXTURE.TotalLoadedTextures();
		if (TD2DE_DEBUG.GetDebugMode() >= TD2DE::eDebug::DEBUG_HIGH)
			TD2DE_DEBUG.LogMessage("[TD2DE_Main]Shutting down engine...");


		if (TD2DE_DEBUG.GetDebugMode() >= TD2DE::eDebug::DEBUG_HIGH)
			TD2DE_DEBUG.LogMessage("[TD2DE_Main]Clearing textures from list...");

		for (int i = 0; i < val; i++)
			TD2DE_TEXTURE.RemoveAllTextures();


		TD2DE::TD2DE_MAIN.engineRunning = false;
	}

}


#endif