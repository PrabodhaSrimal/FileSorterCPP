// grade-scores.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "InputFileReader.h"
#include "CSVInputFileReader.h"
#include "RecordReader.h"
#include "StudentRecordReader.h"
#include "RecordSet.h"
#include "RecordSorter.h"
#include "CustomStudentRecordSorter.h"
#include "OutputWriter.h"
#include "CSVOutputFileWriter.h"
#include "RecordConverter.h"
#include "StudentRecordCsvConverter.h"
#include "RecordSetWriter.h"
#include <algorithm>

int main(int argc, char * argv[])
{
	if(argc != 2)
	{
		DEBUG_LOG << "Usage: grade-scores <input-file-name>";
		return -1;
	}

	std::string sInputFile = argv[1];
	std::size_t iPos = sInputFile.find_last_of('.');
	std::string sOutputFile;
	if(iPos != std::string::npos)
	{
		sOutputFile = sInputFile.substr(0, iPos) + "-graded" + sInputFile.substr(iPos);
	}
	else
	{
		sOutputFile = sInputFile + "-graded";
	}

	DEBUG_LOG << "Input file  : " << sInputFile;
	DEBUG_LOG << "Output file : " << sOutputFile;
	
	OutputWriter * pOutputWriter = new CSVOutputFileWriter(sOutputFile);

	RecordReader * pRecordReader = new StudentRecordReader(new CSVInputFileReader(sInputFile));
	RecordConverter * pRecordConverter = new StudentRecordCsvConverter();

	

	RecordSet * pRecordSet = new RecordSet();

	pRecordReader->Read(pRecordSet);
	DEBUG_LOG << "un-sorted records";
	pRecordSet->Print();

	RecordSorter * pRecordSorter = new CustomStudentRecordSorter();
	pRecordSorter->Sort(pRecordSet);

	DEBUG_LOG << "Sorted records";
	pRecordSet->Print();

	RecordSetWriter * pRecordWriter = new RecordSetWriter(new CSVOutputFileWriter(sOutputFile));
	pRecordWriter->Write(pRecordSet, pRecordConverter);

	delete pRecordSet;
	delete pRecordSorter;
	delete pRecordReader;
	delete pRecordConverter;
	delete pRecordWriter;

	return 0;
}

