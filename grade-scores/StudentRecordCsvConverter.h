#pragma once
#include "recordconverter.h"

class StudentRecordCsvConverter : public RecordConverter
{
public:
	StudentRecordCsvConverter(void);
	virtual ~StudentRecordCsvConverter(void);

	std::string Convert(Record * _pRecord);
};
