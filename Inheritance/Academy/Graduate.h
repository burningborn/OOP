#pragma once
#include<iostream>
#include"Student.h"
using namespace std;

class Graduate;
ostream& operator<<(ostream& os, const Graduate& obj);

class Graduate : public Student
{
	string subject;	
public:
	const string& get_subject()const;
	void set_subject(const string& subject);

	Graduate
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& specialty, const string& group, double rating,
		const string& subject
	);
	~Graduate();

	void print();
};


