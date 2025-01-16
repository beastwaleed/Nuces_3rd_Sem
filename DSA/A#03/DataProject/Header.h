#pragma once
#include<iostream>
#include<string>
using namespace std;
class date_time
{
	int day, month, year, hour, min;
	string am_pm;
public:
	void set_date();
	void display();
};
