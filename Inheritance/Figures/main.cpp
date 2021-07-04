#define _USE_MATH_DEFINES
#include<iostream>
#include<Windows.h>

using std::cin;
using std::cout;
using std::endl;

namespace Geometry
{
	//typedef unsigned int Color;
	enum Color
	{
		console_black = 0x00,
		console_white = 0xFF,//0xFFFFFF00,
		console_red = 0xCC,//0xFF000000,
		console_green = 0xAA,//0x00FF0000,
		console_blue = 0x99,//0x0000FF00
		default_console_color = 7,

		black = 0x00000000,
		red   = 0x000000FF,
		green = 0x0000AA00,
		yellow= 0x0000FFFF,
		blue  = 0x00FF0000,
		grey  = 0x00555555,
		white = 0x00FFFFFF,
	};

	class Shape
	{
	protected:
		Color color;

	public:
		Shape(Color color) :color(color) {}
		virtual	~Shape() {}

		virtual double get_area()const = 0;
		virtual double get_perimeter()const = 0;
		virtual void drow()const = 0;
		virtual void info()const = 0;
	};

	class Square :public Shape
	{
		double side;
	public:
		double get_side() { return side; }
		double set_side(double side)
		{
			if (side <= 0)side = 1;
			this->side = side;
			return this->side;
		}
		Square(Color color, double side) :Shape(color)
		{
			set_side(side);
		}
		~Square() {}


		double get_area()const
		{
			return side * side;
		}
		double get_perimeter()const
		{
			return side * 4;
		}
		void drow()const
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			unsigned int default_color;
			SetConsoleTextAttribute(hConsole, color);

