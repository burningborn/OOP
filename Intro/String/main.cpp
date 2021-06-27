#include"String.h"



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