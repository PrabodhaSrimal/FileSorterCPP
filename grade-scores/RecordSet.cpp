#include "StdAfx.h"
#include "Record.h"

#include "RecordSet.h"

#include <algorithm>

RecordSet::RecordSet(void)
{
}

RecordSet::~RecordSet(void)
{
}

void RecordSet::AddRecord(Record* _pRecord)
{
	lst_Records.push_back(_pRecord);
}

RecordSet::Records::iterator RecordSet::Begin()
{
	return lst_Records.begin();
}

RecordSet::Records::iterator RecordSet::End()
{
	return lst_Records.end();
}

void RecordSet::Print()
{
	for(Records::iterator ite = lst_Records.begin();
		ite != lst_Records.end();
		ite++)
	{
		(*ite)->Print();
	}
}

//void RecordSet::Read(InputFileReader * _pReader)
//{
//	Record * pRec = _pReader->ReadRecord();
//	while(pRec)
//	{
//		lst_Records.push_back(pRec);
//		pRec = _pReader->ReadRecord();
//	}
//}
//
//void RecordSet::Write(OutoutFileWriter * _pWriter)
//{
//	_pWriter->Write(this);
//}
//
//void RecordSet::Sort(RecordSorter * _pSorter)
//{
//	std::sort(lst_Records.begin(), lst_Records.end(), _pSorter->operator ());
//}
