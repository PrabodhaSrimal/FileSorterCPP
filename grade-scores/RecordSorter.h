#pragma once

#include "Record.h"

class RecordSet;

/**
 * Interface for custom sort functions
 */
class RecordSorter
{
public:
	virtual ~RecordSorter(void) {}

	// sort the given data set in-place
	virtual void Sort(RecordSet * _pRecordSet) = 0;
};
