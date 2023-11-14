#include <iostream>
#include "Stack.h"
#include "ValidInput.h"
using namespace std;

Stack::Stack()
{
	_length = 0;
	_lastItem = nullptr;
}

Stack& Stack::Push(const int& value)
{
	StackItem* newItem = new StackItem;
	newItem->_value = value;
	
	if (_lastItem != nullptr)
	{
		newItem->_prev = _lastItem;
	}
	else
	{
		newItem->_prev = nullptr;
	}

	_length += 1;
	_lastItem = newItem;

	return *this;
}

Stack& Stack::Pop()
{
	if (_length == 0)
	{
		cout << "length is 0"<<endl;

		return *this;
	}

	StackItem* popItem = _lastItem;
	_lastItem = popItem->_prev;

	delete popItem;
	_length -= 1;

	return *this;
}

Stack& Stack::Clean()
{
	StackItem* current = _lastItem;

	for (int i = 0; i < _length; i++)
	{
		current = current->_prev;
		delete _lastItem;
		_lastItem = current;
	}

	_length = 0;

	return *this;
}

Stack::~Stack()
{
	Clean();
}

int Stack::GetLastItem()
{
	if (_lastItem != nullptr)
	{
		return _lastItem->_value;
	}
	else
	{
		return NULL;
	}

}

ostream& operator<<(ostream& os, Stack& stack)
{
	os << "Current stack:";

	StackItem* current = stack._lastItem;

	os << endl;

	for (int i = 0; i < stack._length; i++)
	{
		os << "|" << current->_value << "|" << endl;
		current = current->_prev;
	}

	os << "length: " << stack._length << endl;

	return os;
}

char Stack::MenuController()
{
	const char* menu = "Choose one of activity:\n. - Choose another structure\n1 - Push\n2 - Pop\nq - quit\nYour choice: ";
	char mode = '\0';
	bool wrongInput = false;

	cout << *this;
	while (true)
	{
		int value;
		cout << menu;
		wrongInput = ValidInput(mode, wrongInput);
		system("cls");
		switch (mode)
		{
		case '.':
			return '.';
		case '1':
			cout << "Enter push element: ";
			while (ValidInput(value))
			{
				cout << "Enter correct integer: ";
			}
			this->Push(value);
			break;
		case '2':
			if (_length == 0)
			{
				cout << "No elements in stack!\n";
			}
			else
			{
				cout << "Pop element: " << this->Pop() << endl;
			}
			break;
		case 'q':
			return 'q';
		default:
			wrongInput = true;
			break;
		}
		cout << *this;
	}
	return '\0';
}