#pragma once
#include <iostream>
#include<fstream>
using namespace std;



class Data
{
private:
	int day;
	int month;
	int year;
	friend ofstream& operator<< (ofstream& out, const Data& data);
	friend ifstream& operator>> (ifstream& in,  Data& data);
public:
	Data();
	Data(int day, int month, int year);
	Data operator++();
	Data operator--();
	bool operator == (const Data& other) const;
	bool operator != (const Data& other) const;
	bool operator < (const Data& other) const;
	bool operator > (const Data& other) const;
	void operator ()(int val);
	void operator ()(int days);
	void operator ()(int days,int month);
	void operator ()(int days,int month,int years);

};

ofstream& operator<<(ofstream& out, const Data& data)
{
	out << "day: " << data.day << endl;
	out << "month: " << data.month << endl;
	out << "year: " << data.year << endl;
	return out;
}

ifstream& operator>>(ifstream& in,  Data& data)
{
	in >> data.day;
	in >> data.month;
	in >> data.year;
	return in;
}
