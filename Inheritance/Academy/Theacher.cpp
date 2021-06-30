#include"Theacher.h"

	const string& Theacher::get_specialty()const{return specialty;}
	unsigned int Theacher::get_expirience()const{return expirience;}

	void Theacher::set_speciality(const string& spetialty){this->specialty = spetialty;}
	void Theacher::set_expirience(unsigned int expirience){this->expirience = expirience;}

	Theacher::Theacher
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& specialty, unsigned int expirience
	) :Human(last_name, first_name, age)
	{
		this->specialty = specialty;
		this->expirience = expirience;
		cout << "TConstructor: " << endl;
	}
	Theacher::~Theacher()
	{
		cout << "TDestructor: " << endl;
	}

	void Theacher::print()
	{
		Human::print();
		cout << "Специальность: " << specialty << ", опыт преаодавания: " << expirience << " лет" << endl;
	}

ostream& operator<<(ostream& os, const Theacher& obj)
{
	os << (Human)obj << " ";
	os << "Специальность: " << obj.get_specialty()
		<< ", опыт преподавания" << obj.get_expirience() << " лет";
	return os;
}