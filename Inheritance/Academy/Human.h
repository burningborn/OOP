#pragma once
#include<iostream>
using namespace std;

class Human;
ostream& operator<<(ostream& os, const Human& obj);

class Human
{
	string last_name;
	string first_name;
	unsigned int age;
public:
	const string& get_last_name()const;
	const string& get_first_name()const;
	unsigned int get_age()const;

	void set_last_name(const string& last_name);
	void set_first_name(const string& first_name);
	void set_age(unsigned int age);

	Human(const string& last_name, const string& first_name, unsigned int age);
	virtual ~Human();

	virtual void print();
};