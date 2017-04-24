#pragma once

#include "InputFileReaderCallback.h"

class InputFileReader;
class RecordSet;

class RecordReader : public InputFileReaderCallback
{
public:
	RecordReader(InputFileReader * _pFileReader) : p_FileReader(_pFileReader) {}
	virtual ~RecordReader() { if(p_FileReader) delete p_FileReader; }

	virtual void Read(RecordSet * _pRecordSet) = 0;

protected:
	InputFileReader * p_FileReader;
};
