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
//	//��̬����һ��int���͵�ָ��
//	int *p1 = new int;
//	int *q1 = (int*)malloc(sizeof(int));
//
//	//��̬����һ��int���͵Ŀռ䲢��ʼ����10
//	int *p2 = new int(10);
//	int *q2 = (int*)malloc(sizeof(int));
//	*q2 = 10;
//
//	//��̬����10��int���͵Ŀռ�
//	int *p3 = new int[10];
//	int *q3 = (int *)malloc(sizeof(int) * 10);
//
//	//��̬����һ��Test���͵�ָ��
//	Test *p4 = new Test;//���ù��캯�����г�ʼ��
//	Test *q4 = (Test*)malloc(sizeof(Test));//�����ʼ��
//
//	Test *p5 = new Test(100, 2);
//	Test *p6 = new Test[10]; // ��ʱ������10�����󣬱����ṩȱʡ�Ĺ��캯��
//						   //Test *p7 = new Test[10](100,1)//��ʱ����
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
//		//������˫���ж�
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
//	////����һ��ȫ�ֱ������������ʱ��ϵͳ���Զ������������������Ӷ��ͷŵ�������
//	//static CGarbo Garbo;
//private:
//	Singleton() 
//	{
//		cout << "Singleton" << endl;
//	};//���캯��˽�л�
//				   //������
//	Singleton(Singleton const&)=delete;
//	Singleton& operator=(Singleton const&)=delete;
//
//	static Singleton* m_pInstance;//��������ָ��
//	static mutex m_mtx;//�������������Ǿ�̬�ģ�ֻ�ܷ��ʾ�̬��Ա
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
		//������˫���ж�
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
	//����һ��ȫ�ֱ������������ʱ��ϵͳ���Զ������������������Ӷ��ͷŵ�������
	//    static CGarbo Garbo;
private:
	Singleton()
	{
		cout << "Single" << endl;
	};//���캯��˽�л�
	  //������
	Singleton(Singleton const&)=delete;
	Singleton& operator=(Singleton const&)=delete;

	static Singleton* m_pInstance;//��������ָ��
	static mutex m_mtx;//�������������Ǿ�̬�ģ�ֻ�ܷ��ʾ�̬��Ա
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