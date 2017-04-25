#pragma once
#include "inputfilereader.h"

/**
 * Read given CSV file and process
 * Callback for each processing event
 */
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
