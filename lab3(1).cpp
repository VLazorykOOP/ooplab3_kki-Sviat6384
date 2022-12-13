#include <iostream>
#include <math.h>
using namespace std;

class Time {
	int hour;
	int minute;
    int second;
public:
	Time() : hour(0), minute(0), second(0) {}
	Time(int h) : minute(0), second(0) { if (h >= 0 && h <= 23) hour = h; else h = 0; }
	Time(int h, int m, int s) {
		hour = h;
		minute = m;
		second = s;
	}
	int getHour()
	{
		return hour;
	}
	void setHour(int h)
	{
		if (h < 0 || h > 23) {
			cout << " Error set hour \n";
			return;
		}
		hour = h;
	}
	int getMinute()
	{
		return minute;
	}
	void setMinute(int m)
	{
		if (m < 0 || m > 23) {
			cout << " Error set minute \n";
			return;
		}
		minute = m;
	}
	int getSecond() const
	{
		return second;
	}
	void setSecond(int s)
	{
		if (s < 0 || s > 23)
		{
			cout << " Error set second \n";
			return;
		}
		second = s;
	}
	void printInfo1()
	{
		cout << hour << " годин " << minute << " хвилин " << second << " секунди " << endl;
	}
	void printInfo2()
	{
		cout << hour % 12;
		if (hour - 12 < 0) {
			cout << " a.m ";
		}
		else {
			cout << " p.m ";
		}
		cout <<  minute << " хвилин " << second << " секунди " << endl;
	}
};
int main()
{
	Time obj;
	obj.printInfo1();
	int in_h, in_m, in_s;
	cout << " Input hour, minute and second: "; cin >> in_h >> in_m >> in_s;
	Time obj1(in_h), obj2(in_h, in_m, in_s);
	cout << "obj1" << endl;
	obj1.printInfo1();
	cout << "obj2" << endl;
	obj2.printInfo1();
	cout << "Hour" << endl;
	obj.setHour(-2);
	obj.printInfo1();
	obj.setHour(2);
	obj.printInfo1();
	cout << "Minute" << endl;
	obj.setMinute(-3);
	obj.printInfo1();
	obj.setMinute(3);
	obj.printInfo1();
	cout << "Second" << endl;
	obj.setSecond(-10);
	obj.printInfo1();
	obj.setSecond(10);
	obj.printInfo1();
	cout << "PrintInfo2" << endl;
	obj.printInfo2();
	obj.setHour(23);
	obj.printInfo2();
	cout << " End testing \n";
	return 0;
}