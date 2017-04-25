#pragma once

class RecordSet;
class RecordConverter; 
class OutputWriter;

/**
 * Write given RecordSet into destination using given OutputWriter 
 * Records should first convert into string with given RecordConverter
 */
class RecordSetWriter
{
public:
	RecordSetWriter(OutputWriter * _pOutputWriter);
	virtual ~RecordSetWriter(void);

	void Write(RecordSet * _pRecordSet, RecordConverter * _pConverter);

private:
	OutputWriter * p_OutputWriter;
};
