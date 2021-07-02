#include"Leaver.h"
#include"Graduate.h"

const string& Leaver::get_diplomColor()const {return diplomColor;}
void Leaver::set_diplomColor(const string& diplomColor) { this->diplomColor = diplomColor; }

Leaver::Leaver
(
	const string& last_name, const string& first_name, unsigned int age,
	const string& specialty, const string& group, double rating, const string& subject,
	const string& diplomColor
) :Graduate(last_name, first_name, age, specialty, group, rating, subject)
{
	this->diplomColor = diplomColor;
	cout << "LConstructor: " << endl;
}

Leaver::~Leaver() { cout << "LDestructor: " << endl; }

void Leaver::print()
{
	Graduate::print();
	cout << "Диплом: " << diplomColor << endl;
}
ostream& operator<<(ostream& os, const Leaver& obj)
{
	os << (Graduate&)obj;
	return os << "\nЦвет диплома: " << obj.get_diplomColor() << endl;
}