#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

//1. Написать метод void erase();
//2. Проверочный код в секциях
//   HARDCORE;	//Для этого нужен итератор 
//   COPY_CONSTRUCTOR_CHECK;
//	 COPY_ASSIGNMENT_CHECK;
//	 должен заработать;
//3. Написать класс ReverseIterstor, который позволит перемещаться по списку в обратном направлении
//	 (от Хвоста до Головы);


#define tab "\t"
#define delimiter    "\n=================================================================================\n"

class List
{
	class Element
	{
		int Data;
		Element* pNext;
		Element* pPrev;
	public:
		Element(int Data, Element* pNext = nullptr, Element* pPrev = nullptr) :
			Data(Data), pNext(pNext), pPrev(pPrev)
		{
#ifdef DEBUG
			cout << "EConstrucor: \t" << this << endl;
#endif // DEBUG

		}
		~Element()
		{
#ifdef DEBUG
			cout << "EDestrucor: \t" << this << endl;
#endif // DEBUG

		}
		friend class List;
		friend class Iterator;
		friend class ReverseIterator;
	}*Head, *Tail;	
	size_t size;
public:
	class Iterator
	{
		Element* Temp;
	public:
		Iterator(Element* Temp = nullptr) :Temp(Temp)
		{
#ifdef DEBUG
			cout << "ItConstructor:\t" << this << endl;
#endif // DEBUG

		}
		~Iterator()
		{
#ifdef DEBUG
			cout << "ItDestructor:\t" << this << endl;
#endif // DEBUG

		}
		Iterator& operator ++()
		{
			Temp = Temp->pNext;
			return *this;
		}
		Iterator operator ++(int)
		{
			Iterator old = *this;
			Temp = Temp->pNext;
			return old;
		}
		Iterator& operator --()
		{
			Temp = Temp->pPrev;
			return *this;
		}
		Iterator operator --(int)
		{
			Iterator old = *this;
			Temp = Temp->pPrev;
			return old;
		}
		bool operator==(const Iterator& other)const
		{
			return this->Temp == other.Temp;
		}
		bool operator!=(const Iterator& other)const
		{
			return this->Temp != other.Temp;
		}

		const int& operator*()const
		{
			return Temp->Data;
		}
		int& operator*()
		{
			return Temp->Data;
		}
	};
	class ReverseIterator
	{
		Element* Temp;
	public:
		ReverseIterator(Element* Temp = nullptr) :Temp(Temp)
		{
#ifdef DEBUG
			cout << "RItConstructor:\t" << this << endl;
#endif // DEBUG

		}
		~ReverseIterator()
		{
#ifdef DEBUG
			cout << "RItDestructor:\t" << this << endl;
#endif // DEBUG

		}
		ReverseIterator& operator++()
		{
			Temp = Temp->pPrev;
			return *this;
		}
		ReverseIterator operator++(int)
		{
			ReverseIterator old = *this;
			Temp = Temp->pPrev;
			return old;
		}
		ReverseIterator& operator--()
		{
			Temp = Temp->pNext;
			return *this;
		}
		ReverseIterator operator--(int)
		{
			ReverseIterator old = *this;
			Temp = Temp->pNext;
			return old;
		}

		bool operator==(const ReverseIterator& other)const
		{
			return this->Temp == other.Temp;
		}
		bool operator!=(const ReverseIterator& other)const
		{
			return this->Temp != other.Temp;
		}
		
		const int& operator*()const
		{
			return Temp->Data;
		}
		int& operator*()
		{
			return Temp->Data;
		}
	};
	size_t get_size() { return size; }
	Iterator begin() { return Head; }
	Iterator end() { return nullptr; }
	ReverseIterator rbegin(){ return Tail; }
	ReverseIterator rend() { return nullptr; }


	List()
	{
		Head = Tail = nullptr;
		size = 0;
		cout << "LConstructor:\t" << this << endl;
	}
	explicit List(size_t size, int value = int()):List()
	{
		while (size--)push_back(value);
		cout << "LConstructor:\t" << this << endl;
	}
	List(const std::initializer_list<int>&il):List()
	{
		cout << typeid(il.begin()).name() << endl;
		for (int const* it = il.begin(); it != il.end(); it++)
			push_back(*it);
	}
	~List()
	{
		//while (Head)pop_front();
		while (Tail)pop_back();
		cout << "LDestructor:\t" << this << endl;
	}

	                 // Operators
	int& operator[](size_t index)
	{
		if (index >= size)throw std::exception("Error: out of range");
		Element* Temp;
		if (index < size / 2)
		{
			Temp = Head;
			for (int i = 0; i < index; i++)Temp = Temp->pNext;
		}
		else
		{
			Temp = Tail;
			for (int i = 0; i < size - index - 1; i++)Temp = Temp->pPrev;
		}
		return Temp->Data;
	}

	                // Edd elements

