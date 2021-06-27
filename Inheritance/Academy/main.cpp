#include<iostream>
using namespace std;

#define delimiter "\n----------------------------------------------------------------------\n"

class Human
{
	string last_name;
	string first_name;
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
	unsigned int get_age()const
	{
		return age;
	}
	void set_last_name(const string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(unsigned int age)
	{
		this->age = age;
	}

	//Constructors
	Human(const string& last_name, const string& first_name, unsigned int age)
	{
		set_last_name(last_name);
		set_first_name(first_name);
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
		cout << last_name << " " << first_name << " " << age << " ���."<<endl;
	}

};

ostream& operator<<(ostream& os, const Human& obj)
{
	os << obj.get_last_name() << " " << obj.get_first_name() << " " << obj.get_age() << " ���.";
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
		this->specialty = specialty;
	}
	void set_group(const string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}

	//				Constructors:
	Student
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& specialty, const string& group, double rating
	) :Human(last_name, first_name, age)
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
		cout << "�������������: " << specialty << ", ������: " << group << ", ������������: " << rating << endl;
	}
};

ostream& operator<<(ostream& os, const Student& obj)
{
	os << (Human)obj << " ";
	os << "�������������: " << obj.get_specialty() << ", ������: " << obj.get_group() << ", ������������: " << obj.get_rating();
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
		this->specialty = spetialty;
	}
	void set_expirience(unsigned int expirience)
	{
		this->expirience = expirience;
	}

	//				Constructors:
	Theacher
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& specialty, unsigned int expirience
	) :Human(last_name, first_name, age)
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
		cout << "�������������: " << specialty << ", ���� ������������: " << expirience << " ���" << endl;
	}
};

ostream& operator<<(ostream& os, const Theacher& obj)
{
	os << (Human)obj << " ";
	os << ", �������������: " << obj.get_specialty()
		<< ", ���� ������������" << obj.get_expirience() << " ���";
	return os;
}

class Graduate : public Human
{
	string topic;
	string decision;
public:
	const string& get_topic()const
	{
		return topic;
	}
	const string& get_decision()const
	{
		return decision;
	}
	void set_topic(const string& topic)
	{
		this->topic = topic;
	}
	void set_decision(const string& decision)
	{
		this->decision = decision;
	}
	//				Constructors:
	Graduate
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& topic, const string& decision
	) :Human(last_name, first_name, age)
	{
		this->topic = topic;
		this->decision = decision;
		cout << "GConstructor: " << endl;
	}
	~Graduate()
	{
		cout << "GDestructor: " << endl;
	}
	//              Methods
	void print()
	{
		Human::print();
		cout << "����: " << topic << ", �������: " << decision << endl;
	}

};
	ostream& operator<<(ostream& os, const Graduate& obj)
	{
		os << (Human)obj << " ";
		os << "����: " << obj.get_topic() 
		<< ", �������: " << obj.get_decision();
		return os;
	}

//#define INHERITANCE_BASICS

void main()
{
	setlocale(LC_ALL, "Rus");
#ifdef INHERITANCE_BASICS
	/*Human human("�������", "�������", 18);
human.print();	*/
	Student stud("������� ", "�������", 18, "���", "BV_123", 43.4);
	stud.print();
	Theacher Albert("Einstein", "Albert", 150, "Astrophisics", 120);
	Albert.print();
#endif // INHERITANCE_BASICS

	//                POINTERS TO BASE CLASS
	Human* group[] =
	{
		new Student("��������", "���������", 23, "���", "��_011", 90),
		new Student("���������", "���������", 25, "���", "��_011", 90),
		new Theacher("������", "����", 36, "���������� ���������� �� �++", 6),
		new Student("�����", "���������", 25, "���", "��_011", 95),
		new Student("��������", "�������", 28, "���", "��_011", 98),
		new Theacher("�������", "������", 30, "HardWare PC", 6),
		new Student("����", "�������", 22, "���", "��_011", 100),
		new Student("����", "�������", 35, "���", "��_011", 99),
		new Graduate("������", "����", 20, "����������� ���������� ����������� ����� �������", "��������")
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