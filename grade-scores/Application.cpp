#include "StdAfx.h"
#include "Application.h"

#include "CSVInputFileReader.h"
#include "StudentRecordReader.h"
#include "CustomStudentRecordSorter.h"
#include "CSVOutputFileWriter.h"
#include "StudentRecordCsvConverter.h"

#include <algorithm>
#include <sstream>

Application::Application(std::string _sInputFile) : 
	s_InputFile(_sInputFile),
	p_RecordReader(NULL),
	p_RecordSet(NULL),
	p_RecordSorter(NULL),
	p_RecordWriter(NULL),
	p_RecordConverter(NULL)
{
	DEBUG_LOG << "Input file  : " << s_InputFile;
	DEBUG_LOG << "Output file : " << GetOutputFile();
}

Application::~Application(void)
{
	if(p_RecordReader)
		delete p_RecordReader;

	if(p_RecordSet)
		delete p_RecordSet;

	if(p_RecordSorter)
		delete p_RecordSorter;

	if(p_RecordWriter)
		delete p_RecordWriter;

	if(p_RecordConverter)
		delete p_RecordConverter;
}

void Application::Run()
{
	p_RecordSet = new RecordSet();

	// Read records from CSV file using record reader
	p_RecordReader = new StudentRecordReader(new CSVInputFileReader(s_InputFile));
	
	try
	{
		p_RecordReader->Read(p_RecordSet);
	}
	catch(std::exception & ex)
	{
		std::cerr << "ERROR: " << ex.what() << std::endl;
		return;
	}

	DEBUG_LOG << "un-sorted records";
	std::stringstream ss;
	p_RecordSet->Print(ss);
	DEBUG_LOG << ss.str();

	// sort records with our custom soriting logic
	p_RecordSorter = new CustomStudentRecordSorter();
	p_RecordSorter->Sort(p_RecordSet);

	DEBUG_LOG << "sorted records";
	ss.str("");
	p_RecordSet->Print(ss);
	DEBUG_LOG << ss.str();

	// store sorted records back into a CSV file
	p_RecordWriter = new RecordSetWriter(new CSVOutputFileWriter(GetOutputFile()));
	p_RecordConverter = new StudentRecordCsvConverter();

	try
	{
		p_RecordWriter->Write(p_RecordSet, p_RecordConverter);
	}
	catch(std::exception & ex)
	{
		std::cerr << "ERROR: " << ex.what() << std::endl;
	}
}


std::string Application::GetOutputFile()
{
	std::size_t iPos = s_InputFile.find_last_of('.');
	std::string sOutputFile;
	if(iPos != std::string::npos)
	{
		sOutputFile = s_InputFile.substr(0, iPos) + "-graded" + s_InputFile.substr(iPos);
	}
	else
	{
		sOutputFile = s_InputFile + "-graded";
	}

	return sOutputFile;
}
