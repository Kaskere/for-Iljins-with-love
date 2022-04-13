#include <string>
#include <iostream>
#include <iomanip>

using namespace std;
// for writing function - body is :
// return_type function_name( parameter list ) {
  // body of the function
// }

// auxiliary function for checking leap year. //The return type is bool, which means that every return statement
//has to provide a bool expression. The first line outputs the value true because 2 is a single-digit number.
//does not display the words true and false, but rather the integers 1 and 0.
bool leapyear(int year) {
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        return true;
    return false;
}
// get weekday from entered date - Sakamoto algorythm
int dayofweek(int day, int month, int year){
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    year -= month < 3;
    return ( year + year/4 - year/100 + year/400 + t[month-1] + day) % 7;

}
// Do the black job
int main()
{
    char fill = '/';
    string entered_date;
    int entered_month;
    int entered_year;
    int entered_day;

    cout << "Enter a date (dd/mm/yyyy): " << endl;
    cin >> entered_date;
    //parse integers out of strings with stoi. 1st - order, 2nd - length. this one I found really convenient
    entered_month = stoi(entered_date.substr(3,2));
    entered_day = stoi(entered_date.substr(0,2));
    entered_year = stoi(entered_date.substr(6));
        // check entered values
    //cout << entered_year << entered_month << entered_day << endl;

// validates entered date
// make dictionary
    const int lookup_table[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
    if (!(entered_month >= 1 && entered_month <= 12)) {
        cout<<"wrong month";
        return 1;
    }
    if (!(entered_day >= 1 && entered_day <= lookup_table[entered_month-1])) {
        cout<<"wrong day";
        return 1;
    }
    if (!(entered_year >= 0001)) {  // 0001 format cannot be used in python
        cout<<"wrong year";
        return 1;
    }

    // Call dayofweek function ; While creating a C++ function, you give a definition of what the function has to do.
    // To use a function, you will have to call or invoke that function.

int day_num = dayofweek(entered_day, entered_month, entered_year);
const string day_names[] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
cout<<day_names[day_num]<<endl;



    // Call leapyear function
    if (leapyear(entered_year))
        cout<<entered_year<<" is a leap year";
    else
        cout<<entered_year<<" is not a leap year";
    return 0;
}
