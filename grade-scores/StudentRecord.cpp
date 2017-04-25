#include "StdAfx.h"
#include "StudentRecord.h"
#include <sstream>

StudentRecord::StudentRecord(void) : Record()
{
}

StudentRecord::~StudentRecord(void)
{
}

std::string StudentRecord::GetFirstName() const
{
	return s_FirstName;
}

std::string StudentRecord::GetSurname() const
{
	return s_Surname;
}

int StudentRecord::GetScore() const
{
	return i_Score;
}

void StudentRecord::SetFirstName(const std::string & _sName)
{
	s_FirstName = _sName;
}

void StudentRecord::SetSurname(const std::string & _sName)
{
	s_Surname = _sName;
}

void StudentRecord::SetScore(int _iScore)
{
	i_Score = _iScore;
}

void StudentRecord::Print(std::stringstream & _ssBuf)
{
	_ssBuf << "FirstName=" << s_FirstName << "|Surname=" << s_Surname << "|Score=" << i_Score;
}
