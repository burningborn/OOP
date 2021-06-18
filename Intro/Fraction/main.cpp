#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n-----------------------------------------------------------------------------------\n"

class Fraction;

Fraction operator+(Fraction left, Fraction right);
Fraction operator-(Fraction left, Fraction right);
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(Fraction left, Fraction right);

class Fraction
{
	int integer;
	int numerator;
	int denominator;
public:
	int get_integer()const { return integer; }
	int get_numerator()const { return numerator; }
	int get_denominator()const { return denominator; }
	void set_integer(int integer) { this->integer = integer; }
	void set_numerator(int numerator) { this->numerator = numerator; }
	void set_denominator(int denominator) { if (denominator == 0)denominator = 1; this->denominator = denominator; }

	friend ostream& operator<<(ostream& os, const Fraction& obj);
	friend istream& operator>>(istream& is, Fraction& obj);
	//         Constructors
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		//cout << "DfaultArgunentConstructor:\t" << this << endl;
	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		//cout << "SingleArgunentConstructor:\t" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->denominator = denominator;
		//cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->set_integer(integer);
		this->set_numerator(numerator);
		this->set_denominator(denominator);
		//cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		//cout << "Copy:\t" << this << endl;
	}

	~Fraction()
	{
		//cout << "Destructor:\t" << this << endl;
	}

	                    //Operators:
	explicit operator int()const
	{
		return integer;
	}
	explicit operator double()const
	{
		
		return integer + ((double)numerator / denominator);
	}

	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		//cout << "Copy=:\t" << this << endl;
		return *this;
	}

	                 //Compound assignments

	Fraction& operator+=(const Fraction& other) {return *this = *this + other;}
	Fraction& operator-=(const Fraction& other) {return *this = *this - other;}
	Fraction& operator*=(const Fraction& other) {return *this = *this * other;}
	Fraction& operator/=(const Fraction& other) {return *this = *this / other;}

	                 //Increment/Decrement

	Fraction& operator++()
	{
		integer++;
		return *this;
	}
	Fraction operator++(int)
	{
		Fraction old = *this;
		integer++;
		return old;
	}
	Fraction& operator--()
	{
		integer--;
		return *this;
	}
	Fraction operator--(int)
	{
		Fraction old = *this;
		integer--;
		return old;
	}

	                     //Methods

	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction inverted()
	{
		to_improper();
		Fraction inverted(denominator, numerator);
		return inverted;
	}
	Fraction to_common(Fraction& other)  //Приведение к общему знаменателю
	{
		this->to_improper(); other.to_improper();
		Fraction One = *this;
		Fraction Two = other;
		One.numerator *= other.denominator;
		Two.numerator *= this->denominator;
		One.denominator = Two.denominator *= this->denominator;
		*this = One;
		other = Two;
		return *this;
	}
	Fraction& simplification()  //Сокращение дробей
	{
		this->to_improper();
		Fraction result;
		int tempA = result.numerator = this->numerator;
		int tempB = result.denominator = this->denominator;

		if (tempA < 0)tempA *= -1;

		while (tempA != tempB) // алгоритм Евклида
		{
			if (tempA > tempB)swap(tempA, tempB);
			tempB = tempB - tempA;
		}
		result.numerator /= tempA;
		result.denominator /= tempA;
		return *this = result.to_proper();
	}

	void print()
	{
		if (integer)cout << integer;
		if (integer && numerator) cout << "(";
		if (numerator) cout << numerator << "/" << denominator;
		if (integer && numerator) cout << ")";
		if (integer == 0 && numerator == 0) cout << 0;
		cout << endl;
	}
};

Fraction operator+(Fraction left, Fraction right)
{
	left.to_common(right);
	return Fraction 
		(
			left.get_numerator() + right.get_numerator(),
			left.get_denominator()
		).to_proper();
}
Fraction operator-(Fraction left, Fraction right)
{
	left.to_common(right);
	return Fraction
		(
			left.get_numerator() - right.get_numerator(),
			left.get_denominator()
		).to_proper();
}
Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper(); right.to_improper();
	return Fraction //Явно вызываем конструктор и передаём в него параметры
		//Этот конструктор создаёт временный безимянный объект, который сразу же отправляется return-у
		(
			left.get_numerator() * right.get_numerator(),
			left.get_denominator() * right.get_denominator()
		).to_proper();
}
Fraction operator/(Fraction left, Fraction right) {return left * right.inverted();}
 
                   // Comparison Operators

bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() == right.get_numerator() * left.get_denominator();
}
bool operator!=(Fraction left, Fraction right)
{
	return !(left == right);
}
bool operator< (Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() < right.get_numerator() * left.get_denominator();
}
bool operator> (Fraction left, Fraction right) {return !(left < right);}
bool operator<=(Fraction left, Fraction right) {return (left < right || left == right);}
bool operator>=(Fraction left, Fraction right) {return (left > right || left == right);}

               //In/Out operators

