#include "StdAfx.h"
#include "RecordSet.h"
#include "StudentRecord.h"
#include "CustomStudentRecordSorter.h"
#include <algorithm>

CustomStudentRecordSorter::CustomStudentRecordSorter(void)
{
}

CustomStudentRecordSorter::~CustomStudentRecordSorter(void)
{
}

void CustomStudentRecordSorter::Sort(RecordSet * _pRecordSet)
{
	std::sort(_pRecordSet->Begin(), _pRecordSet->End(), *this);
}

bool CustomStudentRecordSorter::operator ()(const Record * _rhs, const Record * _lhs)
{
	const StudentRecord * rhs = dynamic_cast<const StudentRecord*>(_rhs);
	const StudentRecord * lhs = dynamic_cast<const StudentRecord*>(_lhs);

	if(rhs->GetScore() > lhs->GetScore())
		return true;
	else if(rhs->GetScore() < lhs->GetScore())
		return false;

	if(ToUpper(rhs->GetSurname()) < ToUpper(lhs->GetSurname()))
		return true;
	else if(ToUpper(rhs->GetSurname()) > ToUpper(lhs->GetSurname()))
		return false;
	
	if(ToUpper(rhs->GetFirstName()) < ToUpper(lhs->GetFirstName()))
		return true;

	return false;
}

// Convert text to uppercase and trim
std::string & CustomStudentRecordSorter::ToUpper(std::string & _s)
{
	std::transform(_s.begin(), _s.end(), _s.begin(), ::toupper);
	return _s;
}