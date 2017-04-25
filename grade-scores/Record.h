#pragma once

#include <sstream>

/**
 * Interface for Record data 
 */
class Record
{
public:
	Record() {}
	virtual ~Record() {}

	virtual void Print(std::stringstream & _ssBuf) = 0;
};