ostream& operator<<(ostream& os, const Fraction& obj)
{
	if (obj.get_integer())cout << obj.get_integer();
	if (obj.get_integer() && obj.get_numerator()) cout << "(";
	if (obj.get_numerator()) cout << obj.get_numerator() << "/" << obj.get_denominator();
	if (obj.get_integer() && obj.get_numerator()) cout << ")";
	if (obj.get_integer() == 0 && obj.get_numerator() == 0) cout << 0;
	return os;
}
istream& operator>>(istream& is, Fraction& obj)
{
	cout << "Введите целое, числитель и знаменатель. Росле каждого числа введите ENTER.\n";
	is >> obj.integer >> obj.numerator >> obj.denominator;
	return is;
}

//#define CONSTRUCTOR_CHEK
//#define ARIPHMETICAL_OPERATORS_CHECK
//#define INCREMENT_CHECK
//#define OPERATORS
#define TYPE_CONVRSIONS

void main()
{
	setlocale(LC_ALL, "Rus");
#ifdef CONSTRUCTOR_CHEK

	Fraction A = 5;
	A.print();
	Fraction B(2, 3, 4);
	B.print();
	Fraction C(1, 2);
	C.print();
	Fraction D;
	D.print();
#endif // CONSTRUCTOR_CHEK

#ifdef ARIPHMETICAL_OPERATORS_CHECK
	Fraction A(1, 2, 3);
	/*A.to_improper();
	A.print();*/
	Fraction B(19, 5);
	/*B.to_proper();
	B.print();*/

	Fraction C = A * B; C.print();
	Fraction D = A / B; D.print();
	A *= B; A.print();

	cout << "---------------------------------\n";

	A /= B; A.print();
#endif // ARIPHMETICAL_OPERATORS_CHECK

#ifdef INCREMENT_CHECK
	for (double i = .25; i < 10; i++)
	{
		cout << i << "\t";
	}
	for (Fraction i(1, 4); i.get_integer() < 10; i++)
	{
		cout << i << "\t";
	}
#endif // INCREMENT_CHECK

	//Fraction A(1, 2);
	//Fraction B(5, 11);
	//cout << (A != B) << endl;
#ifdef OPERATORS
	Fraction A(3, 5);
	Fraction B(2, 3);
	Fraction C(0, 0);
	Fraction D(0, 0, 0);

	cout << "Объект A:\t "; A.print();
	cout << "Объект B: \t"; B.print();

	cout << delimiter << endl;

	C = A + B; cout << "Сложение : C = A + B = "; C.simplification(); C.print();
	C = A - B; cout << "Вычитание: C = A - B = "; C.simplification(); C.print();
	C = A * B; cout << "Умножение: C = A * B = "; C.simplification(); C.print();
	C = A / B; cout << "Деление  : C = A / B = "; C.simplification(); C.print();

	cout << delimiter << endl;

	D = ++C; cout << "Инкремент префиксный : D = ++C "; D.print();
	D = C++; cout << "Инкремент постфиксный: D = C++ "; D.print();
	cout << "Инкремент постфиксный: C++ "; C.print();

	cout << delimiter << endl;

	D = --C; cout << "Декремент префиксный : D = --C "; C.print();
	D = C--; cout << "Декремент постфиксный: D = C-- "; D.print();
	cout << "Декремент постфиксный: C--; "; C.print();

	cout << delimiter << endl;

	A += B; cout << "Плюс   -    равно: A += B = "; A.simplification(); A.print();
	A -= B; cout << "Минус   -   равно: A -= B = "; A.simplification(); A.print();
	A *= B; cout << "Умножить -  равно: A *= B = "; A.simplification(); A.print();
	A /= B; cout << "Разделить - равно: A /= B = "; A.simplification(); A.print();

	cout << delimiter << endl;

	cout << "Равно   : A == B? --> ";  cout << A << " равно " << B << " = " << (A == B) << endl;
	cout << "Не равно: A != B? --> ";  cout << A << " не равно " << B << " = " << (A != B) << endl;
	cout << "Меньше  : A <  B? --> ";  cout << A << " меньше " << B << " = " << (A < B) << endl;
	cout << "Больше  : A >  B? --> ";  cout << A << " больше " << B << " = " << (A > B) << endl;
	cout << "Меньше или равно : A <= B? --> ";  cout << A << " меньше или равно " << B << " = " << (A <= B) << endl;
	cout << "Больше или равно : A >= B? --> ";  cout << A << " больше или равно " << B << " = " << (A >= B) << endl;

	cin >> A; cout << " A равно " << A << endl;
#endif // OPERATORS

#ifdef TYPE_CONVRSIONS
	Fraction A(2, 3, 4);
	cout << A << endl;
	int a = (int)A;
	cout << "a = " << a << endl;
	double b = (double)A;
	cout << "b = " << b << endl;
#endif // TYPE_CONVRSIONS

}