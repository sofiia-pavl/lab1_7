#include "Date.h"

void Date::SetYear(unsigned int value) {
	if (value > 2020 || value < 2001)
		value = 2020;
	this->year = value;
}

void Date::SetMonth(unsigned int value) {
	if (value > 12 || value < 1)
		value = 1;
	this->month = value;
}

bool Date::IsVysokostnyi() {
	if (year % 4 == 0)
		return true;
	else
		return false;
}

void Date::SetDay(unsigned int value) {
	int max = 31;
	if (month == 4 || month == 6 || month == 9 || month == 11)
		max = 30;
	else if (month == 2) {
		if (IsVysokostnyi())
			max = 29;
		else
			max = 28;
	}
	if (value > max || value < 1)
		value = 1;
	this->day = value;
}

void Date::InitNum(unsigned int year, unsigned int month, unsigned int day) {
	SetYear(year);
	SetMonth(month);
	SetDay(day);
}

void Date::Read() {
	unsigned int y, m, d;
	do {
		cout << " Enter year: "; cin >> y;
	} while (y > 2021 || y < 2001);

	do {
		cout << " Enter month: "; cin >> m;
	} while (m > 12 || m < 1);

	int max = 31;
	if (m == 4 || m == 6 || m == 9 || m == 11)
		max = 30;
	else if (m == 2) {
		if (y == 2004 || y == 2008 || y == 2012 || y == 2016 || y == 2020)
			max = 29;
		else
			max = 28;
	}

	do {
		cout << " Enter day: "; cin >> d;
	} while (d > max || d < 1);

	InitNum(y, m, d);
}

void Date::Display() {
	cout << endl << toString() << endl << endl;
}

string Date::toString() const {
	stringstream sout;
	sout << " " << day << "." << month << "." << year;
	return sout.str();
}

bool Date::IsEarlierThan(Date D2) {
	if (year == D2.year) {
		if (month == D2.month) {
			if (day == D2.day)
				return false;
			else if (day < D2.day)
				return true;
			else
				return false;
		}
		else if (month < D2.month)
			return true;
		else
			return false;
	}
	else if (year < D2.year)
		return true;
	else
		return false;
}

bool Date::IsSameAs(Date D2) {
	if (year == D2.year) {
		if (month == D2.month) {
			if (day == D2.day)
				return true;
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}

bool Date::IsLaterThan(Date D2) {
	if (IsEarlierThan(D2))
		return false;
	else if (!IsSameAs(D2))
		return true;
}

short Date::DaysInMonth(unsigned int month) {
	short amount = 31;
	if (month == 4 || month == 6 || month == 9 || month == 11)
		amount = 30;
	else if (month == 2) {
		if (IsVysokostnyi())
			amount = 29;
		else
			amount = 28;
	}
	return amount;
}

void Date::SubstractDays() {
	unsigned int substr;
	do {
		cout << " Enter how much days to substract: "; cin >> substr;
	} while (substr < 1 || substr > 7300);

	do {
		if (substr < day) {
			day = day - substr;
			substr = 0;
		}
		else {
			substr = substr - day;
			if (month == 1) {
				month = 12;
				year--;
			}
			else {
				month--;
				day = DaysInMonth(month);
			}
		}
	} while (substr != 0);
}

void Date::DateAfterDays() {
	unsigned int days;
	do {
		cout << " Enter how much days to add: "; cin >> days;
	} while (days < 1);

	short DaysInMonthLeft;
	do {
		DaysInMonthLeft = DaysInMonth(month) - day;
		if (days < DaysInMonthLeft) {
			day = day + days;
			days = 0;
		}
		else {
			day = day + DaysInMonthLeft;
			days = days - DaysInMonthLeft;
			if (month == 12) {
				month = 0;
				year++;
			}
			else {
				month++;
				day = 0;
			}
		}
	} while (days != 0);
}

unsigned int DaysBetweenAmount(Date D1, Date D2) {
	unsigned int answer = 0;
	if (D1.IsSameAs(D2))
		return answer;
	else if (D1.IsEarlierThan(D2)) {
		do {
			D1.day++;
			answer++;
			if (D1.day > D1.DaysInMonth(D1.month)) {
				D1.day = 1;
				if (D1.month == 12) {
					D1.month = 1;
					D1.year++;
				}
				else
					D1.month++;
			}
		} while (!D1.IsSameAs(D2));
	}
	else if (D2.IsEarlierThan(D1)) {
		do {
			D2.day++;
			answer++;
			if (D2.day > D2.DaysInMonth(D2.month)) {
				D2.day = 1;
				if (D2.month == 12) {
					D2.month = 1;
					D2.year++;
				}
				else
					D2.month++;
			}
		} while (!D2.IsSameAs(D2));
	}
	return answer;
}