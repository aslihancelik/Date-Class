// Date.h : This file contains the definition of the Date class. 
// The Date class provides functionality for:
// - Setting and validating dates with `setDate`.
// - Checking for leap years with `isLeapYear`.
// - Determining the number of days in a month with `daysInMonth`.
// - Printing dates in various formats with `print1`, `print2`, and `print3`.
// - Adjusting dates with `adjustDate`.
// - Overloading operators for date arithmetic, including pre- and post-increment (`++`), 
//   pre- and post-decrement (`--`), and subtraction (`-`).
// - Overloading stream insertion (`<<`) and extraction (`>>`) operators for input and output.
// This class ensures that dates are validated and adjusted correctly, provides different date 
// representations, and handles basic date arithmetic.
//
//
// Programmer: Aslihan Aria Celik

#ifndef DATE_H 
#define DATE_H

#include <iostream>
using namespace std;

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

	//name of the months
	static const string monthNames[13];

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

	//Subtraction
	int operator-(const Date& other) const;

	////Stream operators

	// Friend function to overload the << operator
	friend ostream& operator<<(ostream& os, const Date& date);

	//friend function to overload the >> operator
	friend istream& operator>>(istream& is, Date& date);

};

#endif // DATE_H