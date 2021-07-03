#include<iostream>
#include<string>
#include<regex>
using namespace std;

#define delimiter "\n----------------------------------------------------------------------\n"

class Human
{
	string last_name;
	string first_name;
	string email;
	string phoneNuber;
	unsigned int age;

public:
	const string& get_last_name()const
	{
		return last_name;
	}
	const string& get_first_name()const
	{
		return first_name;
	}
	const string& get_email()const
	{
		return email;
	}
	const string& get_phoneNumber()const
	{
		return phoneNuber;
	}

	unsigned int get_age()const
	{
		return age;
	}
	void set_last_name(const string& last_name)
	{
		std::regex en_rgx("[A-Z][a-z]{1,15}");
		std::regex ru_rgx("[А-Я][а-я]{1,15}");
		std::regex ru_double_rgx("([А-Я][а-я]{1,15}[ -]{0,1}){1,2}");
		if 
			(std::regex_match(last_name, en_rgx) || 
			 std::regex_match(last_name, ru_rgx) ||
			 std::regex_match(last_name, ru_double_rgx))this->last_name = last_name;
		else this->last_name = "Bad name";
	}
	void set_first_name(const string& first_name)
	{
		std::regex en_rgx("[A-Z][a-z]{1,15}");
		std::regex ru_rgx("[А-Я][а-я]{1,15}");
		if (std::regex_match(first_name, en_rgx) || std::regex_match(first_name, ru_rgx))this->first_name = first_name;
		else this->first_name = "Bad name";
	}
	void set_email(const string& email)
	{
		std::regex rgx("([a-z]+)([_.a-z0-9]*)([a-z0-9]+)(@)([a-z]+)([.a-z]+)([a-z]+)");
		if (std::regex_match(email, rgx))this->email = email;
		else this->email = "Bad email";
	}
	void set_phoneNumber(const string& phoneNumber)
	{
		std::regex rgx("([\+][\d][\(](\d){3}[\)](\d){3}([-\d\d])([-\d\d]))");
		if (std::regex_match(phoneNumber, rgx))this->phoneNuber = phoneNumber;
		else this->phoneNuber = "Bad phoneNumber";
	}
	void set_age(unsigned int age)
	{
		if (age > 18 && age <= 150)this->age = age;
		else this->age = 0;
	}

	//Constructors
	Human(const string& last_name, const string& first_name, const string& email, const string& phoneNumber, unsigned int age)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_email(email);
		set_phoneNumber(phoneNumber);
		set_age(age);
		cout << "HConstructor:\t" << endl;
	}
	virtual ~Human()
	{
		cout << "HDestructor:\t" << endl;
	}

	//                Mehods:
	virtual void print()
	{
		cout << last_name << " " << first_name << " " << email << " телефон: " << phoneNuber<< " " << age << " лет." << endl;
	}

};

ostream& operator<<(ostream& os, const Human& obj)
{
	os << obj.get_last_name() << " " << obj.get_first_name() << " " << obj.get_email() << " телефон: " << obj.get_phoneNumber() << " " << obj.get_age() << " лет.";
	return os;
}

class Student : public Human
{
	string specialty;
	string group;
	double rating;
public:
	const string& get_specialty()const
	{
		return specialty;
	}
	const string& get_group()const
	{
		return group;
	}
	double get_rating()const
	{
		return rating;
	}
	void set_specialty(const string& specialty)
	{
		std::regex en_rgx("([A-Za-z][A-Za-z]{1,15}[ -]{0,4}){1,5}");
		std::regex ru_rgx("([А-Яа-я][А-Яа-я]{1,15}[ -]{0,4}){1,5}");
		if (std::regex_match(specialty, en_rgx) || std::regex_match(specialty, ru_rgx))this->specialty = specialty;
		else this->specialty = "Bad speciality";
	}
	void set_group(const string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		if (rating >= 0 && rating <= 100)this->rating = rating;
		else this->rating = 0;
	}

	//				Constructors:
	Student
	(
		const string& last_name, const string& first_name, const string& email, const string& phoneNumber, unsigned int age,
		const string& specialty, const string& group, double rating
	) :Human(last_name, first_name, email, phoneNumber, age)
	{
		set_specialty(specialty);
		set_group(group);
		set_rating(rating);
		cout << "SConstructor: " << endl;
	}
	~Student()
	{
		cout << "SDestructor: " << endl;
	}

	//				Methods:

	void print()
	{
		Human::print();
		cout << "Специальность: " << specialty << ", группа: " << group << ", успеваемость: " << rating << endl;
	}
};

ostream& operator<<(ostream& os, const Student& obj)
{
	os << (Human)obj << " ";
	os << "Специальность: " << obj.get_specialty() << ", группа: " << obj.get_group() << ", успеваемость: " << obj.get_rating();
	return os;
}

