#pragma once

#include <string>

class InputFileReaderCallback
{
public:
	virtual ~InputFileReaderCallback() {}

	virtual void OnBOF(std::string _sFile) = 0;
	virtual void OnEOF(std::string _sFile) = 0;
	virtual void OnRowStart(int _iRowNumber, const std::string & _sRowData) = 0;
	virtual void OnRowEnd(int _iRowNumber) = 0;
	virtual void OnNewToken(int _iRowNumber, int _iTokenIndex, const std::string & _sTokenData) = 0;
};
