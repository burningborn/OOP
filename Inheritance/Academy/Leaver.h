#pragma once
#include<iostream>
#include"Graduate.h"
using namespace std;

class Leaver;
ostream& operator<<(ostream& os, const Leaver& obj);

class Leaver : public Graduate
{
	string diplomColor;
public:
	const string& get_diplomColor()const;
	void set_diplomColor(const string& diplomColor);

	Leaver
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& specialty, const string& group, double rating, const string& subject,
		const string& diplomColor
	);
	~Leaver();

	void print();
};

