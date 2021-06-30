#pragma once
#include<iostream>
#include"Human.h"
using namespace std;

class Theacher;
ostream& operator<<(ostream& os, const Theacher& obj);

class Theacher : public Human
{
	string specialty;
	unsigned int expirience;
public:
	const string& get_specialty()const;
	unsigned int get_expirience()const;

	void set_speciality(const string& spetialty);
	void set_expirience(unsigned int expirience);

	Theacher
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& specialty, unsigned int expirience
	);
	~Theacher();

	void print();
};
