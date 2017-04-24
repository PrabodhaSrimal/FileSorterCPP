#pragma once

#include <vector>

class Record;

class RecordSet
{
public:
	typedef std::vector<Record*> Records;

	RecordSet(void);
	~RecordSet(void);

	Records::iterator Begin();
	Records::iterator End();

	void AddRecord(Record* _pRecord);
	void Print();

private:
	Records lst_Records;
};
