#include<iostream>
using namespace std;

//using
#define tab "\t"
#define delimiter "\n-----------------------------------------------------------------------------------\n"
#define HELLO(arg) "Hello "#arg 

class Point   //Описывает точку на плоскости
{
	double x;    //Свойства объекта
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	//				Constructors:
	/*Point()
	{
		x = y = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}*/
	Point(double x = 0, double y = 0)
	{
		// Этот конструктор с параметрами так же является конструктором по умолчанию, по скольку его можно вызвать без параметров,
		//тогда оба его параметра примут значение по умолчанию, т.е. ноль.
		this->x = x;
		this->y = y;
		cout << "Constructor:\t " << this << endl;
	}
	Point(const Point& other) //Конструктор копирования
	{
		//other - это просто имя принимаемого параметра или имя другого объекта
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor: " << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t " << this << endl;
	}

	                         //Operators:
	Point& operator = (const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssigment:\t " << this << endl;
		return *this;
	}

	/*Point operator+(const Point& other)const
	{
		Point result;
		result.x = this->x + other.x;
		result.y = this->y + other.y;
		return result;
	}*/

	Point operator++() //Prefix
	{
		this->x++;
		this->y++;
		cout << "Prefix Increment:\t" << this << endl;
		return *this;
	}

	Point operator++(int) //POstfix
	{
		Point old = *this;
		this->x++;
		this->y++;
		cout << "Suffix Increment:\t" << this << endl;
		return old;
	}



	double distance(Point& other)const
	{
		
		this; //Эта точка , в которой мы находимся              this  - этот
		other; //ТА точка до которой нужно вычислить расстояние other - другой
		double x_distanse = this->x - other.x;
		double y_distanse = this->y - other.y;
		double distatse = sqrt(x_distanse * x_distanse + y_distanse * y_distanse);
		return distatse;
	}

	//				Methods
	void print()
	{
		cout << " x = " << x << tab << " y = " << y << endl;
	}
};
//После того, ка  мы создали структкру можно создавать её объекты
//Создавая структуру или класс мы создаём новывй тип данных

double distanse(const Point& A, const Point& B)
{

	double x_distanse = A.get_x() - B.get_x();
	double y_distanse = A.get_y() - B.get_y();
	double distatse = sqrt(x_distanse * x_distanse + y_distanse * y_distanse);
	return distatse;
}

Point operator+(const Point& left, const Point& right)
{
	Point result;
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());
	cout << "Global Plus" << endl;
	return result;
}



//#define STRUCT
//#define DISTANSE_AND_CNSTRUNCORS
//#define ASSIGMENT_CHECK 

void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef STRUCT
	int a;              //Объявление (создание)переменной
	Point A;
	//Создание объекта структуры Point
	//Объявление объекта cтруктуры POint
//Объект - это самая обычная переменная, но не примитивного типа, а пользовательского.
//Объекты ещё называют экземплярами класса или структуры.
//Структуры и классы ещё называют пользовательскими типами данных.
	A.x = 2;
	A.y = 3;
	cout << A.x << tab << A.y << endl;

	Point* pA = &A;
	cout << pA->x << tab << pA->y << endl;
#endif // STRUCT

#ifdef DISTANSE_AND_CNSTRUNCORS
	Point A(2.3, 4.5);
	/*A.set_x(2);
	A.set_y(3);*/
	cout << sizeof(A) << endl;
	cout << A.get_x() << tab << A.get_y() << endl;
	A.print();

	Point B;				//DefaultConstructor
	B.distance(A);
	//B.print();

	Point C = A;			//CopyConstructor

	Point D(6.7, 8.3);
	cout << delimiter;
	cout << " Расстояние от точки A до точки D: " << A.distance(D) << endl; //A - this, D - other
	cout << " Расстояние от точки D до точки A: " << D.distance(A) << endl; //D - this, A - other

	cout << " Расстояние между точками A и D: " << distanse(A, D) << endl;
	cout << " Расстояние между точками D и A: " << distanse(D, A) << endl;

	B = D;  //CopyAssigment

	///////////////////////////////////////////////////////////////////////////////////////////////
	cout << delimiter << endl;
	Point E = A;  //CopyConstructor
	Point F;
	F = D;   // CopyAssigment
	cout << delimiter << endl;
	///////////////////////////////////////////////////////////////////////////////////////////////  
#endif // DISTANSE_AND_CNSTRUNCORS

#ifdef ASSIGMENT_CHECK
	int a, b, c;
	a = b = c = 0;
	cout << a << tab << b << tab << c << endl;

	cout << delimiter << endl;
	Point A, B, C;
	A = B = C = Point(2.3, 4.5); //Point(2.3, 4.5) - явный вызов конструктора.
								//Создаётся временный безимянный объект 
							   //который существует только в пределах этого выражения.
	cout << delimiter << endl;
	//l-value = r-rvalue;
	//Point  = void;
	A.print();
	B.print();
	C.print();
	cout << delimiter << endl;
#endif // ASSIGMENT_CHECK

	//cout << HELLO(guy) << endl;

	int a = 2;
	int b = 3;
	a + b;

	Point A(2.3, 4.5);
	Point B(2.7, 3.14);
	cout << delimiter << endl;
	Point C = A + B;
	cout << delimiter << endl;
	C.print();
	cout << delimiter << endl;
	++C;
	C.print();
	cout << delimiter << endl;
	C++;
	C.print();


}
/*
Обращение к полям
*/