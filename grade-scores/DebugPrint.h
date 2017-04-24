#pragma once

#include <sstream>
#include <string>
#include <stdio.h>

//// Debug log macros 
//#ifndef NDEBUG
//#define DEBUG_LOG(exp) do {\
//	std::cout << exp << std::endl;\
//	} while(0);
//#else
//#define DEBUG_LOG(exp)
//#endif


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

inline void DebugLog::Print(const std::string& _log)
{
	fprintf(pStream, "%s", _log.c_str());
	fflush(pStream);
}

inline std::ostringstream& DebugLog::Out()
{
	pStream = stdout;
	return ossOut;
}

inline std::ostringstream& DebugLog::Error()
{
	pStream = stderr;
	return ossOut;
}


// Debug log macros 
#ifndef NDEBUG
#define DEBUG_LOG DebugLog().Out()
#else
#define DEBUG_LOG
#endif