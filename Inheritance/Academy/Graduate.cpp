#include"Graduate.h"

	const string& Graduate::get_subject()const{return subject;}
	void Graduate::set_subject(const string& subject){this->subject = subject;}

	Graduate::Graduate
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& specialty, const string& group, double rating,
		const string& subject
	) :Student(last_name, first_name, age, specialty, group, rating)
	{
		this->subject = subject;
		cout << "GConstructor: " << endl;
	}
	Graduate::~Graduate()
	{
		cout << "GDestructor: " << endl;
	}

	void Graduate::print()
	{
		Student::print();
		cout << "Тема: " << subject << endl;
	}

ostream& operator<<(ostream& os, const Graduate& obj)
{
	os << (Student&)obj;
	return os << "\nТема диплома: " << obj.get_subject();
}
