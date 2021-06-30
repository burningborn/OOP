#pragma once
#include<iostream>
#include"Human.h"
using namespace std;

class Student;
ostream& operator<<(ostream& os, const Student& obj);

class Student : public Human
{
	string specialty;
	string group;
	double rating;
public:
	const string& get_specialty()const;
	const string& get_group()const;
	double get_rating()const;

	void set_specialty(const string& specialty);
	void set_group(const string& group);
	void set_rating(double rating);

	Student
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& specialty, const string& group, double rating
	);
	~Student();

	void print();
};
