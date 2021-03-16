#pragma once
#include "Date.h"

class Payment
{
private:
	string name, surname;
	double stavka;
	Date data;
	short nadbavkaProc;
	double pributPodatok;
	short amountRob, amountVidprac;
	double SumNarah, SumUtrym;
public:
	string GetName() const { return name; };
	void SetName(string v) { this->name = v; };

	string GetSurname() const { return surname; };
	void SetSurname(string v) { this->surname = v; };

	double GetStavka() const { return stavka; };
	void SetStavka(double);

	Date GetDate() const { return data; };
	void SetDate(Date v) { this->data = v; };

	short GetNadbavkaProc() const { return nadbavkaProc; };
	void SetNadbavkaProc(short);

	unsigned int GetPributPodatok() const { return pributPodatok; };
	void SetPributPodatok(unsigned int v) { this->pributPodatok = v; };

	short GetAmountRob() const { return amountRob; };
	void SetAmountRob(short v);

	short GetAmountVidprac() const { return amountVidprac; };
	void SetAmountVidprac(short);

	double GetSumNarah() const { return SumNarah; };
	void SetSumNarah(double v);

	double GetSumUtrym() const { return SumUtrym; };
	void SetSumUtrym(double v);

	void Read();
	void Display();
	void Init(string, string, double, Date, short, short, short);
	string toString() const;

	short CountExpirience(Date);
	double PrybotkovyiPodatok();
	double AmountSumNarah();
	double AmountSumUtrym();
	double AmountZarplata();
};

