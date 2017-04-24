#pragma once

#include <string>

class Record
{
public:
	Record() {}
	virtual ~Record() {}

	virtual void Print() = 0;
};
