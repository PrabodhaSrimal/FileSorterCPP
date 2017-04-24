#pragma once
#include "inputfilereader.h"

class CSVInputFileReader : public InputFileReader
{
public:
	CSVInputFileReader(std::string _sFilePath);
	virtual ~CSVInputFileReader(void);

	void ReadFile(InputFileReaderCallback * _pCallback);

private:
	// helper functions to std::string manipulations
	std::string & Trim(std::string &s);
	std::string & Ltrim(std::string &s);
	std::string & Rtrim(std::string &s);
};
