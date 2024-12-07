// Date Class.cpp : This file contains the 'main' function. Program execution begins and ends there.
// This program demonstrates the functionality of the Date class, including creating date objects,
// testing constructors, setting dates, verifying invalid dates, and testing date arithmetic and 
// increment/decrement operators.It also showcases the use of overloaded stream extraction and 
// insertion operators for input and output.
//
//
// Programmer: Aslihan Aria Celik

#include <iostream>
#include "Date.h" 
using namespace std;

int main() {
    // 1. Create a date object using the default constructor and display the date using the first format.
    Date date1;
    cout << "Default Constructor Date (MM/DD/YYYY): ";
    date1.print1();
    cout << endl;

    // 2. Create a date object using the constructor with parameters and display the date using the second format.
    Date date2(12, 25, 2021);
    cout << "Parameterized Constructor Date (Month DD, YYYY): ";
    date2.print2();
    cout << endl;

    // 3. Use one of your date objects to test the setDate() function and display the result using the third format.
    date1.setDate(4, 15, 2022);
    cout << "After setDate(4, 15, 2022): ";
    date1.print3();
    cout << endl;

    // 4. Use setDate() to set the date to 13/45/2018 and verify that this date is not accepted.
    date1.setDate(13, 45, 2018); // Invalid month and day
    cout << "After setDate(13, 45, 2018): ";
    date1.print1(); // Should display the default date (1/1/1930)
    cout << endl;

    // 5. Use setDate() to set the date to 4/31/2000 and verify that this date is not accepted.
    date1.setDate(4, 31, 2000); // Invalid day for April
    cout << "After setDate(4, 31, 2000): ";
    date1.print1(); // Should display the default date (1/1/1930)
    cout << endl;

    // 6. Use setDate() to set the date to 2/29/2009 and verify that this date is not accepted.
    date1.setDate(2, 29, 2009); // 2009 is not a leap year
    cout << "After setDate(2, 29, 2009): ";
    date1.print1(); // Should display the default date (1/1/1930)
    cout << endl;

    // 7. Subtract two valid dates and verify the result.
    date1.setDate(4, 10, 2014); // Set first date
    date2.setDate(4, 18, 2014); // Set second date
    cout << "Difference between 4/10/2014 and 4/18/2014: " << (date2 - date1) << " days" << endl;

    // 8. Subtract two other valid dates and verify the result.
    date1.setDate(11, 10, 2003);
    date2.setDate(2, 2, 2006);
    cout << "Difference between 2/2/2006 and 11/10/2003: " << (date2 - date1) << " days" << endl << endl;

    // 9-12. Test pre- and post-increment/decrement operators.
    date1.setDate(2, 29, 2008); // Leap year
    // Pre-decrement
    cout << "Pre-decrement from 2/29/2008: ";
    (--date1).print1(); // Should display 1/31/2008
    cout << endl;

    // Pre-increment
    cout << "Pre-increment back to 2/29/2008: ";
    (++date1).print1(); // Should display 2/29/2008
    cout << endl;

    // Post-decrement
    cout << "Post-decrement from 2/29/2008: ";
    date1--.print1(); // Should display 1/31/2008
    cout << endl;

    // Post-increment
    cout << "Post-increment back to 2/29/2008: ";
    date1++.print1(); // Should display 2/29/2008
    cout << endl;

    // Pre-increment
    cout << "Pre-increment to 3/1/2008: ";
    (++date1).print1(); // Should display 3/1/2008
    cout << endl;

    // Pre-decrement
    cout << "Pre-decrement from 3/1/2008: ";
    (--date1).print1(); // Should display 2/29/2008
    cout << endl;

    //Question 12:
    date1.setDate(12, 31, 2024);
    // Post-increment to next year
    cout << "Print post-incrementing from 12/31/2024: ";
    date1++.print1(); // Should display 12/31/2025
    cout << "Date is set to: ";
    date1.print1(); // Should display 1/1/2025
    cout << endl;

    //Question 13
    // Post-decrement back to previous year
    cout << "Print post-decrementing back to 12/31/2024: ";
    date1--.print1(); // Should display 1/1/2024
    cout << "Date is set to: ";
    date1.print1(); // Should display 12/31/2024
    cout << endl;

    //Question 14
    // Pre-increment
    cout << "Print pre-incrementing from 12/31/2024: ";
    (++date1).print1(); // Should display 1/1/2025
    cout << "Date is set to: ";
    date1.print1(); // Should display 1/1/2025
    cout << endl;

    // Pre-decrement
    cout << "Print pre-decrementing from 1/1/2025: ";
    (--date1).print1(); // Should display 12/31/2024
    cout << "Date is set to: ";
    date1.print1(); // Should display 12/31/2025
    cout << endl;

    //Question 15:
    // Use cin and the >> operator to read and display a date.
    Date inDate;
    cin >> inDate;

    //Question 16:

    cout << "The date you entered is set to: " << inDate << endl;

    //testing the overloaded stream insertion operator
    cout << endl;
    Date today(4, 18, 2018); // December 7, 2024 
    cout << "Today's date is: " << today << endl;

    return 0;
}
