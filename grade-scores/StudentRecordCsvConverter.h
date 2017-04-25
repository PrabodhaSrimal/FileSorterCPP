#pragma once
#include "recordconverter.h"

/**
 * Convert given StudentRecord to a string representation
 */
class StudentRecordCsvConverter : public RecordConverter
{
public:
	StudentRecordCsvConverter(void);
	virtual ~StudentRecordCsvConverter(void);

	std::string Convert(Record * _pRecord);
};
