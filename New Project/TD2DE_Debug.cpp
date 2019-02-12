#include "TD2DE_Debug.h"
#include "TD2DE_Main.h"

#include <string>


TD2DE::TD2DE_Debug::TD2DE_Debug()
{
	debugMode = DEBUG_NONE;
	debugType = DEBUGTYPE_TOFILEONLY;
	fileLocation = "";
	commandConsoleDebugLevel = DEBUG_NONE;
}

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
	fileLocation = location;
}

void TD2DE::TD2DE_Debug::LogMessage(std::string message)
{

}