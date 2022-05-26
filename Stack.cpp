#include "Stack.h"
using namespace std;

Stack::Stack(int size)	// конструктор с параметром
{
	this->size = size;
	data = new int[size];

	for (int i = 0; i < size; i++)
		data[i] = rand() % 100;
}

Stack::Stack(const Stack &other)	// конструктор копирования
{
	this->size = other.size;
	this->data = new int[other.size];

	for (int i = 0; i < other.size; i++)
		this->data[i] = other.data[i];
}

Stack::~Stack()	// деструктор
{
	delete[] data;
}

void Stack::show()
{
	cout << fixed;	//Вывод чисел с плавающей точкой в фиксированной форме(по умолчанию)
	for (int i = 0; i < size; i++)	// проходим по массиву и выводим его содержание
	{
		cout << setprecision(4) << data[i] << " ";
	}
	cout << endl;
}

void Stack::operator=(const int value)	// оператор присваивания
{
	for (int i = 0; i < size; i++)
	{
		data[i] = value;
	}		
}

void Stack::operator==(const int value)	// оператор сравнения
{
	for (int i = 0; i < size; i++)
	{
		if(data[i] == value)
			cout << data[i] << "==" << value << endl;
		else if(data[i] < value)
			cout << data[i] << "<" << value << endl;
		else if (data[i] > value)
			cout << data[i] << ">" << value << endl;
	}
}

void Stack::operator-=(const int value)	
{
	for (int i = 0; i < size; i++)
	{
		data[i] -= value;
	}
}

void Stack::operator/=(const int value)
{
	for (int i = 0; i < size; i++)
	{
		data[i] /= value;
	}
}

void Stack::operator!()	// !
{
	for (int i = 0; i < size; i++)
	{
		data[i] *= (-1);
	}
}

void Stack::operator-(const int value)	// оператор вычитания
{
	for (int i = 0; i < size; i++)
	{
		data[i] -= value;
	}
}

void Stack::operator/(const int value)	// оператор деления
{
	for (int i = 0; i < size; i++)
	{
		data[i] /= value;
	}
}

ostream& operator<<(ostream& out, const Stack& object)	// вывод стека
{
	cout << fixed;
	for (int i = 0; i < object.size; i++)
	{
		out << setprecision(4) << object.data[i] << " ";
	}
	out << endl;

	return out;
}

istream& operator>>(istream& in, Stack& object)	// ввод в стек
{
	for (int i = 0; i < object.size; i++)
	{
		in >> setprecision(4) >> object.data[i];
	}
	return in;
}

/*Stack operator-(const Stack& object, const int value)	// оператор вычитания
{
	Stack stack(object);

	for (int i = 0; i < stack.size; i++)
	{
		stack.data[i] = object.data[i] - value;
	}

	return stack;
}*/

/*Stack operator/(const Stack& object, const int value)	// оператор деления
{
	Stack stack(object);

	for (int i = 0; i < stack.size; i++)
	{
		stack.data[i] = object.data[i] / value;
	}

	return stack;
}*/