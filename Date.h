#pragma once
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Date
{
private:
	unsigned int year, month, day;
public:
	unsigned int GetYear() const { return year; };
	unsigned int GetMonth() const { return month; };
	unsigned int GetDay() const { return day; };

	void SetYear(unsigned int);
	void SetMonth(unsigned int);
	void SetDay(unsigned int);

	void InitNum(unsigned int, unsigned int, unsigned int);
	void Read();
	void Display();
	string toString() const;

	bool IsVysokostnyi();
	bool IsEarlierThan(Date);
	bool IsSameAs(Date);
	bool IsLaterThan(Date);

	short DaysInMonth(unsigned int);

	void SubstractDays();
	void DateAfterDays();

	friend unsigned int DaysBetweenAmount(Date, Date);
};

