#ifndef _TD2DE_DEBUG_
#define _TD2DE_DEBUG_

#include <string>
#include <fstream>

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
		std::ofstream file;

		bool StartLogging();
		bool StopLogging();

	public:
		TD2DE_Debug();

		void SetDebugMode(eDebug newDebugMode);
		eDebug GetDebugMode();
		void SetDebugType(eDebugType newDebugType);
		eDebugType GetDebugType();
		void SetFileLocation(std::string location);
		void LogMessage(std::string message, eDebug debugLevel);

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

void TD2DE::TD2DE_Debug::LogMessage(std::string message, eDebug debugLevel)
{
	if (currentlyLogging && debugMode >= debugLevel)
	{
		//push given error message to file
		file << message.data() << "\n";
		
		file.flush();
	}
}

bool TD2DE::TD2DE_Debug::StartLogging()
{
	file.open(fileLocation, std::ios::out | std::ios::trunc);

	if (!file.is_open())
	{
		TD2DE::TD2DE_DEBUG.LogMessage("[TD2DE_Debug]debug file failed to open", DEBUG_LOW);
		return false;
	}

	TD2DE::TD2DE_DEBUG.LogMessage("[TD2DE_Debug]Debug logging has been started", DEBUG_LOW);
	return true;
}

bool TD2DE::TD2DE_Debug::StopLogging()
{
	if (!file.is_open())
	{
		TD2DE::TD2DE_DEBUG.LogMessage("[TD2DE_Debug]debug file is not open, can not close file", DEBUG_LOW);
		return false;
	}

	TD2DE::TD2DE_DEBUG.LogMessage("[TD2DE_Debug]Debug logging has been stopped", DEBUG_LOW);

	file.flush();
	file.close();		

	return true;
}

bool TD2DE::TD2DE_Debug::Start()
{
	if (currentlyLogging)
	{
		TD2DE::TD2DE_DEBUG.LogMessage("[TD2DE_Debug]Attempt to start logging when it is already running", DEBUG_MEDIUM);
		return false;
	}

	if (fileLocation == "")
	{
		TD2DE::TD2DE_DEBUG.LogMessage("[TD2DE_Debug]Attempt to start logging when no file location has been given", DEBUG_MEDIUM);
		return false;
	}

	if (!StartLogging())
	{
		TD2DE::TD2DE_DEBUG.LogMessage("[TD2DE_Debug]Failed to start logging", DEBUG_LOW);
		return false;
	}

	currentlyLogging = true;
	TD2DE::TD2DE_DEBUG.LogMessage("[TD2DE_Debug]Debug logging started!", DEBUG_MEDIUM);

	return true;
}

bool TD2DE::TD2DE_Debug::Stop()
{
	if (!currentlyLogging)
	{
		TD2DE::TD2DE_DEBUG.LogMessage("[TD2DE_Debug]Attempt to stop logging when it is not running", DEBUG_MEDIUM);
		return false;
	}
	
	TD2DE::TD2DE_DEBUG.LogMessage("[TD2DE_Debug]stopping debug logging...", DEBUG_MEDIUM);

	if (!StopLogging())
	{
		TD2DE::TD2DE_DEBUG.LogMessage("[TD2DE_Debug]Failed to stop logging", DEBUG_LOW);
		return false;
	}

	
	currentlyLogging = false;

	return true;
}

#endif