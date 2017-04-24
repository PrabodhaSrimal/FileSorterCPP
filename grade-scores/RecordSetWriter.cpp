#include "StdAfx.h"
#include "RecordSet.h"
#include "RecordConverter.h"
#include "OutputWriter.h"
#include "RecordSetWriter.h"
#include <sstream>

RecordSetWriter::RecordSetWriter(OutputWriter * _pOutputWriter) :
	p_OutputWriter(_pOutputWriter)
{
}

RecordSetWriter::~RecordSetWriter(void)
{
}

void RecordSetWriter::Write(RecordSet * _pRecordSet, RecordConverter * _pConverter)
{
	RecordSet::Records::iterator ite = _pRecordSet->Begin();
	RecordSet::Records::iterator iteEnd = _pRecordSet->End();

	std::stringstream ssOut;
	for(; ite != iteEnd; ite++)
	{
		ssOut << _pConverter->Convert(*ite) << std::endl;
	}

	p_OutputWriter->Write(ssOut.str());
}
