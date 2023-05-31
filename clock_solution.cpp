#include <iostream>
#include "clockType.h"
using namespace std;
//http://www.cplusplus.com/forum/general/7050/


// Write a C++ program which contains a class named Time having three data members.
// • Hours
// • Minutes
// • Seconds
//
// The class must have
// • A default and parameterized constructor
// • show() method to display the time in proper format like HH:MM:SS on the screen
// • get() method to get time from user
// • Overloaded Plus (+) and Minus (-) operators
// • A destructor
//
// You will overload + and - operator for this class.
//
// In main program make 3 objects of the Time class time1, time2 and time3 and call the get() functions for time1 and time2 then perform time3 = tim1+time2 and then you will display time3 using its show() function.
//
// Note1: While Adding the time keep in mind do not just add the hours into hours and minutes into minutes and seconds in seconds , e.g
// 10:25:10
// +01:45:25
// ---------------------
// 11: 70: 35
//
// Will not be correct, instead your code should add times like, Note that as number of minutes have increased 60, hour have been increased.
//
// 10:25:10
// + 01:45:25
// -------------------
// 12: 10: 35

/* Sample run with your data
Enter the time
Hour: 10
Minutes: 23
Seconds: 10
Enter the time
Hour: 1
Minutes: 45
Seconds: 25
Time 1 : 10:23:10
Time 2 : 01:45:25

Added :
10:23:10
+01:45:25
----------
12:08:35

Subtracted:
10:23:10
-01:45:25
----------
08:37:45
Press any key to continue . . .
*/


void convert(int, int &, int &, int &);
class Time
{
	public:
		int hour, minute, second;
	Time()
	{
		hour = 0;
		minute = 0;
		second = 0;
	}~Time()
	{
		hour = 0;
		minute = 0;
		second = 0;
	}

	Time(int h, int m, int s)
	{
		hour = h;
		minute = m;
		second = s;
	}

	void get()
	{
		cout << "Enter the time\n";
		cout << "Hour: ";
		cin >> hour;
		cout << "Minutes: ";
		cin >> minute;
		cout << "Seconds: ";
		cin >> second;
	}

	void show()
	{
		cout << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << minute << ":" << setw(2) << setfill('0') << second << endl;
	}

	Time operator+(Time t)
	{
		int h, m, s;
		int totalsec;
		totalsec = (hour *3600 + minute *60 + second) + (t.hour *3600 + t.minute *60 + t.second);
		convert(totalsec, h, m, s);
		return Time(h, m, s);
	}

	Time operator-(Time t)
	{
		int h, m, s, totalsec;
		totalsec = (hour *3600 + minute *60 + second) - (t.hour *3600 + t.minute *60 + t.second);
		if (totalsec < 0)
			totalsec = -totalsec;
		convert(totalsec, h, m, s);
		return Time(h, m, s);
	}

	void convert(int totalsec, int &h, int &m, int &s)
	{
		s = totalsec % 60;
		totalsec = totalsec / 60;
		m = totalsec % 60;
		h = (totalsec / 60) % 12;
		if (h == 0)
			h = 12;
		return;
	}
};

int main()
{
	Time time1, time2, added, subtracted;
	cout.setf(ios::fixed, ios::floatfield);
	cout.precision(2);
	time1.get();
	time2.get();
	added = time1 + time2;
	subtracted = time1 - time2;
	cout << "Time 1 : ";
	time1.show();
	cout << "Time 2 : ";
	time2.show();
	cout << "\nAdded :\n ";
	time1.show();
	cout << "+";
	time2.show();
	cout << "----------\n ";
	added.show();
	cout << "\nSubtracted:\n ";
	time1.show();
	cout << "-";
	time2.show();
	cout << "----------\n ";
	subtracted.show();
	system("pause");
}
