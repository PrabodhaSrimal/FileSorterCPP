#pragma once

#include <string>
#include "InputFileReader.h"
#include "RecordReader.h"
#include "RecordSet.h"
#include "RecordSorter.h"
#include "RecordSetWriter.h"
#include "OutputWriter.h"
#include "RecordConverter.h"

class Application
{
public:
	Application(std::string _sInputFile);
	~Application(void);

	void Run();

private:
	std::string GetOutputFile();

	std::string s_InputFile;
	
	RecordReader * p_RecordReader;
	RecordSet * p_RecordSet;
	RecordSorter * p_RecordSorter;
	RecordSetWriter * p_RecordWriter;
	RecordConverter * p_RecordConverter;
};
