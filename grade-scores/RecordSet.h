#pragma once

#include <vector>
#include <sstream>

class Record;

/**
 * Collection of Records 
 */
class RecordSet
{
public:
	typedef std::vector<Record*> Records;

	RecordSet(void);
	~RecordSet(void);

	Records::iterator Begin();
	Records::iterator End();

	void AddRecord(Record* _pRecord);
	void Print(std::stringstream & _ssBuf);

private:
	Records vec_Records;
};
