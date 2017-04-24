#include "StdAfx.h"
#include "InputFileReader.h"
#include "RecordSet.h"

#include "StudentRecordReader.h"

#include "StudentRecord.h"

StudentRecordReader::StudentRecordReader(InputFileReader * _pFileReader) :
	RecordReader(_pFileReader),
	p_CurrentRecord(NULL),
	p_Recordset(NULL)
{
}

StudentRecordReader::~StudentRecordReader(void)
{
}

void StudentRecordReader::Read(RecordSet * _pRecordSet)
{
	p_Recordset = _pRecordSet;
	p_FileReader->ReadFile(this);
}

void StudentRecordReader::OnBOF(std::string _sFile)
{
	DEBUG_LOG << "OnBOF : " << _sFile;
}

void StudentRecordReader::OnEOF(std::string _sFile)
{
	DEBUG_LOG << "OnEOF : " << _sFile;
}

void StudentRecordReader::OnRowStart(int _iRowNumber, const std::string & _sRowData)
{
	DEBUG_LOG << "OnRowStart : [" << _iRowNumber << "] [" << _sRowData << "]" ;
	p_CurrentRecord = new StudentRecord();
}

void StudentRecordReader::OnRowEnd(int _iRowNumber)
{
	DEBUG_LOG << "OnRowEnd : [" << _iRowNumber << "]" ;
	p_Recordset->AddRecord(p_CurrentRecord);
}

void StudentRecordReader::OnNewToken(int _iRowNumber, int _iTokenIndex, const std::string & _sTokenData)
{
	DEBUG_LOG << "OnNewToken : [" << _iRowNumber << "," << _iTokenIndex << "] [" << _sTokenData << "]" ;
	switch(_iTokenIndex)
	{
	case FirstName:
		p_CurrentRecord->SetFirstName(_sTokenData);
		break;
	case Surname:
		p_CurrentRecord->SetSurname(_sTokenData);
		break;
	case Score:
		p_CurrentRecord->SetScore(atoi(_sTokenData.c_str()));
		break;
	default:
		break;
	}
}