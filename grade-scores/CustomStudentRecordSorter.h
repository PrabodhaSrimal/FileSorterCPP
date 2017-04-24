#pragma once
#include "recordsorter.h"
#include <string>

class CustomStudentRecordSorter : public RecordSorter
{
public:
	CustomStudentRecordSorter(void);
	virtual ~CustomStudentRecordSorter(void);

	void Sort(RecordSet * _pRecordSet);

	bool operator ()(const Record * _rhs, const Record * _lhs);

private:
	std::string & ToUpper(std::string & _s);
};
