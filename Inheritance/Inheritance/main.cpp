﻿#include<iostream>
using namespace std;

class Box
{
	double height, width, depth;
	string material;
public:
	Box(string material, double height, double width, double depth)
	{
		this->material = material;
		this->height = height;
		this->width = width;
		this->depth = depth;
		cout << "BConstructor:\t" << this << endl;
	}
	~Box()
	{
		cout << "Destructor:\t" << this << endl;
	}
	void print()
	{
		cout << "Material: " <<material<<endl;
		cout << "Dimentions: " << height << "x" << width << "x" << depth << endl;
		cout << "Volume: " << height * width * depth << endl;

	}
};

class GiftBox :public Box
{
	string cover;
public:
	GiftBox(string material, double height, double width, double depth):Box(material, height, width, depth)
	{
		this->cover = cover;
		cout << "GBConstructor:\t" << this << endl;
	}
	~GiftBox()
	{
		cout << "GBDestructor:\t" << this << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "Rus");
	Box box("Cardboard", 3, 4, 5);
		box.print();

		GiftBox gift_box("Cardboard", 3, 4, 5);
		gift_box.print();
}