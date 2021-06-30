#include<iostream>
using namespace std;
#include"Human.h"
#include"Student.h"
#include"Theacher.h"
#include"Graduate.h"

#define delimiter "\n----------------------------------------------------------------------\n"

//#define INHERITANCE_BASICS

void main()
{
	setlocale(LC_ALL, "Rus");
#ifdef INHERITANCE_BASICS
	/*Human human("Тупенко", "Василий", 18);
human.print();	*/
	Student stud("Тупенко ", "Василий", 18, "РПО", "BV_123", 43.4);
	stud.print();
	Theacher Albert("Einstein", "Albert", 150, "Astrophisics", 120);
	Albert.print();
#endif // INHERITANCE_BASICS

	//                POINTERS TO BASE CLASS
	Human* group[] =
	{
		new Student("Васильев", "Александр", 23, "РПО", "ПВ_011", 90),
		new Student("Васильева", "Маргарита", 25, "РПО", "ПВ_011", 90),
		new Theacher("Ковтун", "Олег", 36, "Разработка приложений на С++", 6),
		new Student("Ивлев", "Александр", 25, "РПО", "ПВ_011", 95),
		new Graduate("Рахманин", "Николай", 28, "РПО", "ПВ_011", 98, "Разработка кросплатформенной обучающей игры"),
		new Theacher("Романов", "Андрей", 30, "HardWare PC", 6),
		new Student("Нусс", "Дмитрий", 22, "РПО", "ПВ_011", 100),
		new Student("Борн", "Евгений", 35, "РПО", "ПВ_011", 99),
		
	};

	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		cout << delimiter << endl;
		if (typeid(*group[i]) == typeid(Student))cout << *dynamic_cast<Student*>(group[i]) << endl;
		if (typeid(*group[i]) == typeid(Theacher))cout << *dynamic_cast<Theacher*>(group[i]) << endl;
		if (typeid(*group[i]) == typeid(Graduate))cout << *dynamic_cast<Graduate*>(group[i]) << endl;
	}
		cout << delimiter << endl;

	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		delete[] group[i];
	}
}