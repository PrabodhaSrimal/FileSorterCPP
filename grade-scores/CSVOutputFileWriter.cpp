#include "StdAfx.h"
#include "CSVOutputFileWriter.h"
#include <fstream>

CSVOutputFileWriter::CSVOutputFileWriter(std::string _sPath) :
	OutputWriter(),
	s_OutputPath(_sPath)
{
}

CSVOutputFileWriter::~CSVOutputFileWriter(void)
{
}

void CSVOutputFileWriter::Write(const std::string & _sContent)
{
	std::ofstream ofsOut(s_OutputPath.c_str());
	if(!ofsOut.is_open())
	{
		std::stringstream ss;
		ss << "Output File could not be open for write : " << s_OutputPath;
		DEBUG_LOG << ss.str();

		throw std::exception(ss.str().c_str());
	}

	ofsOut << _sContent;

	ofsOut.flush();
	ofsOut.close();
}