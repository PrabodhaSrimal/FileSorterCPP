#pragma once

class OutputWriter
{
public:
	OutputWriter(void) {}
	virtual ~OutputWriter(void) {}

	virtual void Write(const std::string & _sContent) = 0;
};
