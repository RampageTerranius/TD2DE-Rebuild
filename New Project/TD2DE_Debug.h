#ifndef _TD2DE_DEBUG_
#define _TD2DE_DEBUG_

#include <string>

namespace TD2DE
{
	enum eDebug
	{
		DEBUG_NONE,
		DEBUG_LOW,
		DEBUG_MEDIUM,
		DEBUG_HIGH
	};

	enum eDebugType
	{
		DEBUGTYPE_TOFILEONLY,
		DEBUGTYPE_TOCONSOLEONLY,
		DEBUGTYPE_TOFILEANDCONSOLE
	};

	class TD2DE_Debug
	{
	private:
		eDebug debugMode;//the level of detail to show in logs
		eDebugType debugType;//where the logs are sent to
		std::string fileLocation;
		eDebug commandConsoleDebugLevel;//the command console will only show logs that are <= to this given level
		bool currentlyLogging;		

	public:
		TD2DE_Debug();

		void SetDebugMode(eDebug newDebugMode);
		eDebug GetDebugMode();
		void SetDebugType(eDebugType newDebugType);
		eDebugType GetDebugType();
		void SetFileLocation(std::string location);
		void LogMessage(std::string message);

		bool Start();
		bool Stop();

		std::string lastError;
	}TD2DE_DEBUG;
}

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

bool TD2DE::TD2DE_Debug::Start()
{
	if (currentlyLogging)
	{
		if (TD2DE::TD2DE_DEBUG.GetDebugMode() >= eDebug::DEBUG_MEDIUM)
			TD2DE::TD2DE_DEBUG.LogMessage("[TD2DE_Debug]Attempt to start logging when it is already running");
		return false;
	}

	if (fileLocation == "")
	{
		if (TD2DE::TD2DE_DEBUG.GetDebugMode() >= eDebug::DEBUG_MEDIUM)
			TD2DE::TD2DE_DEBUG.LogMessage("[TD2DE_Debug]Attempt to start logging when no file location has been given");
		return false;
	}


}

bool TD2DE::TD2DE_Debug::Stop()
{
	if 
}

#endif