#include<iostream>
#include<list>
#include<string>

void test1()
{
	std::list<int> l1;
	//std::list<int> l2(21);
	std::list<int> l3(4, 10);
	int array[] = { 1, 2, 3, 4, 5, 6 };
	std::list<int> l4(array, array + sizeof(array)/sizeof(int) );
	std::list<int> l5(l3.begin(), l3.end());
	std::list<int> l6(l5);
}

void test2()
{
	std::list<int> l1(4, 10);
	/*l1.push_back(11);
	l1.push_front(9);
	l1.pop_back();
	l1.pop_front();*/
	std::list<int>::iterator it = l1.begin();
	/*it++;
	it++;*/
	l1.insert(++it, 3);
	//l1.insert(it, l1.begin(), l1.end());
	l1.erase(it);
	size_t sz = l1.size();
	std::cout << sz << std::endl;
	std::list<std::string> l2(1,"asd");
	//l2.swap(l1);
	for (std::list<std::string>::iterator it = l2.begin(); it != l2.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	for (auto& e : l1)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;
}

void test3()
{
	std::list<int> l1(4, 10);
	l1.front() = 9;
	l1.back() = 11;
	for (auto& e : l1)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;

	const std::list<int> l2(4, 10);
	const int& x = l2.front();
	std::cout << x << std::endl;
	//x = 11;
	std::cout << x << std::endl;
}
int main()
{
	//test1();
	test2();
	//test3();

	system("pause");
	return 0;
}