class Theacher : public Human
{
	string specialty;
	unsigned int expirience;
public:
	const string& get_specialty()const
	{
		return specialty;
	}
	unsigned int get_expirience()const
	{
		return expirience;
	}
	void set_speciality(const string& spetialty)
	{
		std::regex en_rgx("([A-Za-z][A-Za-z]{1,15}[ -]{0,4}){1,5}");
		std::regex ru_rgx("([А-Яа-я][А-Яа-я]{1,15}[ -]{0,4}){1,5}");
		if (std::regex_match(specialty, en_rgx) || std::regex_match(specialty, ru_rgx))this->specialty = specialty;
		else this->specialty = "Bad speciality";
	}
	void set_expirience(unsigned int expirience)
	{
		if (expirience >= 0 && expirience <= 130)this->expirience = expirience;
		else this->expirience = 0;
	}

	//				Constructors:
	Theacher
	(
		const string& last_name, const string& first_name, const string& email, const string& phoneNumber, unsigned int age,
		const string& specialty, unsigned int expirience
	) :Human(last_name, first_name, email, phoneNumber, age)
	{
		this->specialty = specialty;
		this->expirience = expirience;
		cout << "TConstructor: " << endl;
	}
	~Theacher()
	{
		cout << "TDestructor: " << endl;
	}

	//				Methods:

	void print()
	{
	Human:: print();
		cout << "Специальность: " << specialty << ", опыт преаодавания: " << expirience << " лет" << endl;
	}
};

ostream& operator<<(ostream& os, const Theacher& obj)
{
	os << (Human)obj << " ";
	os << "Специальность: " << obj.get_specialty()
		<< ", опыт преподавания " << obj.get_expirience() << " лет";
	return os;
}

class Graduate : public Student
{
	string subject;
	//Theacher instructor;
public:
	const string& get_subject()const
	{
		return subject;
	}
	
	void set_subject(const string& subject)
	{
		std::regex en_rgx("([A-Za-z][A-Za-z]{1,15}[ -]{0,4}){1,5}");
		std::regex ru_rgx("([А-Яа-я][А-Яа-я]{1,15}[ -]{0,4}){1,5}");
		if (std::regex_match(subject, en_rgx) || std::regex_match(subject, ru_rgx))this->subject = subject;
		else this->subject = "Bad subject";
	}
	
	//				Constructors:
	Graduate
	(
		const string& last_name, const string& first_name, const string& email, const string& phoneNumber, unsigned int age,
		const string& specialty, const string& group, double rating,
		const string& subject
	) :Student(last_name, first_name, email, phoneNumber, age, specialty, group, rating)
	{
		this->subject = subject;		
		cout << "GConstructor: " << endl;
	}
	~Graduate()
	{
		cout << "GDestructor: " << endl;
	}
	//              Methods
	void print()
	{
		Student::print();
		cout << "Тема: " << subject << endl;
	}

};
	ostream& operator<<(ostream& os, const Graduate& obj)
	{
		os << (Student&)obj;
			return os << "\nТема диплома: " << obj.get_subject();
	}

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
		new Student("Васильев", "Александр", "alex@itstep.ru", " +7(915)357-85-21 ", 23, "РПО", "ПВ_011", 90),
		new Student("Васильева", "Маргарита", "rita@itstep.ru", " + 7(915)357-85-21 ",25, "РПО", "ПВ_011", 90),
		new Theacher("Петров-Селёдкин", "Олег", "oleg@itstep.ru", " + 7(915)357-85-21 ", 36, "Разработка приложений на С++", 6),
		new Student("Ивлев", "Александр", "ivlev@itstep.ru", " + 7(915)357-85-21 ", 25, "РПО", "ПВ_011", 95),
		new Graduate("Рахманин", "Николай", "nik@itstep.ru", " + 7(915)357-85-21 ", 28, "РПО", "ПВ_011", 98, "Разработка кросплатформенной обучающей игры"),
		new Theacher("Романов", "Андрей", "andy@itstep.ru", " + 7(915)357-85-21 ", 30, "HardWare PC", 6),
		new Student("Нусс", "Дмитрий", "nuss@itstep.ru", " + 7(915)357-85-21 ", 22, "РПО", "ПВ_011", 100),
		new Student("Борн", "Евгений", "born@itstep.ru", " + 7(915)357-85-21 ", 35, "Разработка програмного-обеспечения", "ПВ_011", 99),
		
	};

	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		//group[i]->print();
		//cout << *group[i] << endl;
		cout << delimiter << endl;
		if (typeid(*group[i]) == typeid(Student))cout << *dynamic_cast<Student*>(group[i]) << endl;
		if (typeid(*group[i]) == typeid(Theacher))cout << *dynamic_cast<Theacher*>(group[i]) << endl;
		if (typeid(*group[i]) == typeid(Graduate))cout << *dynamic_cast<Graduate*>(group[i]) << endl;
	}
		cout << delimiter << endl;

	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		delete[] group[i];
		//cout << delimiter << endl;
	}
}