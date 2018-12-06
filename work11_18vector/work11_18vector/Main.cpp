#include<iostream>
#include<vector>
#include<string>
using namespace std;

//void test1()
//{
//	//遍历
//	//迭代器
//	//for+[]
//	//for-each +11
//	vector<string> s1;
//	s1.push_back("hello");
//	for (const auto& s : s1)
//	{
//		cout << s << " ";
//	}
//	cout << endl;
//}
//void test2()
//{
//	//vector增容，常规2倍，pj版本是1.5倍，Linux下是2倍
//}
//
//int main()
//{
//	//test1();
//	test2();
//	system("pause");
//	return 0;
//}



void swapr(const int&a, const int&b)
{
	cout << "函数引用过程中" << a << " " << b << endl;

}
int main()
{
	double a = 3.1, b = 5.2;
	cout << "原始值" << a << " " << b << endl;
	swapr(a, b);
	cout << "调用后" << a << " " << b << endl;

	system("pause");
	return 0;
}
