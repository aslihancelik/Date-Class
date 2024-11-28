// Date Class.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Date.h" // Include the header file for the Date class

int main() {
    // 1. Create a date object using the default constructor and display the date using the first format.
    Date date1;
    std::cout << "Default Constructor: ";
    date1.print1();
    std::cout << std::endl;

    // 2. Create a date object using the parameterized constructor and display the date using the second format.
    Date date2(12, 25, 2021);
    std::cout << "Parameterized Constructor: ";
    date2.print2();
    std::cout << std::endl;

    // 3. Test setDate() function and display the result using the third format.
    date1.setDate(10, 31, 2023);
    std::cout << "After using setDate(10, 31, 2023): ";
    date1.print3();
    std::cout << std::endl;

    // 4. Set date to 13/45/2018 and verify it is not accepted.
    if (!date1.setDate(13, 45, 2018)) {
        std::cout << "Invalid Date: 13/45/2018 was not accepted." << std::endl;
    }

    // 5. Set date to 4/31/2000 and verify it is not accepted.
    if (!date1.setDate(4, 31, 2000)) {
        std::cout << "Invalid Date: 4/31/2000 was not accepted." << std::endl;
    }

    // 6. Set date to 2/29/2009 and verify it is not accepted.
    if (!date1.setDate(2, 29, 2009)) {
        std::cout << "Invalid Date: 2/29/2009 was not accepted." << std::endl;
    }

    // 7. Test subtraction operator: 4/18/2014 - 4/10/2014 = 8 days.
    date1.setDate(4, 10, 2014);
    date2.setDate(4, 18, 2014);
    std::cout << "Days between 4/18/2014 and 4/10/2014: "
        << date2 - date1 << " days." << std::endl;

    // 8. Test subtraction operator: 2/2/2006 - 11/10/2003 = 815 days.
    date1.setDate(11, 10, 2003);
    date2.setDate(2, 2, 2006);
    std::cout << "Days between 2/2/2006 and 11/10/2003: "
        << date2 - date1 << " days." << std::endl;

    // 9. Pre-decrement operator: 2/29/2008 -> 1/31/2008
    date1.setDate(2, 29, 2008);
    --date1;
    std::cout << "Pre-decrement: ";
    date1.print1();
    std::cout << std::endl;

    // 10. Pre-increment operator: 1/31/2008 -> 2/29/2008
    ++date1;
    std::cout << "Pre-increment: ";
    date1.print1();
    std::cout << std::endl;

    // 11. Post-decrement and post-increment operators
    date1--;
    std::cout << "Post-decrement: ";
    date1.print1();
    std::cout << std::endl;

    date1++;
    std::cout << "Post-increment: ";
    date1.print1();
    std::cout << std::endl;

    // 12. Post-increment: 12/31/2024 -> 1/1/2025
    date1.setDate(12, 31, 2024);
    date1++;
    std::cout << "Post-increment (12/31/2024 -> 1/1/2025): ";
    date1.print1();
    std::cout << std::endl;

    // 13. Post-decrement: 1/1/2025 -> 12/31/2024
    date1--;
    std::cout << "Post-decrement (1/1/2025 -> 12/31/2024): ";
    date1.print1();
    std::cout << std::endl;

    // 14. Pre-increment and pre-decrement operators
    ++date1;
    std::cout << "Pre-increment (12/31/2024 -> 1/1/2025): ";
    date1.print1();
    std::cout << std::endl;

    --date1;
    std::cout << "Pre-decrement (1/1/2025 -> 12/31/2024): ";
    date1.print1();
    std::cout << std::endl;

    // 15. Use cin and >> operator to read a date.
    std::cout << "Enter a date (mm dd yyyy): ";
    std::cin >> date1;

    // 16. Use cout and << operator to display the date read from the keyboard.
    std::cout << "Date entered: " << date1 << std::endl;

    return 0;
}
