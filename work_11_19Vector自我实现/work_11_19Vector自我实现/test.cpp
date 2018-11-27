#include"Vector.h"

void test1()
{
	wg::Vector<int> s1;//无参构造
	wg::Vector<int> s2(4,100);//构造并初始化n个value
	//wg::Vector<int>::Iterator it = s2.Begin();
	//while(it<s2.End())
	//{
	//	cout << *it << endl;
	//	++it;
	//}
	wg::Vector<int> s3(s2);//拷贝构造
	//for (size_t i = 0; i < s3.Size(); i++)
	//{
	//	cout << s3[i] << endl;
	//}
	wg::Vector<int> s4(s3.Begin(), s3.End());//使用迭代器进行初始化构造
	

	for (size_t i = 0; i < s4.Size(); i++)
	{
		cout << s4[i] << endl;
	}

}

void test2()
{
	wg::Vector<int> s1(2,3);
	s1.Insert(s1.Begin()+1, 1);
	s1.Insert(s1.Begin() + 1, 1);
	

	s1.PushBack(5);
	s1.Resize(2);
	s1.Resize(6);
	s1.Resize(20);
	for (size_t i = 0; i < s1.Size(); i++)
	{
		cout << s1[i] << endl;
	}
	cout << s1.Size() << endl;

}
void test3()
{
	wg::Vector<int> s1(1, 0);
	//s1.PopBack();
	s1.PushBack(1);
	s1.PushBack(2);
	s1.PushBack(3);
	s1.PushBack(4);
	s1.PushBack(5);

	s1.Erasse(s1.Begin());
	s1.Erasse(s1.End());
	s1.Erasse(s1.Begin()+1);
	s1.Erasse(s1.Begin()+6);//报错


	for (size_t i = 0; i < s1.Size(); i++)
	{
		cout << s1[i] << endl;
	}
	
}
int main()
{
	//test1();
	//test2();
	test3();
	system("pause");
	return 0;
}