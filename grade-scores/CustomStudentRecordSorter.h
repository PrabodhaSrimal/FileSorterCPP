#pragma once
#include "recordsorter.h"
#include <string>

/**
 * Custom sort behavior implementation for StudentRecord s
 * 
 * - Orders the names by their score. 
 * - If scores are the same, order by their last name followed by first name
 * - Sorting score should be descending order
 * - Sorting names should be ascending order
 * - Text ordering should be case-insensitive
 */
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
