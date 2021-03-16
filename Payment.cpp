#include "Payment.h"

void Payment::SetStavka(double v) {
	if (v < 2000)
		v = 2000;
	this->stavka = v;
}

void Payment::SetNadbavkaProc(short v) {
	if (v > 100 || v < 0) {
		v = 0;
	}
	this->nadbavkaProc = v;
}

void Payment::SetAmountRob(short v) {
	if (v < 1 || v > data.DaysInMonth(data.GetMonth())) {
		v = 14;
	}
	this->amountRob = v;
}

void Payment::SetAmountVidprac(short v) {
	if (v < 1 || v > data.DaysInMonth(data.GetMonth())) {
		v = 1;
	}
	this->amountVidprac = v;
}

void Payment::SetSumNarah(double v) {
	if (v < 2000)
		v = 2000;
	this->SumNarah = v;
}

void Payment::SetSumUtrym(double v) {
	if (v < 100)
		v = 100;
	this->SumUtrym = v;
}

short Payment::CountExpirience(Date D2) {
	short answer = 0;
	if (D2.IsEarlierThan(data)) {
		cout << " ERROR" << endl;
		exit(0);
	}
	else if (data.IsEarlierThan(D2)) {
		unsigned int days = DaysBetweenAmount(data, D2);
		answer = days / 365;
	}
	else if (data.IsSameAs(D2)) {
		return 0;
	}
	return answer;
}

void Payment::Init(string n, string s, double stavka, Date D1, short nadbavkaproc, short amountRob, short amountVidprac) {
	SetName(n);
	SetSurname(s);
	SetStavka(stavka);
	SetDate(D1);
	SetNadbavkaProc(nadbavkaproc);
	SetAmountRob(amountRob);
	SetAmountVidprac(amountVidprac);
}

void Payment::Read() {
	string n, s;
	cout << " Enter name: "; cin >> n;
	cout << " Enter surname: "; cin >> s;

	unsigned int stavka;
	do {
		cout << " Enter stavka: "; cin >> stavka;
	} while (stavka < 2000);

	Date D1;
	cout << " Enter date of hiring:" << endl;
	D1.Read();

	short nadbavka;
	do {
		cout << " Enter nadbavka: "; cin >> nadbavka;
	} while (nadbavka > 100 || nadbavka < 0);

	short amountRob;
	do {
		cout << " Enter number of working days: "; cin >> amountRob;
	} while (amountRob < 1 || amountRob > data.DaysInMonth(data.GetMonth()));

	short amountVidprac;
	do {
		cout << " Enter number of worked days: "; cin >> amountVidprac;
	} while (amountVidprac < 1 || amountVidprac > data.DaysInMonth(data.GetMonth()));

	Init(n, s, stavka, D1, nadbavka, amountRob, amountVidprac);
}

string Payment::toString() const {
	stringstream sout;
	sout << endl << " Name: " << name << " " << surname << endl
		<< " Month stavka: " << stavka << " uah." << endl
		<< " Date of hiring: " << data.GetDay() << "." << data.GetMonth() << "." << data.GetYear() << endl
		<< " Number of working days in the month: " << amountRob << endl
		<< " Number of worked days in the month: " << amountVidprac << endl
		<< " Nadbavka percent: " << nadbavkaProc << " %" << endl;
	return sout.str();
}

void Payment::Display() {
	cout << toString() << endl;
}

double Payment::AmountSumNarah() {
	return stavka / amountRob * amountVidprac + stavka * (nadbavkaProc / 100);
}

double Payment::PrybotkovyiPodatok() {
	return AmountSumNarah() * 0.13;
}

double Payment::AmountSumUtrym() {
	return AmountSumNarah() * 0.01 + PrybotkovyiPodatok();
}

double Payment::AmountZarplata() {
	return AmountSumNarah() - AmountSumUtrym();
}