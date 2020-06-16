#include "data.h"

Data::Data()
{
	day = 0;
	month = 0;
	year = 0;
}

Data::Data(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

Data Data::operator++()
{
	if (this->day + 1 > 31) {
		cout << "Error" << endl;
	}
	else
	{
		this->day = this->day + 1;
	}
	return *this;
}

Data Data::operator--()
{
	if (this->day - 1 < 0) {
		cout << "Error" << endl;
	}
	else
	{
		this->day = this->day - 1;
	}
	return *this;
}

bool Data::operator==(const Data& other) const
{
	return (this->day && this->month == other.day && other.month);
}

bool Data::operator!=(const Data& other) const
{
	return (this->day && this->month != other.day && other.month);
}

bool Data::operator<(const Data& other) const
{
	return (this->day && this->month < other.day && other.month);
}

bool Data::operator>(const Data& other) const
{
	return (this->day && this->month > other.day && other.month);
}

void Data::operator()(int val)
{
	if (val > 0 && val <= 31) {

		day += val;
		if (day >= 31) {
			month + 1;
		}
	}
}
void Data::operator ()(int days) {
	if (days > 0 && days <= 31) {
		day += days;
		if (day > 31) month++;
	}
}

void Data::operator()(int days, int month)
{
	if ((days > 0 && days <= 31)&&(month > 0 && month <=12)){
		this->month += month;
		
		
		if (day > 31 || this->month > 12) month++;
	}
}

void Data::operator()(int days, int month, int years)
{
	if ((days > 0 && days <= 31) && (month > 0 && month <= 12)&& (years > 0)) {
		this->month + month;
		this->year += years;
		if (day > 31 || this->month > 12) month++;
	}
}