			for (int i = 0; i < side; i++)
			{
				for (int j = 0; j < side; j++)
				{
					cout << "* ";
				}
				cout << endl;
			}
			SetConsoleTextAttribute(hConsole, 7);
		}
		void info()const
		{
			cout << endl;
			cout << "Квадрат      :\n";
			cout << "Длина стороны: " << side << endl;
			cout << "Площадь      : " << get_area() << endl;
			cout << "Периметр     : " << get_perimeter() << endl;
			cout << endl;
			drow();
		}
	};

	class Rectangle :public Shape
	{
		double lenght;
		double width;
	public:
		double get_lenght()const { return lenght; }
		double get_width()const { return width; }

		void set_lenght(double lenght)
		{
			if (lenght <= 0)lenght = 1;
			this->lenght = lenght;
		}
		void set_widht(double width)
		{
			if (width <= 0)width = 1;
			this->width = width;
		}
		Rectangle(Color color, double lenght, double width) :Shape(color)
		{
			set_lenght(lenght);
			set_widht(width);
		}
		~Rectangle() {}

		double get_area()const
		{
			return lenght * width;
		}
		double get_perimeter()const
		{
			return (lenght + width) * 2;
		}
		void drow()const
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			unsigned int default_color;
			SetConsoleTextAttribute(hConsole, color);

			for (int i = 0; i < width; i++)
			{
				for (int j = 0; j < lenght; j++)
				{
					cout << "* ";
				}
				cout << endl;
			}
			SetConsoleTextAttribute(hConsole, 7);
		}
		void info()const
		{
			cout << endl;
			cout << "Прямоугольник  :\n";
			cout << "Длина          : " << lenght << endl;
			cout << "Ширина         : " << width << endl;
			cout << "Площадь        : " << get_area() << endl;
			cout << "Периметр       : " << get_perimeter() << endl;
			cout << endl;
			drow();
		}
	};
	class Circle :public Shape
	{
		UINT start_x;
		UINT start_y;
		double radius;
	public:
		double get_radius()const { return radius; }
		double get_diameter()const { return radius * 2; }
		void set_radius(double radius)
		{
			if (radius <= 0)radius - 1;
			this->radius = radius;
		}
		void set_start_x(UINT x)
		{
			if (x >= 1000)x = 1000;
			start_x = x;
		}
		void set_start_y(UINT y)
		{
			if (y >= 700)y = 700;
			start_y = y;
		}
		Circle(Color color, double radius, UINT start_x = 0, UINT start_y = 0) :Shape(color)
		{
			set_radius(radius);
			set_start_x(start_x);
			set_start_y(start_y);
		}
		~Circle() {};

		double get_area()const
		{
			return M_PI * pow(radius, 2);
		}
		double get_perimeter()const
		{
			return 2 * M_PI * radius;
		}
		void drow()const
		{
			int x1 = 200;
			int y1 = 200;
			int x2 = x1 + get_diameter();
			int y2 = y1 + get_diameter();
			cout << "Здесь должен быть круг:-)" << endl;
			HWND hwnd = GetConsoleWindow();
			// 1) Создаем конткст устройства
			//hwnd = FindWindow(NULL, L"Inheritance - Microsoft Visual Studio");
			HDC hdc = GetDC(hwnd);
			// 2) Создаем кисть которой будем рисовать
			HPEN hPen = CreatePen(PS_SOLID, 5, blue); //PS_SOLID - сплошная линия, 5 - пикселей, цвет(RGB )

			HBRUSH hBrush = CreateSolidBrush(blue);

			// 3) Выбираем: на чём и чем будем рисовать
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			// 4) Рисуем:
			//Ellipse(hdc, 200, 200, 500, 500);
			Ellipse(hdc, start_x, start_y, start_x + get_radius(), start_y + get_radius());

			//После того как кисть использовани, её нужно удалить
			DeleteObject(hPen);
			DeleteObject(hBrush);
			ReleaseDC(hwnd, hdc);
		}
		void info()const
		{
			cout << endl;
			cout << "Круг\n";
			cout << "Радиус: " << radius << endl;
			cout << "Площадь: " << get_area() << endl;
			cout << "Периметр: " << get_perimeter() << endl;
			cout << endl;
			drow();
		}
	};

	class Triangle :public Shape
		{
		public:
			Triangle(Color color) :Shape(color) {}
			~Triangle() {}

	};

	class EquilateralTriangle : Triangle
	{
		UINT start_x;
		UINT start_y;
			double side;
		public:
			double get_side()const { return side; }
			double get_hight()const
			{
				return side * pow(3, .5) / 2;
			}
			void set_side(double side)
			{
				if (side <= 0)side = 1;
				this->side = side;
			}
			void set_start_x(UINT x)
			{
				if (x >= 1000)x = 1000;
				start_x = x;
			}
			void set_start_y(UINT y)
			{
				if (y >= 700)y = 700;
				start_y = y;
			}
			EquilateralTriangle(Color color, double side, UINT start_x=0, UINT start_y=0) :Triangle(color)
			{
				set_side(side);
				set_start_x(start_x);
				set_start_y(start_y);
			}
			~EquilateralTriangle(){}
			double get_area()const
			{
				return side * 3;
			}

			double get_perimeter()const
			{
				return side * 3;
			}
			void drow()const
			{
				HWND hwnd = GetConsoleWindow();
				HDC hdc = GetDC(hwnd);

				HPEN hPen = CreatePen(PS_SOLID, 5, color);
				HBRUSH hBrush = CreateSolidBrush(color);

				SelectObject(hdc, hPen);
				SelectObject(hdc, hBrush);
				POINT points[] =
				{
					{start_x, start_y + side},
				    {start_x + side, start_y + side},
					{start_x + side / 2, start_y + side - get_hight()}
				};

				Polygon(hdc, points, sizeof(points) / sizeof(POINT));

				DeleteObject(hPen);
				DeleteObject(hBrush);

				ReleaseDC(hwnd, hdc);
			}

			void info()const
			{
				cout << endl;
				cout << "Треугольник\n";
				cout << "Дина стороны: " << side << endl;
				cout << "Высота      : " << side << endl;
				cout << "Площадь: " << get_area() << endl;
				cout << "Периметр: " << get_perimeter() << endl;
				cout << endl;
				drow();
			}

	};
	//class IsoscelesTriange
}

//Rectangle(HDC hdc, UINT left_up_x, UNIT left_up_y, UNIT right _down_x, UNIT right _down_y);
//Ellipse(HDC hdc, UINT left_up_x, UNIT left_up_y, UNIT right _down_x, UNIT right _down_y);

void main()
{
	setlocale(LC_ALL, "Russian");
	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD buffer = { 80,50 };
	SetConsoleDisplayMode(hConsole, CONSOLE_FULLSCREEN, &buffer);

	Geometry::Square square(Geometry::Color::console_red, 5);
	square.info();

	Geometry::Rectangle rectangle(Geometry::Color::console_green, 4, 8);
	rectangle.info();

	Geometry::Circle circle(Geometry::Color::red, 100, 880, 200);
	circle.info();

	Geometry::EquilateralTriangle equil_triangle(Geometry::Color::red, 200, 200, 200);
	equil_triangle.info();
}