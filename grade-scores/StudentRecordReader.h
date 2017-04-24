#pragma once

#include "RecordReader.h"
#include <string>

class StudentRecord;
class RecordSet;
class InputFileReader;

class StudentRecordReader : public RecordReader
{
	enum StudentRecordIndex
	{
		FirstName = 0,
		Surname,
		Score
	};

public:
	StudentRecordReader(InputFileReader * _pFileReader);
	virtual ~StudentRecordReader(void);

	void Read(RecordSet * _pRecordSet);

	void OnBOF(std::string _sFile);
	void OnEOF(std::string _sFile);
	void OnRowStart(int _iRowNumber, const std::string & _sRowData);
	void OnRowEnd(int _iRowNumber);
	void OnNewToken(int _iRowNumber, int _iTokenIndex, const std::string & _sTokenData);

private:
	StudentRecord * p_CurrentRecord;
	RecordSet * p_Recordset;
};
