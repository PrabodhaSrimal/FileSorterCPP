#pragma once

#include "stdafx.h"
#include "InputFileReaderCallback.h"

/**
 * Read given file and generate data structure using Builder design pattern
 */
class InputFileReader
{
public:
	InputFileReader(std::string _sFilePath) : s_FilePath(_sFilePath) {}
	virtual ~InputFileReader() {}

	virtual void ReadFile(InputFileReaderCallback * _pCallback) = 0;

protected: 
	std::string s_FilePath;
};
