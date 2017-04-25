#pragma once
#include "outputwriter.h"
#include <string>

/**
 * Write given RecordSet into CSV file  
 */
class CSVOutputFileWriter : public OutputWriter
{
public:
	CSVOutputFileWriter(std::string _sPath);
	virtual ~CSVOutputFileWriter(void);

	void Write(const std::string & _sContent);

private:
	std::string s_OutputPath;
};
