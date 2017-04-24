#pragma once

#include "Record.h"

class RecordSet;

class RecordSorter
{
public:
	virtual ~RecordSorter(void) {}

	virtual void Sort(RecordSet * _pRecordSet) = 0;
};