	void push_front(int Data)
	{
		if (Head == nullptr && Tail == nullptr)
		{
			Head = Tail = new Element(Data);
			size++;
			return;
		}
		Element* New = new Element(Data);
		New->pNext = Head;
		Head->pPrev = New;
		Head = New;
		size++;
	}
	void push_back(int Data)
	{
		if(Head == nullptr && Tail == nullptr)
		{
			Head = Tail = new Element(Data);
			size++;
			return;
		}
		Element* New = new Element(Data);
		New->pPrev = Tail;
		Tail->pNext = New;
		Tail = New;
		size++;

	}
	void insert(size_t index, int Data)
	{
		if (index > size)return;
		if (index == 0)return push_front(Data);
		if (index == size)return push_back(Data);
		Element* Temp;
		if (index < size / 2)
		{
			Temp = Head;
			for (size_t i = 0; i < index; i++)Temp = Temp->pNext;
		}
		else
		{
			Temp = Tail;
			for (size_t i = 0; i < index; i++)Temp = Temp->pPrev;
		}
		Element* New = new Element(Data);
		New->pPrev = Temp->pPrev;
		New->pNext = Temp;
		Temp->pPrev->pNext = New;
		Temp->pPrev = New;
		size++;
	}

	                //Removing elements:
	
	void pop_front()
	{
		if (Head == Tail)
		{
			delete Head;
			Head = Tail = nullptr;
			size--;
			return;
		}
		Head = Head->pNext;
		delete Head->pPrev;
		Head->pPrev = nullptr;
		size--;
	}
	void pop_back()
	{
		if (Head == Tail)
		{
			delete Tail;
			Tail = Head = nullptr;
			size--;
			return;
		}
		Tail = Tail->pPrev;
		delete Tail->pNext;
		Tail->pNext = nullptr;
		size--;
	}
	void erase(size_t index)
	{
		
		if (index == 0)return pop_front();
		if (index == size)return;
		Element* Temp;
		if (index < size / 2)
		{
			Temp = Head;
			for (size_t i = 0; i < index; i++)Temp = Temp->pNext;
		}
		else
		{
			Temp = Tail;
			for (size_t i = 0; i < index; i++)Temp = Temp->pPrev;
		}
		Element* Eraser;
		Eraser = Temp;
		Temp->pPrev->pNext = Temp->pNext;
		Temp->pNext->pPrev = Temp->pPrev;
		delete Eraser;
		size--;
	}

	                        // Methods:

	void print()
	{
		cout << "Head: " << Head << endl;
		for (Element* Temp = Head; Temp; Temp = Temp->pNext)
		{
			cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		}
			cout << "Количество элементов списка: " <<size<< endl;
	}
	void reverse_print()
	{
		cout << "Tail: " << Tail << endl;
		for (Element* Temp = Tail; Temp; Temp = Temp->pPrev)
		{
			cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		}
			cout << "Количество элементов списка: " << size << endl;
	}
};



//#define BASE_CHECK
//#define SIZE_COSTRUCTOR_AND_SUBSCRIPT
#define HARDCORE
//#define ITERATORS_CHECK
//#define COPY_CONSTRUCTOR_CHECK
//#define COPY_ASSIGNMENT_CHECK
void main()
{
	setlocale(LC_ALL, "Russian");

#ifdef BASE_CHECK
	int n; cout << "Введите размер списка: "; cin >> n;
	List list;
	for (int i = 0; i < n; i++)
	{
		//list.push_front(rand() % 100);
		list.push_back(rand() % 100);
	}

	list.print();
	list.reverse_print();
	list.push_front(777);
	list.print();
	list.pop_front();
	list.print();
	list.pop_back();
	list.print();
	cout << delimiter;
	size_t index;
	int value;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите значение добавляемого элемента: "; cin >> value;
	list.insert(index, value);
	list.print();
	cout << delimiter;
	cout << "Введите индекс удаляемого элемента: "; cin >> index;
	list.erase(index);
	list.print();
	//list.reverse_print();
#endif // BASE_CHECK

#ifdef SIZE_COSTRUCTOR_AND_SUBSCRIPT
	int n; cout << "Введите размер списка: "; cin >> n;
	List list(n);
	for (int i = 0; i < list.get_size(); i++)
		list[i] = rand() % 100;
	for (int i = 0; i < list.get_size(); i++)
		cout << list[i] << tab;
	cout << endl;
	for (int i = list.get_size() - 1; i >= 0; i--)
		cout << list[i] << tab;
	cout << endl;
#endif // SIZE_COSTRUCTOR_AND_SUBSCRIPT

#ifdef HARDCORE
	List list = { 3, 5, 8, 13, 21 };
	for (int i : list)
		cout << i << tab;
	cout << endl;
	/*for (List::Iterator it = list.begin(); it != list.end(); it++)cout << *it << tab;	
	cout << endl;*/
	/*for (List::Iterator it = list.end(); it != list.begin(); it--)
		cout << *it << tab;
	cout << endl;*/
	for(List::ReverseIterator rit=list.rbegin();rit!=list.rend();rit++)
		cout << *rit << tab;
	cout << endl;


#endif // HARDCORE

#ifdef ITERATORS_CHECK
	List list = { 3, 5, 8, 13, 21 };
	list.print();
#endif // ITERATORS_CHECK


#ifdef COPY_CONSTRUCTOR_CHECK
	List list = { 3, 5, 8, 13, 21 };
	list.print();
	list.reverse_print();
	cout << delimiter;
	List list2 = list;
	list2.print();
	cout << delimiter;
	list2.reverse_print();
#endif // COPY_CONSTRUCTOR_CHECK

#ifdef COPY_ASSIGNMENT_CHECK
	List list = { 3, 5, 8, 13, 21 };
	list = list;
	list.print();
	list.reverse_print();
	List list2;
	list2 = list;
	list2.print();
	list2.reverse_print();
#endif // COPY_ASSIGNMENT_CHECK

}