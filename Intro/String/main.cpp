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

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////        CLASS DEFINITION (ОПРЕДЕЛЕНИЕ КЛАССА)          //////////////////////////////////////////////////

	unsigned int String::get_size()const{return size;}
	const char* String::get_str()const{return str;}
	char* String::get_str(){return str;}
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
		if (this == &other)return *this;   //0) Проверяем, не является ли this и other одним и тем же объектом
		delete[] this->str;	              //1) Удаляем старое значение объекта 
		this->size = other.size;         //2) Выполняемкопирование
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

////////////////////        CLASS DEFINITION END (КОНЕЦ ОПРЕДЕЛЕНИЯ КЛАССА)          //////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//#define CONSTRUCTORS_CHECK
//#define INPUT_CHECK
#define OPERATOR_PLUS_CHECK
//#define HOW_CAN_WE_CALL_CONSTRUCTORS

void main()
{

	setlocale(LC_ALL, "Russian");
#ifdef CONSTRUCTORS_CHECK
	String str;
	str.print();
	String str1 = "Hello";
	str1 = str1;
	str1.print();
	cout << str1 << endl;
	String str2 = str1;    //CopyConstrutor
	str2.print();
	String str3;
	str3 = str2;          //CopyAssignment
	cout << str3 << endl;
#endif // CONSTRUCTORS_CHECK

#ifdef INPUT_CHECK
	String str;
	cout << "Введите строку: "; cin >> str;
	cout << str << endl;
#endif // INPUT_CHECK

#ifdef OPERATOR_PLUS_CHECK
	String str1 = "Hello";
	String str2 = "World";
	cout << delimiter << endl;
	String str3 = str1 + str2;
	//MoveMethods или МЕТОДЫ ПЕРЕНОСА: MoveConstructor, MoveAssignment
	cout << delimiter << endl;
	cout << str3 << endl;

	str1 += str2;
	cout << str1 << endl;
#endif // OPERATOR_PLUS_CHECK

#ifdef HOW_CAN_WE_CALL_CONSTRUCTORS
	String str1;                    //Default construcor
	String str2 = "Hello";          //Single-argument construcor
	String str3 = str2;             //Copy constructor - потому что мы создаём объект.
	String str4;
	str4 = str3;                    //Copy Assignment (operator=). Copy constructor вызвать невозможно потому что объёкт str4 уже создан.
	String str5();                  //Не Default constructor. Здесь вообще не создаётся объект.
									//Объявление функции str5, которая ни чего не принимает, и возвращает значение типа Strung.
	String str6{};                  //Явный вызов конструктора по умолчанию.  
#endif // HOW_CAN_WE_CALL_CONSTRUCTORS

}