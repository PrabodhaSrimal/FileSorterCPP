#pragma once

class RecordSet;
class RecordConverter; 
class OutputWriter;

class RecordSetWriter
{
public:
	RecordSetWriter(OutputWriter * _pOutputWriter);
	virtual ~RecordSetWriter(void);

	void Write(RecordSet * _pRecordSet, RecordConverter * _pConverter);

private:
	OutputWriter * p_OutputWriter;
};
