#include"List.hpp"

void test1()
{
	wg::List<int> l1;

	wg::List<int> l2(4, 1);
	Print(l2);//1 1 1 1

	int array[5] = { 1,2,3,4,5 };
	wg::List<int> l3(array, array + sizeof(array) / sizeof(array[0]));
	Print(l3);//1 2 3 4 5

	wg::List<int> l4(l3);
	Print(l4);//1 2 3 4 5

	l1 = l4;
	Print(l1);//1 2 3 4 5
}

void test2()
{
	wg::List<int> l1;
	l1.PushBack(1);
	l1.PushBack(2);
	l1.PushBack(3);
	l1.PushBack(4);
	Print(l1);//1 2 3 4

	l1.PushFront(0);
	Print(l1);//0 1 2 3 4

	l1.PopFront();
	l1.PopBack();
	Print(l1);//1 2 3

	wg::List<int>::Iterator pos = l1.Begin();
	pos++;
	l1.Insert(pos, 20);
	Print(l1);//1 20 2 3

	l1.Erase(pos);
	Print(l1);//1 20 3
	//此时pos已经失效
	cout << l1.Size() << endl;

}

void test3()
{
	wg::List<int> l(4, 1);
	Print(l);//1 1 1 1
	cout << l.Size() << endl;

	l.ReSize(3, 2);
	Print(l);//1 1 1;
	cout << l.Size() << endl;

	l.ReSize(5, 2);
	Print(l);//1 1 1 2 2
	cout << l.Size() << endl;
}
int main()
{
	//test1();
	//test2();
	test3();
	system("pause");
	return 0;
}