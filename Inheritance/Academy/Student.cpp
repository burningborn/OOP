#include"Student.h"

	const string& Student::get_specialty()const{return specialty;}
	const string& Student::get_group()const{return group;}
	double Student::get_rating()const{return rating;}

	void Student::set_specialty(const string& specialty){this->specialty = specialty;}
	void Student::set_group(const string& group){this->group = group;}
	void Student::set_rating(double rating){this->rating = rating;}

	Student::Student
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
	Student::~Student()
	{
		cout << "SDestructor: " << endl;
	}

	void Student::print()
	{
		Human::print();
		cout << "Специальность: " << specialty << ", группа: " << group << ", успеваемость: " << rating << endl;
	}

	ostream& operator<<(ostream& os, const Student& obj)
		{
		os << (Human)obj << " ";
		os << "Специальность: " << obj.get_specialty() << ", группа: " << obj.get_group() << ", успеваемость: " << obj.get_rating();
		return os;
		}