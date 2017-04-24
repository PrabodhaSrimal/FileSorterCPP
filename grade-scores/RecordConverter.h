#pragma once

class Record;

class RecordConverter
{
public:
	RecordConverter() {}
	virtual ~RecordConverter() {}

	virtual std::string Convert(Record * _pRecord) = 0;
};