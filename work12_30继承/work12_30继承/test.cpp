#include<iostream>
#include<string>
using std::cout;
using std::endl;
using std::string;
//class Person {
//public:
//	Person(string t = "Wang wu",int age = 5)
//		:_name(t)
//		,_age(age)
//	{
//		cout << "Person()" << endl;
//	}
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//	~Person()
//	{
//		cout << "~Person" << endl;
//	}
//protected:
//	string _name;
//	int _age;
//};
//
//class Student:public Person {
//public:
//	Student(const string s = "haha",int age = 10)
//		:_stuid(age)
//		,Person(s)
//	{
//		cout << "Student()" << endl;
//	}
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "Person name:" << Person::_name << endl;
//		//cout << "Stuend name:" << Student::_name << endl;
//	}
//	~Student()
//	{
//		cout << "~Sdutent()" << endl;
//	}
//protected:
//	int _stuid;
//};
//
//class Teacher : public Person {
//	public:
//	Teacher()
//		:_jobid(110)
//	{}
//protected:
//	int _jobid;
//};
//
//void Test()
//{
//	Student t();
//}
//int main()
//{
//	/*Person p1;
//	Student St;
//	p1.Print();
//	St.Print();
//	Teacher T1;*/
//	//Test();
//	Student t;
//	system("pause");
//	return 0;
//}


//class Student;
//
//class Person {
//public:    friend void Display(const Person& p, const Student& s);
//protected:
//	string _name; // ����
//};
//
//class Student : public Person
//{
//protected:
//	int _stuNum; // ѧ�� };
//
//	void Display(const Person& p, const Student& s)
//	{
//		//cout << p._name << endl;
//		cout << s._stuNum << endl;
//	}
//};
//
//int main()
//{
//	Person p;
//	Student s;
//	Display(p, s);
//	return 0;
//}

class Person {
public:
	string _name; // ����
};
class Student : public Person {
protected :    
	int _num ; //ѧ��
}; 
class Teacher : public Person { 
protected :    int _id ; // ְ����� 
}; class Assistant : public Student, public Teacher { 
protected :    
	string _majorCourse ; // ���޿γ�
}; 
void Test()
{      
	Assistant a;
	//a._name = "peter";// �������ж������޷���ȷ֪�����ʵ�����һ�� 
	a.Student::_name = "peter"; // ��Ҫ��ʾָ�������ĸ�����ĳ�Ա���Խ�����������⣬�����������������޷���� 

}
int main()
{
	Test();
	return 0;
}