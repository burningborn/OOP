#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

/*
TODO:
В класс ForwardList добавить методы:
	void pop_front();
	void pop_back();
	void insert(...);	//Вставляет элемент по указанному индексу
	void erase(...);	//Удавляет элемент по указанному индексу
*/

#define tab "\t"

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
	friend class Iterator;
	Element& operator=(int Data) 
	{ 
		this->set_Data(Data); 
	}
};
int Element::count = 0;

class Iterator
{
	Element* Temp;
public:
	Iterator(Element* Temp = nullptr) :Temp(Temp)
	{
		cout << "IConstructor:\t" << this << endl;
	}
	~Iterator()
	{
		cout << "IDestructor:\t" << this << endl;
	}
	Iterator& operator++()
	{
		Temp = Temp->pNext;
		return *this;
	}
	bool operator == (const Iterator & other) const
	{
		return this->Temp == other.Temp;
	}
	bool operator != (const Iterator & other) const
	{
		return this->Temp != other.Temp;
	}
	int& operator*()
	{
		return Temp->Data;
	}
};

class ForwardList
{
	Element* Head;
	size_t size;
public:
	Iterator begin() { return Head; }
	Iterator end() { return nullptr; }

	Element& get_Head() { return *Head; }
	size_t get_size() { return size; }
	int set_size(int n)
	{
		this->size = n;
	}

	ForwardList()	//Default constructor - создает пустой список.
	{
		this->Head = nullptr;	//Если Голова указывает на 0, то список пуст.
		this->size = 0;
		cout << "LConstructor:\t" << this << endl;
	}
	explicit ForwardList(size_t size):ForwardList()
	{
		while (size--)push_front(0);
		cout << "LArgConstructor:\t" << this << endl;
	}
	ForwardList(const std::initializer_list<int>& il) :ForwardList()
	{
		cout << typeid(il.begin()).name() << endl;
		for (int const* it = il.begin(); it != il.end(); it++)
		{
			push_back(*it);
		}
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
		Head = new Element(Data, Head);
		size++;
	}
	void push_back(int Data)
	{
		if (Head == nullptr)
		{
			//ЕСЛИ список пуст, вызываем метод, который умеет добавлять элемент в пустой список.
			return push_front(Data);
			//return;
		}
		//1)Создать новый элемент:
		//Element* New = new Element(Data);

		//2)Дойти до конца списка (до последнего элемента):
		Element* Temp = Head;
		while (Temp->pNext)
			Temp = Temp->pNext;	//Переходим на следующий элемент
		//3)В pNext последнего элемента добавить адрес нового элемента:
		Temp->pNext = new Element(Data);
		size++;
	}
	void insert(int index, int Data)
	{
		if (index > size)return;
		if (index == 0)return push_front(Data);
		//1) Создаем новый элемент:
		Element* New = new Element(Data);
		//2) Доходим до элемента, который находится перед добавляемым элементом:
		Element* Temp = Head;
		for (int i = 0; i < index - 1; i++)
			Temp = Temp->pNext;
		//3) Вставляем новый элемент в список:
		//Temp - Предыдущий элемент, тоносительно того элемента, на место которого нужно сделать вставку.
		//Temp->pNext - элемент, на место которого мы вставляет новый элемент.
		//Temp->pNext и все последующие элементы будут сдвинуты на 1 позицию вправо.
		/*New->pNext = Temp->pNext;
		Temp->pNext = New;*/
		Temp->pNext = new Element(Data, Temp->pNext);
		size++;
	}

	//			Removing elements:
	void pop_front()
	{
		//1) Запоминаем адрес удаляемого элемента:
		Element* Temp = Head;
		//2) Смещаем Голову на следубщий элемент списка:
		Head = Head->pNext;
		//3) Удаляем элемент из памяти:
		delete Temp;
		size--;
	}
	void pop_back()
	{
		//1) Доходим до предпоследнего элемента:
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
		for (Element* Temp = Head; Temp; Temp = Temp->pNext)cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		cout << "Количество элементов списка: " << size << endl;
		cout << "Общее количество элементов:  " << Element::count << endl;
	}
	ForwardList& operator=(const ForwardList& other)
	{
		//Проверяем не является ли this и other одним объектом.
		if (this == &other)return *this;
		while (Head)pop_front();
		
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
//#define COPY_METHODS
#define HARDCORE

void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef BASE_CHECK
	int n; cout << "Введите размер списка: "; cin >> n;
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
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите значение добавляемого элемента: "; cin >> value;
	list.insert(index, value);
	list.print();
	cout << "Введите индекс удаляемого элемента: "; cin >> index;
	list.erase(index);
	list.print();

	ForwardList list2;
	list2.push_back(1024);
	list2.push_back(2048);
	list2.push_back(3072);
	list2.print();
#endif // BASE_CHECK

#ifdef SIZE_CONSTRUCTOR_AND_SUBSCRIPT
	int n; cout << "Введите размер списка: "; cin >> n;
	ForwardList list(n);	//Создается список на n элементов
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

#ifdef SIZE_CONSTRUCTOR_AND_SUBSCRIPT

	int n; cout << "Введите размер списка: "; cin >> n;
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

#ifdef HARDCORE

	/*int arr[] = { 1024,2048,4096,8192 };
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
		cout << arr[i] << tab;
	cout << endl;
	for (int i : arr)
		cout << i << tab;
	cout << endl;*/

	ForwardList list = { 3, 5, 8, 13, 21 };
	list.print();
	//for (Iterator it = list.begin(); it != list.end(); ++it)cout << *it << tab;
	cout << endl;
	for (int i : list)
		cout << i << tab;
	cout << endl;
#endif // INIT_LIST_LIKE_ARRAY


}