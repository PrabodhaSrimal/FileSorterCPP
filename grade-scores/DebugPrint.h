#pragma once

#include <sstream>
#include <string>
#include <stdio.h>

/**
 * Simple console debug logging class with stream support
 * Use:
 *	DEBUG_LOG << "log message " << with_params << "." ;
 */
class DebugLog
{
public:
    DebugLog();
    virtual ~DebugLog();

    std::ostringstream& Out();
	std::ostringstream& Error();

protected:
    std::ostringstream ossOut;
	FILE* pStream;
private:
    DebugLog(const DebugLog&);
    DebugLog& operator =(const DebugLog&);

	void Print(const std::string& _log);
};

inline DebugLog::DebugLog()
{
	FILE* pStream = stdout;
}

inline DebugLog::~DebugLog()
{
    ossOut << std::endl;
    Print(ossOut.str());
}

// Write to console only in Debug Mode
inline void DebugLog::Print(const std::string& _log)
{
#ifndef NDEBUG
	fprintf(pStream, "%s", _log.c_str());
	fflush(pStream);
#endif
}

// log to stdout
inline std::ostringstream& DebugLog::Out()
{
	pStream = stdout;
	return ossOut;
}

// log to stderror
inline std::ostringstream& DebugLog::Error()
{
	pStream = stderr;
	return ossOut;
}

#define DEBUG_LOG DebugLog().Out()
#define ERROR_LOG DebugLog().Error()
