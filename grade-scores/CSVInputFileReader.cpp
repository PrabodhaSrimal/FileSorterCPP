#include "StdAfx.h"
#include "CSVInputFileReader.h"

#include <stdio.h>
#include <stdlib.h>
#include <cctype>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <functional>

CSVInputFileReader::CSVInputFileReader(std::string _sFilePath) : InputFileReader(_sFilePath)
{
}

CSVInputFileReader::~CSVInputFileReader(void)
{
}

void CSVInputFileReader::ReadFile(InputFileReaderCallback * _pCallback)
{
	std::ifstream ifsCsvFile(s_FilePath.c_str());
	if(!ifsCsvFile.is_open())
	{
		DEBUG_LOG << "File " << s_FilePath << " not found!";
		return;	
	}

	_pCallback->OnBOF(s_FilePath);

	int iRowNumber = 0;
	std::string sLine;

	while(!ifsCsvFile.eof())
	{
		std::getline(ifsCsvFile, sLine);
		if(sLine.empty())
			continue;

		_pCallback->OnRowStart(iRowNumber, sLine);
		int iTokenIndex = 0;

		std::istringstream iss(Trim(sLine));
		std::string sToken;    
		while (getline(iss, sToken, ',')) 
		{
			_pCallback->OnNewToken(iRowNumber, iTokenIndex, Trim(sToken));
			iTokenIndex++;
		}

		_pCallback->OnRowEnd(iRowNumber);
		iRowNumber++;
	}
	_pCallback->OnEOF(s_FilePath);
	ifsCsvFile.close();
}

// trim from both ends
std::string & CSVInputFileReader::Trim(std::string &_s)
{
	return Ltrim(Rtrim(_s));
}

// trim from start
std::string & CSVInputFileReader::Ltrim(std::string &_s)
{
	_s.erase(_s.begin(), std::find_if(_s.begin(), _s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
	return _s;
}

// trim from end
std::string & CSVInputFileReader::Rtrim(std::string &_s)
{
	_s.erase(std::find_if(_s.rbegin(), _s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), _s.end());
	return _s;
}