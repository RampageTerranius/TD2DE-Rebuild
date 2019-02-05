#include "TD2DE_Debug.h"
#include "TD2DE_Main.h"

#include <string>

TD2DE::eDebug TD2DE::TD2DE_Debug::GetDebugMode()
{
	return debugMode;
}

void TD2DE::TD2DE_Debug::SetDebugMode(TD2DE::eDebug newDebugMode)
{
	debugMode = newDebugMode;
}

TD2DE::eDebugType TD2DE::TD2DE_Debug::GetDebugType()
{
	return debugType;
}

void TD2DE::TD2DE_Debug::SetDebugType(TD2DE::eDebugType newDebugType)
{
	debugType = newDebugType;
}

void TD2DE::TD2DE_Debug::SetFileLocation(std::string location)
{
	if (!TD2DE_MAIN.EngineIsRunning())
	{
		if (TD2DE_DEBUG.GetDebugMode() >= TD2DE::eDebug::DEBUG_HIGH)
			TD2DE_DEBUG.LogMessage("[TD2DE_Debug]Debug file location has been set to: " +location);
		fileLocation = location;
	}
	else if (TD2DE_DEBUG.GetDebugMode() >= TD2DE::eDebug::DEBUG_HIGH)
		TD2DE_DEBUG.LogMessage("[TD2DE_Debug]Attempt to change debug file location while engine is running, this is not allowed");
}

