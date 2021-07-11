#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

/*
TODO:
� ����� ForwardList �������� ������:
	void pop_front();
	void pop_back();
	void insert(...);	//��������� ������� �� ���������� �������
	void erase(...);	//�������� ������� �� ���������� �������
*/

#define tab "\t"
//ostream& operator<<(ostream& os, Element& obj);
//ostream& operator<<(ostream& os, ForwardList& obj);

class Element
{
	int Data;
	Element* pNext;
	static int count;
public:
	int get_Data() { return Data; }
	Element& get_pNext() { return *pNext; }
	void set_Data(int Data) { this->Data = Data; }

	Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
	{
		count++;
		cout << "EConstructor:\t" << this << endl;
	}
	~Element()
	{
		count--;
		cout << "EDestructor:\t" << this << endl;
	}
	friend class ForwardList;
	Element& operator=(int Data) 
	{ 
		this->set_Data(Data); 
	}
};
int Element::count = 0;

class ForwardList
{
	Element* Head;
	size_t size;
public:
	Element& get_Head() { return *Head; }
	size_t get_size() { return size; }
	int set_size(int n)
	{
		this->size = n;
	}

	ForwardList()	//Default constructor - ������� ������ ������.
	{
		this->Head = nullptr;	//���� ������ ��������� �� 0, �� ������ ����.
		this->size = 0;
		cout << "LConstructor:\t" << this << endl;
	}
	explicit ForwardList(size_t size):ForwardList()
	{
		while (size--)push_front(0);
		cout << "LArgConstructor:\t" << this << endl;
	}
	ForwardList(const ForwardList& other) :ForwardList()
	{
		Element* Temp = other.Head;
		while (Temp)
		{
			push_back(Temp->Data);
			Temp = Temp->pNext;
		}
		cout << "LCopyConstructor:\t" << this << endl;
	}

	~ForwardList()
	{
		while (Head)pop_front();
		cout << "LDestructor:\t" << this << endl;
	}

	//			Adding elements:
	void push_front(int Data)
	{
		//���������� �������� � ������ ������:

		////1) ������� �������:
		//Element* New = new Element(Data);

		////2) ����������� ����� ������� � ������:
		//New->pNext = Head;

		////3) ����� ������ �������� �������� � ������, 
		//Head = New;
		//����� ����, ����� ������� �������� ��������� ��������� ������
		Head = new Element(Data, Head);
		size++;
	}
	void push_back(int Data)
	{
		if (Head == nullptr)
		{
			//���� ������ ����, �������� �����, ������� ����� ��������� ������� � ������ ������.
			return push_front(Data);
			//return;
		}
		//1)������� ����� �������:
		//Element* New = new Element(Data);

		//2)����� �� ����� ������ (�� ���������� ��������):
		Element* Temp = Head;
		while (Temp->pNext)
			Temp = Temp->pNext;	//��������� �� ��������� �������
		//3)� pNext ���������� �������� �������� ����� ������ ��������:
		Temp->pNext = new Element(Data);
		size++;
	}
	void insert(int index, int Data)
	{
		if (index > size)return;
		if (index == 0)return push_front(Data);
		//1) ������� ����� �������:
		Element* New = new Element(Data);
		//2) ������� �� ��������, ������� ��������� ����� ����������� ���������:
		Element* Temp = Head;
		for (int i = 0; i < index - 1; i++)
			Temp = Temp->pNext;
		//3) ��������� ����� ������� � ������:
		//Temp - ���������� �������, ������������ ���� ��������, �� ����� �������� ����� ������� �������.
		//Temp->pNext - �������, �� ����� �������� �� ��������� ����� �������.
		//Temp->pNext � ��� ����������� �������� ����� �������� �� 1 ������� ������.
		/*New->pNext = Temp->pNext;
		Temp->pNext = New;*/
		Temp->pNext = new Element(Data, Temp->pNext);
		size++;
	}

	//			Removing elements:
	void pop_front()
	{
		//1) ���������� ����� ���������� ��������:
		Element* Temp = Head;
		//2) ������� ������ �� ��������� ������� ������:
		Head = Head->pNext;
		//3) ������� ������� �� ������:
		delete Temp;
		size--;
	}
	void pop_back()
	{
		//1) ������� �� �������������� ��������:
		Element* Temp = Head;
		while (Temp->pNext->pNext)
			Temp = Temp->pNext;
		delete Temp->pNext;
		Temp->pNext = nullptr;
		size--;
	}
	void erase(int index)
	{
		if (index > size)return;
		if (index == 0)return pop_front();
		Element* Temp = Head;
		for (int i = 0; i < index - 1; i++)
			Temp = Temp->pNext;
		Element* Remover = Temp->pNext->pNext;
		delete Temp->pNext;
		Temp->pNext = Remover;
		size--;
	}

