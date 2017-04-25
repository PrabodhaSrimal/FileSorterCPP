#pragma once

#include <string>

class Record;

/**
 * Convert given Record to a std::string representation
 */
class RecordConverter
{
public:
	RecordConverter() {}
	virtual ~RecordConverter() {}

	virtual std::string Convert(Record * _pRecord) = 0;
};