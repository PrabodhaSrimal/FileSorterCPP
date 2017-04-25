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
	vec_Records.push_back(_pRecord);
}

RecordSet::Records::iterator RecordSet::Begin()
{
	return vec_Records.begin();
}

RecordSet::Records::iterator RecordSet::End()
{
	return vec_Records.end();
}

void RecordSet::Print(std::stringstream & _ssBuf)
{
	for(Records::iterator ite = vec_Records.begin();
		ite != vec_Records.end();
		ite++)
	{
		(*ite)->Print(_ssBuf);
		_ssBuf << std::endl;
	}
}

