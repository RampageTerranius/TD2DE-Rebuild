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


	public:
		void SetDebugMode(eDebug newDebugMode);
		eDebug GetDebugMode();
		void SetDebugType(eDebugType newDebugType);
		eDebugType GetDebugType();
		void SetFileLocation(std::string location);
		void LogMessage(std::string error);

		std::string lastError;
	}TD2DE_DEBUG;
}

#endif