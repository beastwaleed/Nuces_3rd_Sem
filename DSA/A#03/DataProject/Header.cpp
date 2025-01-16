#include<iostream>
#include<string>
#include<ctime>
#include"Header.h"
using namespace std;

void date_time::set_date()
{
	time_t current_time = time(0);
	tm localtime;
	localtime_s(&localtime, &current_time);
	hour = localtime.tm_hour;
	min = localtime.tm_min;
	day = localtime.tm_mday;
	month = localtime.tm_mon + 1;
	year = localtime.tm_year + 1900;
	if (hour >= 12)
	{
		am_pm = "pm";
		hour = hour % 12;
	}
	else
		am_pm = "am";
}
void date_time::display()
{
	if (day < 10)
	{
		cout << "0";
	}
	cout << day;

	cout << "/";
	if (month < 10)
	{
		cout << "0";
	}
	cout << month << "/" << year << " ";
	if (hour < 10)
	{
		cout << "0";
	}
	cout << hour << ":";
	if (min < 10)
	{
		cout << "0";
	}
	cout << min << " " << am_pm << endl;
}