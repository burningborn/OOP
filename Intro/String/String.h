#pragma once
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n----------------------------------------------------------------------------\n"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////     CLASS DECLARATION (ОБЪЯВЛЕНИЕ КЛАССА)         ////////////////////////////////////////////

class String;
String operator+(const String& left, const String& right);

std::ostream& operator<<(std::ostream& os, const String& obj);
std::istream& operator>> (std::istream& is, const String& obj);

class String           //     ОПИСАНИЕ КЛАССА
{
	unsigned int size; //     Размер строки в байтах
	char* str;         //     Указатель на строку в динамической памяти
public:
	unsigned int get_size()const;
	const char* get_str()const;
	char* get_str();
	//                        Constructors
	explicit String(unsigned int size = 80);
	String(const char str[]);
	String(const String& other);
	String(String&& other);
	~String();
	//                       Operators
	String& operator=(const String& other);
	char& operator[](unsigned int i);
	const char operator[](unsigned int i)const;
	String& operator+=(const String& other);
	//                       Methods
	void print()const;
};

////////////////////     CLASS DECLARATION END (КОНЕЦ ОБЪЯВЛЕНИЯ КЛАССА)         ////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////