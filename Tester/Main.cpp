#include "Main.h"

int main(int argc, char *argv[])
{
	TD2DE::TD2DE_DEBUG.SetDebugMode(TD2DE::DEBUG_HIGH);
	TD2DE::TD2DE_DEBUG.SetFileLocation("debug.txt");
	
	TD2DE::TD2DE_RENDER.SetScreenWidth(640);
	TD2DE::TD2DE_RENDER.SetScreenHeight(480);

	TD2DE::TD2DE_ENGINE.Start();

	TD2DE::TD2DE_ENGINE.Stop();

	return 0;
}