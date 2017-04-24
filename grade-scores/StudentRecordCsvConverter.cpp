#include "StdAfx.h"
#include "StudentRecordCsvConverter.h"
#include "StudentRecord.h"

StudentRecordCsvConverter::StudentRecordCsvConverter(void)
{
}

StudentRecordCsvConverter::~StudentRecordCsvConverter(void)
{
}

std::string StudentRecordCsvConverter::Convert(Record * _pRecord)
{
	StudentRecord * pStudentRecord = dynamic_cast<StudentRecord*>(_pRecord);
	if(!pStudentRecord)
	{
		DEBUG_LOG << "Record to StudentRecord convert error";
		return "Convert ERROR!!!";
	}

	std::stringstream ssOut;
	ssOut << pStudentRecord->GetSurname() << ",";
	ssOut << pStudentRecord->GetFirstName() << ",";
	ssOut << pStudentRecord->GetScore();

	return ssOut.str();
}