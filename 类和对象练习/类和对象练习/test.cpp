#include<iostream>
using namespace std;
//class Date
//{
//friend ostream& operator<<(ostream& _cout, const Date& d);
//friend istream& operator>>(istream& _cin, const Date& d);
//public:
//	Date(int year, int month, int day)
//		:_year(year)
//		,_month(month)
//		,_day(day)
//	{}
//	
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//ostream& operator<<(ostream& _cout,const Date& d)
//{
//	_cout << d._year << "-" << d._month << "-" << d._day;
//	return _cout;
//}
////istream& operator>>(istream& _cin, const Date& d)
////{
////	_cin >> d._year;
////	_cin >> d._month;
////	_cin >> d._day;
////	return _cin;
////}
//int main()
//{
//	Date d(2018,5,5);
//	//cin >> d;
//	cout << d << endl;
//	system("pause");
//	return 0;
//}


//外部类内部类
class A
{
private:
	static int k;
	int h;
public:
	class B
	{
	public:
		void foo(const A& a)
		{
			cout << k << endl;
			cout << a.h << endl;
		}
	};
	void Print()
	{
		cout << h << endl;
	}
};
int A::k = 1;
int main()
{
	A::B b;
	b.foo(A());
	
	system("pause");
	
	return 0;
}