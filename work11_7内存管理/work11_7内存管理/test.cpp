//#include<stdio.h>
//#include<stdlib.h>
//using namespace std;

//class Test
//{
//public:
//	Test(int Date = 0, int x = 1)
//		:_Date(Date)
//		, _x(x)
//	{}
//	~Test() {}
//private:
//	int _Date;
//	int _x;
//};
//int main()
//{
//	//动态申请一个int类型的指针
//	int *p1 = new int;
//	int *q1 = (int*)malloc(sizeof(int));
//
//	//动态申请一个int类型的空间并初始化成10
//	int *p2 = new int(10);
//	int *q2 = (int*)malloc(sizeof(int));
//	*q2 = 10;
//
//	//动态申请10个int类型的空间
//	int *p3 = new int[10];
//	int *q3 = (int *)malloc(sizeof(int) * 10);
//
//	//动态申请一个Test类型的指针
//	Test *p4 = new Test;//调用构造函数进行初始化
//	Test *q4 = (Test*)malloc(sizeof(Test));//不会初始化
//
//	Test *p5 = new Test(100, 2);
//	Test *p6 = new Test[10]; // 此时创建了10个对象，必须提供缺省的构造函数
//						   //Test *p7 = new Test[10](100,1)//此时出错
//	delete p1;
//	delete p2;
//	delete []p3;
//	delete p4;
//	delete p5;
//	delete []p6;
//
//	free(q1);
//	free(q2);
//	free(q3);
//	free(q4);
//	return 0;
//}
//#include<iostream>
//#include<mutex>
//#include<thread>
//using namespace std;
//
//class Singleton
//{
//public:
//	static Singleton* GetInstance() {
//		//加锁，双重判断
//		//
//		//    if(m_pInstance==NULL){
//		//      m_mtx.lock();
//		if (NULL == m_pInstance) {
//			m_pInstance = new Singleton();
//		}
//		//      m_mtx.unlock();
//		//    }
//		return m_pInstance;
//	}
//	//class CGarbo {
//	//public:
//	//	~CGarbo() {
//	//		if (Singleton::m_pInstance)
//	//			delete Singleton::m_pInstance;
//	//	}
//	//};
//	////定义一个全局变量，程序结束时，系统会自动调用它的析构函数从而释放单例对象
//	//static CGarbo Garbo;
//private:
//	Singleton() 
//	{
//		cout << "Singleton" << endl;
//	};//构造函数私有化
//				   //防拷贝
//	Singleton(Singleton const&)=delete;
//	Singleton& operator=(Singleton const&)=delete;
//
//	static Singleton* m_pInstance;//单例对象指针
//	static mutex m_mtx;//互斥锁，函数是静态的，只能访问静态成员
//};
//Singleton* Singleton::m_pInstance = NULL;
////Singleton::CGarbo Garbo;
//mutex Singleton::m_mtx;
//
//void func()
//{
//	cout << Singleton::GetInstance() << endl;
//}
//int main()
//{
//	//cout << Singleton::GetInstance() << endl;
//	//cout << Singleton::GetInstance() << endl;
//	thread t1(func);
//	thread t2(func);
//	t1.join();
//	t2.join();
//	system("pause");
//
//	return 0;
//}
#include<iostream>
#include<mutex>
#include<thread>
using namespace std;

class Singleton
{
public:
	static Singleton* GetInstance() {
		//加锁，双重判断
		//
		//    if(m_pInstance==NULL){
		//      m_mtx.lock();
		if (NULL == m_pInstance) {
			m_pInstance = new Singleton();
		}
		//      m_mtx.unlock();
		//    }
		return m_pInstance;
	}
	//    class CGarbo{
	//      public:
	//      ~CGarbo(){
	//        if(Singleton::m_pInstance)
	//          delete Singleton::m_pInstance;
	//      }
	//    };
	//定义一个全局变量，程序结束时，系统会自动调用它的析构函数从而释放单例对象
	//    static CGarbo Garbo;
private:
	Singleton()
	{
		cout << "Single" << endl;
	};//构造函数私有化
	  //防拷贝
	Singleton(Singleton const&)=delete;
	Singleton& operator=(Singleton const&)=delete;

	static Singleton* m_pInstance;//单例对象指针
	static mutex m_mtx;//互斥锁，函数是静态的，只能访问静态成员
};
Singleton* Singleton::m_pInstance = NULL;
//Singleton::CGarbo Garbo;
mutex Singleton::m_mtx;

void func()
{
	cout << Singleton::GetInstance() << endl;
}
int main()
{
	  //cout << Singleton::GetInstance()<<endl;
	  //cout << Singleton::GetInstance()<<endl;
	thread t1(func);
	thread t2(func);
	t1.join();
	t2.join();
	system("pause");
	return 0;
}