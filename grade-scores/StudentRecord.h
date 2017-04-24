#pragma once
#include "record.h"

class StudentRecord : public Record
{
public:
	StudentRecord(void);
	virtual ~StudentRecord(void);

	void SetFirstName(const std::string & _sName);
	void SetSurname(const std::string & _sName);
	void SetScore(int _iScore);

	std::string GetFirstName() const;
	std::string GetSurname() const;
	int GetScore() const;

	void Print();

private:
	std::string s_FirstName;
	std::string s_Surname;
	int i_Score;
};
