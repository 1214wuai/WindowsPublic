#include<iostream>
#include<vector>
#include<string>
using namespace std;

//void test1()
//{
//	//����
//	//������
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
//	//vector���ݣ�����2����pj�汾��1.5����Linux����2��
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
	cout << "�������ù�����" << a << " " << b << endl;

}
int main()
{
	double a = 3.1, b = 5.2;
	cout << "ԭʼֵ" << a << " " << b << endl;
	swapr(a, b);
	cout << "���ú�" << a << " " << b << endl;

	system("pause");
	return 0;
}
