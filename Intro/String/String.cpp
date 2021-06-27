#include"String.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////        CLASS DEFINITION (ÎÏÐÅÄÅËÅÍÈÅ ÊËÀÑÑÀ)          //////////////////////////////////////////////////

unsigned int String::get_size()const { return size; }
const char* String::get_str()const { return str; }
char* String::get_str() { return str; }
//                        Constructors
String::String(unsigned int size)
{
	this->size = size;
	this->str = new char[size] {};
	cout << "DefConstructor:\t" << this << endl;
}
String::String(const char str[])
{
	this->size = strlen(str) + 1;
	this->str = new char[size] {};
	for (int i = 0; str[i]; i++)this->str[i] = str[i];
	cout << "Constructor: \t" << this << endl;
}
String::String(const String& other)
{
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)this->str[i] = other.str[i];
	cout << "CopyConstructor:" << this << endl;
}
String::String(String&& other)
{
	this->size = other.size;
	this->str = other.str;
	other.str = nullptr;
	cout << "MoveConstructor:" << this << endl;
}

String::~String()
{
	delete[] this->str;
	cout << "Destructor: \t" << this << endl;
}
//                       Operators
String& String::operator=(const String& other)
{
	if (this == &other)return *this;   //0) Ïðîâåðÿåì, íå ÿâëÿåòñÿ ëè this è other îäíèì è òåì æå îáúåêòîì
	delete[] this->str;	              //1) Óäàëÿåì ñòàðîå çíà÷åíèå îáúåêòà 
	this->size = other.size;         //2) Âûïîëíÿåìêîïèðîâàíèå
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)this->str[i] = other.str[i];
	cout << "CopyAssignment: \t" << this << endl;
	return *this;
}
char& String::operator[](unsigned int i)
{
	return str[i];
}
const char String::operator[](unsigned int i)const
{
	return str[i];
}
String& String::operator+=(const String& other)
{

	return *this = *this + other;
}
//                       Methods
void String::print()const
{
	cout << "Size " << size << endl;
	cout << "Str " << str << endl;
}
std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}
std::istream& operator>> (std::istream& is, const String& obj)
{
	return is >> obj.get_str();
}

String operator+(const String& left, const String& right)
{
	String cat(left.get_size() + right.get_size() - 1);  //Size constructor
	for (int i = 0; i < left.get_size(); i++)
		//cat.get_str()[i] = left.get_str()[i];
		cat[i] = left[i];
	for (int i = 0; i < right.get_size(); i++)
		//cat.get_str()[i + left.get_size() - 1] = right.get_str()[i];
		cat[i + left.get_size() - 1] = right[i];
	return cat;
}

////////////////////        CLASS DEFINITION END (ÊÎÍÅÖ ÎÏÐÅÄÅËÅÍÈß ÊËÀÑÑÀ)          //////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////