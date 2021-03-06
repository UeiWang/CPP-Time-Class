#ifndef TIME_H_
#define TIME_H_

#include <iostream>
class Time
{
	int year_ = 0;
	int month_ = 0;
	int day_ = 0;
	int hour_ = 0;
	int min_ = 0;
	int sec_ = 0;
	const int Months_of_a_year = 12;
	
	void time_formatting();		//check if the time is in wrong format e.g. second_>=60
	void date_formatting();		//check if the date is in wrong format e.g. month_>=13;

public:
	Time(int year, int month, int day, int hour, int min, int sec);
	Time(char type, int x, int y, int z);		//type specifies whether the input is a time or a date
	Time(char format[3], int x, int y);		//type specifies wheteher the input format is Year-Month, Month-Day, Hour-Minute, or Minute-Second
	Time(tm * t);		//convert from a pointer-to-tm-structure
	bool is_leap_year(int year) const;
	int days_of_a_month(int month) const;
	void add_hour(int num);
	void add_min(int num);
	void add_sec(int num);
	void add_day(int num);
	void add_month(int num);
	void add_year(int num);
	Time operator-(const Time & t) const;
	Time operator+(const Time & t) const;
	void show_date() const
	{
		std::cout << year_ << "." << month_ << "." << day_;
	}
	/*void show_date_separate() const
	{
		std::cout << year_ << "y " << month_ << "m " << day_ << "d";
	}*/
	void show_time() const
	{
		std::cout << hour_ << ":" << min_ << ":" << sec_;
	}
	void show_time_separate() const
	{
		std::cout << day_ << "d " << hour_ << "h " << min_ << "min " << sec_ << "s";
	}
};

Time current_time();

#endif