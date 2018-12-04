#define _CRT_SECURE_NO_WARNINGS 4996
#include<iostream>
#include<string>
#include<string.h>
 
//����48---57
//��д65--+26  90
//Сд97--+26  122
using namespace std;
class Solution {
	bool isNumberOrChar(char ch)
	{
		return((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z') || (ch >= '0'&&ch <= '9'));
	}
	bool Is(string s)
	{
		if (s.empty())
			return true;
		for (auto c : s)
		{
			if (c >= 'A'&&c <= 'Z')
				c += 32;//��дתСд
		}
		int begin = 0;
		int end = s.size() - 1; 
	}
};
class Solution2
{
public:
	string addStrings(string num1, string num2)
	{
		int end1 = num1.size() - 1;
		int end2 = num2.size() - 1;
		string retstr;
		retstr.reserve(num1.size() > num2.size() ? num1.size() + 1 : num2.size() + 1);
		int next = 0;
		while (end1 >= 0 || end2 >= 0)
		{
			//00123
			//45678

			//
			int value1 = 0;
			if (end1 >= 0)
				value1 = num1[end1] - '0';
			int value2 = 0;
			if (end2 >= 0)
				value2 = num2[end2] - '0';
			int addvalue = value1 + value2 + next;
			if (addvalue > 9)
			{
				next = 1;
				addvalue -= 10;
			}
			else {
				next = 0;
			}
			//retstr.insert(retstr.begin(), addvalue + '0');
			retstr += (addvalue + '0');
			--end1;
			--end2;
		}
		if (next == 1)
			//0028
			//9973
			//retstr.insert(retstr.begin(), 1);
			retstr += 1;
		reverse(retstr.begin(), retstr.end());
		return retstr;
	}
};
void Testadd()
{
	Solution2 s1;
	cout << s1.addStrings("123", "456") << endl;
	system("pause");
}

class String
{
public:
	//String()
	//	:_str(new char[1])
	//{
	//	_str[1] = '\0';
	//}
	//String(char* str)
	//	:_str(new char[strlen(str)+1])
	//{
	//	strcpy(_str, str);//while(*drt++=*str++)
	//}
	String(const char *str = "")
		:_str(new char[strlen(str) + 1])
	{
		strcpy(_str, str);
	}

	//��������
	//String(const String& s)//�������죬���
	//	:_str(new char[strlen(s._str) + 1])
	//{
	//	strcpy(_str, s._str);
	//}
	//����������ִ�д��
	String(const String& s)
		:_str(nullptr)
	{
		String tmp(s._str);
		swap(_str, tmp._str);
	}
	//��ֵ
	//String operator=(const String& s)//��ֵ
	//	//:_str(new char[strlen(s._str)+1])
	//{
	//	if (this != &s)
	//	{
	//		delete[] _str;
	//		_str = new char[strlen(s._str) + 1];
	//		strcpy(_str, s._str);
	//	}
	//	return *this;
	//}
	//��ֵ���ִ�д����ȱ�ݣ��Լ����Լ���ֵ��ֻ�ǻ���һƬ�ռ䣬�����Ѿ����������
	String operator=(String s)
	{
		swap(_str, s._str);
		return *this;
	}
	
	~String()
	{
		delete[] _str;
	}
	void Print()
	{
		cout << _str << endl;
	}
private:
	char* _str;
};


void TestString()
{
	String S1;
	String S2("Hello");
	//cout << S1._str << endl;
	S1 = S2;
	S1.Print();
	S2.Print();
}
int main()
{
	//Testadd();
	TestString();
	system("pause");
	return 0;
}