#include "Main.h"

int main(int argc, char *argv[])
{
	TD2DE::TD2DE_DEBUG.SetDebugMode(TD2DE::DEBUG_HIGH);
	TD2DE::TD2DE_DEBUG.SetFileLocation("debug.txt");
	
	TD2DE::TD2DE_RENDER.SetScreenWidth(640);
	TD2DE::TD2DE_RENDER.SetScreenHeight(480);
	TD2DE::TD2DE_RENDER.SetFrameRateLimit(60);

	TD2DE::TD2DE_ENGINE.Start();


	while (TD2DE::TD2DE_MAIN.EngineIsRunning())
	{
		TD2DE::TD2DE_TimeHandle();
		TD2DE::TD2DE_EventHandle();
	}

	TD2DE::TD2DE_ENGINE.Stop();

	return 0;
}