	//			Methods:
	void print()const
	{
		/*Element* Temp = Head;	//Temp - ��� ��������.
		//�������� - ��� ���������, ��� ������ �������� ����� �������� ������ � ��������� ��������� ������.
		while (Temp)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext;	//������� �� ��������� �������.
		}*/
		//for(start;stop; step)
		for (Element* Temp = Head; Temp; Temp = Temp->pNext)cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		cout << "���������� ��������� ������: " << size << endl;
		cout << "����� ���������� ���������:  " << Element::count << endl;
	}
	ForwardList& operator=(const ForwardList& other)
	{
		//��������� �� �������� �� this � other ����� ��������.
		if (this == &other)return *this;
		while (Head)pop_front();
		/*Element* Temp = other.Head;
		while (Temp)
		{
			push_back(Temp->Data);
			Temp = Temp->pNext;

		}*/
		for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)push_back(Temp->Data);
		cout << "LCopyAssignment:\t" << this << endl;
		return *this;
	}
	int& operator[](size_t index)
	{
		if (index >= size)throw std::exception("Error: Out of range");
		Element* Temp = Head;
		for (int i = 0; i < index; i++)Temp = Temp->pNext;
		return Temp->Data;
		/*int i = 0;
		while (Temp)
		{
			if (i == index) { return Temp->Data; }
			i++;
			Temp = Temp->pNext;
		}*/
	}
	//Element& operator=(int s) { this->set_Data(s); }
};

//#define BASE_CHECK	//Almost DONE
//#define SIZE_CONSTRUCTOR_AND_SUBSCRIPT
#define COPY_METHODS
//#define HARDCORE

void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef BASE_CHECK
	int n; cout << "������� ������ ������: "; cin >> n;
	ForwardList list;
	for (int i = 0; i < n; i++)
	{
		//list.push_front(rand() % 100);
		list.push_back(rand() % 100);
	}
	list.push_back(123);
	list.print();
	list.pop_front();
	list.pop_back();
	list.print();

	int index;
	int value;
	cout << "������� ������ ������������ ��������: "; cin >> index;
	cout << "������� �������� ������������ ��������: "; cin >> value;
	list.insert(index, value);
	list.print();
	cout << "������� ������ ���������� ��������: "; cin >> index;
	list.erase(index);
	list.print();

	ForwardList list2;
	list2.push_back(1024);
	list2.push_back(2048);
	list2.push_back(3072);
	list2.print();
#endif // BASE_CHECK

#ifdef SIZE_CONSTRUCTOR_AND_SUBSCRIPT
	int n; cout << "������� ������ ������: "; cin >> n;
	ForwardList list(n);	//��������� ������ �� n ���������
	for (int i = 0; i < list.get_size(); i++)cout << list[i] << tab;
	//for (int i = 0; i < list.get_size(); i++)list[i] = rand() % 100;
	//for (int i = 0; i < list.get_size(); i++)cout << list[i] << tab;
#endif // SIZE_CONSTRUCTOR_AND_SUBSCRIPT

#ifdef COPY_METHODS
	ForwardList list;
	list.push_back(3);
	list.push_back(5);
	list.push_back(8);
	list.push_back(13);
	list.push_back(21);
	list.print();

	ForwardList list2 = list;
	list2.print();

	ForwardList list3;
	list3 = list2;
	list3.print();
#endif // COPY_METHODS

#ifdef HARDCORE
	ForwardList list = { 3, 5, 8, 13, 21 };
	for (int i : list)
		cout << i << tab;
	cout << endl;
#endif // INIT_LIST_LIKE_ARRAY

#ifdef SIZE_CONSTRUCTOR_AND_SUBSCRIPT

	int n; cout << "������� ������ ������: "; cin >> n;
	ForwardList list(n);
	//for (int i = 0; i < n; i++)
	//{
	//	//list.push_front(rand() % 100);
	//	list.push_back(rand() % 100);
	//}
	//list.print();
	try
	{
		for (int i = 0; i < n; i++)list[i] = rand() % 100;
		for (int i = 0; i < n; i++)cout << list[i] << tab;
		cout << endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}
#endif // SIZE_CONSTRUCTOR_AND_SUBSCRIPT

}