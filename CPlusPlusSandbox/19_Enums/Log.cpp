#include <iostream>

class Log
{
public:
	enum Level : unsigned char
	{
		LevelError = 0, LevelWarning, LevelInfo
	};


private:
	Level m_logLevel = LevelInfo;

public:
	void SetLevel(Level level)
	{
		m_logLevel = level;
	}

	void Error(const char* message)
	{
		if (m_logLevel >= LevelError)
			std::cout << "[ERROR]: " << message << std::endl;
	}

	void Warn(const char* message)
	{
		if (m_logLevel >= LevelWarning)
			std::cout << "[WARNING]: " << message << std::endl;
	}

	void Info(const char* message)
	{
		if (m_logLevel >= LevelInfo)
			std::cout << "[INFO]: " << message << std::endl;
	}
};