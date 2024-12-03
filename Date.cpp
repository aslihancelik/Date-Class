#include "Date.h"
#include <iostream>
using namespace std;



//constructor

Date::Date(int m, int d, int y) {
	setDate(m, d, y);
}


// A function to set the date which takes month, day, and year as parameters.
void Date::setDate(int m, int d, int y) {

	//Start with setting the year
	if (y >= 1000) {
		year = y;
	}
	else {
		cout << "Year invalid,setting the date to 1/1/1930 " << endl;
		//Default values
		month = 1;
		day = 1;
		year = 1900;
		return; // Exit the function

	}
	


	//Setting the month
	// Check if the month is valid (between 1 and 12)
	if (m >= 1 && m <= 12) {
		// Set the month if valid
		month = m ;
	}
	else {
		// If month is invalid, print an error message and set default values
		cout << "Date invalid, setting to 1/1/1930 " << endl;
		//Default values
		month = 1;
		day = 1;
		year = 1900;
		return; // Exit the function
	}



	//Validate and set the day
	// Validate the day (must be within valid range for the specified month and year)
	if (d >= 1 && d <= daysInMonth(m)) {
		// Set the day if valid
		day = d;
	}
	else {
		// If day is invalid, print an error message and set default values
		cout << "Date invalid, setting to 1/1/1900 " << endl;
		//Default values
		month = 1;
		day = 1;
		year = 1900;
		return; // Exit the function
	}

}

//A function which takes a year and returns true if the year is a leap year.

bool Date::isLeapYear(int year) {
	// All years which are perfectly divisible by 4 are leap years except for 
	// century years (years ending with 00), which are leap years only if they
	// are perfectly divisible by 400.

		   //if true is a leap year , if false not a leap year
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

}


//A function which takes a month and returns the number of days in that month

int Date::daysInMonth(int month) {
	// Check if the month is February (2)
	if (month == 2) {
		// If it's February, return 29 if it's a leap year, otherwise return 28
		return isLeapYear(year) ? 29 : 28;
	}
	// For months January to July (1 to 7)
	else if (month <= 7)
	{
		// Return 30 days for even months (4, 6) and 31 days for odd months (1, 3, 5, 7)
		return month % 2 == 0 ? 30 : 31;
	}
	// For months August to December (8 to 12)
	else
	{
		// Return 31 days for even months (8, 10, 12) and 30 days for odd months (9, 11)
		return month % 2 == 0 ? 31 : 30;

	}


}

//print in three formats

// Print functions
void Date::print1() const { cout << month << "/" << day << "/" << year << endl; }

void Date::print2() const {
	static const string monthNames[] = { "", "January", "February", "March", "April", "May", "June",
										 "July", "August", "September", "October", "November", "December" };
	cout << monthNames[month] << " " << day << ", " << year << endl;
}
 
void Date::print3() const {
	static const string monthNames[] = { "", "January", "February", "March", "April", "May", "June",
										 "July", "August", "September", "October", "November", "December" };
	cout << day << " " << monthNames[month] << " " << year << endl;
}


void Date::adjustDate(){

	if (month < 1) {
		month = 12;
		year--;
	}
	if (month > 12) {
		month = 1;
		year++;
	}

	while (day > daysInMonth(month)) {
		day -= daysInMonth(month);
		month++;
		if (month > 12) {
			month = 1;
			year++;
		}
	}
	while (day < 1) {
		month--;
		if (month < 1) {  
			month = 12;
			year--;
		}
		day += daysInMonth(month);
	}
}


//Operator overloads

//Prefix increment
Date& Date::operator++() {
	day++;
	adjustDate();
	return *this;
}



////Postfix increment
Date Date::operator++(int){
	Date temp = *this;
	++(*this);
	return temp;
}


////Prefix decrement
Date& Date::operator--() {
	day--;
	adjustDate();
	return *this;
}

////Postfix decrement
Date Date::operator--(int) {
	Date temp = *this;
	--(*this);
	return temp;
}

////Subtraction
//int Date::operator-(const Date& other) const {
//	Date temp1 = *this, temp2 = other;
//	int count = 0;
//
//	// Ensure temp1 is the earlier date
//	if (temp1.year > temp2.year || (temp1.year == temp2.year && temp1.month > temp2.month) ||
//		(temp1.year == temp2.year && temp1.month == temp2.month && temp1.day > temp2.day)) {
//		swap(temp1, temp2);
//	}
//
//	while (temp1.year != temp2.year || temp1.month != temp2.month || temp1.day != temp2.day) {
//		++temp1;
//		count++;
//	}
//	return count;
//}


//
////Stream operators

//// Stream insertion operator
//ostream& operator<<(ostream& os, const Date& date) {
//	static const string monthNames[] = { "", "January", "February", "March", "April", "May", "June",
//										 "July", "August", "September", "October", "November", "December" };
//	os << monthNames[date.month] << " " << date.day << ", " << date.year;
//	return os;
//}


// Stream extraction operator

//istream& operator>>(istream& is, Date& date) {
//	char separator;
//	cout << "Enter date in MM/DD/YYYY format: ";
//	is >> date.month >> separator >> date.day >> separator >> date.year;
//	date.adjustDate();
//	return is;
//}
