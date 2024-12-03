#pragma once
class Date
{
private:
	int day;
	int month;
	int year;
public:

	//constructor

	Date(int = 1, int = 1, int = 1930);


	// A function to set the date which takes month, day, and year as parameters.
	void setDate(int m, int d, int y);
	
    //Getter functions that return the month, day, and year individually as integers.
	int getDay() { return day; }
	int getMonth() { return month; }
	int getYear() { return year; }
	
    //A function which takes a year and returns true if the year is a leap year.
	
	bool isLeapYear(int y);


    //A function which takes a month and returns the number of days in that month

	int daysInMonth(int m);

	//print in three formats

	void print1() const;
	void print2() const;
	void print3() const;

	void adjustDate();

	//Operator overloads

	//Prefix increment
	Date& operator++();

	//Postfix increment
	Date operator++(int);

	//Prefix decrement
	Date& operator--();

	//Postfix decrement
	Date operator--(int);

	////Subtraction
	//int operator-(const Date& other) const;

	////Stream operators

	//friend ostream& operator<<(ostream& os, const Date& date);
	//friend istream& operator>>(istream& is, Date& date);




};

