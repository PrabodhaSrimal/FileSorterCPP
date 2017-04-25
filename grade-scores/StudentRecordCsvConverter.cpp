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
		std::stringstream ss;
		ss << "Convert ERROR: Record is not StudentRecord";
		DEBUG_LOG << ss.str();
		throw(ss.str().c_str());
	}

	std::stringstream ssOut;
	ssOut << pStudentRecord->GetSurname() << ",";
	ssOut << pStudentRecord->GetFirstName() << ",";
	ssOut << pStudentRecord->GetScore();

	return ssOut.str();
}