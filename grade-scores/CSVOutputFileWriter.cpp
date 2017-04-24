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
		DEBUG_LOG << "Output File could not be open : " << s_OutputPath;
		return;
	}

	ofsOut << _sContent;

	ofsOut.flush();
	ofsOut.close();
}