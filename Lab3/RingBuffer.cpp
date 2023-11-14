#include <iostream>
#include "RingBuffer.h"
#include "RingBufferItem.h"
#include "ValidInput.h"
using namespace std;

RingBuffer::RingBuffer()
{
	_capacity = 4;
	_length = 0;
	_oldestItem = nullptr;
	_newestItem = nullptr;
}

int RingBuffer::GetFreeSpace()
{
	return _capacity - _length;
}

int RingBuffer::GetOccupedSpace()
{
	return _length;
}

RingBuffer& RingBuffer::Push(const int& value)
{
	RingBufferItem* newItem = new RingBufferItem;
	newItem->_value = value;

	if (_newestItem == nullptr) {
		newItem->_next = nullptr;
		newItem->_prev = nullptr;
		_length += 1;
	}
	else
	{
		if (_capacity != _length)
		{
			newItem->_next = _newestItem->_next;
			newItem->_prev = _newestItem;
			_newestItem->_next = newItem;
			_length += 1;
		}
		else
		{
			newItem->_next = _oldestItem->_next;
			newItem->_prev = _oldestItem->_prev;
			_newestItem->_next = newItem;
			delete _oldestItem;
			_oldestItem = newItem->_next;
			_newestItem = newItem;
		}

	}

	if (_length == 1)
	{
		_oldestItem = newItem;
	}

	_newestItem = newItem;
	return *this;
}

RingBuffer& RingBuffer::Pop()
{
	if (_length == 0)
	{
		return *this;
	}

	RingBufferItem* popItem = _oldestItem;
	if (popItem->_next != nullptr)
	{
		_oldestItem = popItem->_next;
	}
	_oldestItem->_prev = _newestItem;
	_newestItem->_next = _oldestItem;
	_length -= 1;

	return *this;
}

ostream& operator<<(ostream& os, RingBuffer& buffer)
{
	os << "Current list: [ ";

	RingBufferItem* current = buffer._oldestItem;

	for (int i = 0; i < buffer._length; i++)
	{
		os << current->_value << " ";
		current = current->_next;

	}

	for (int i = 0; i < buffer._capacity - buffer._length; i++)
	{
		os << "*" << " ";
	}

	os << "] length: " << buffer._length << endl;

	return os;
}

RingBuffer& RingBuffer::Resize(const int& value)
{
	_capacity = _capacity + value;
	return *this;
}

RingBuffer::~RingBuffer()
{
	for (int i = 0; i <= _length; i++)
	{
		Pop();
	}

}

char RingBuffer::MenuController()
{
	const char* menu =
		"Choose one of activity:\n. - Choose another structure\n1 - Push\n2 - Pop\n3 - Show free space\n4 - Show occupied space\nq - quit\nYour choice: ";

	char mode = '\0';
	bool bWrongInput = false;

	cout << *this;
	while (true)
	{
		int value;
		cout << menu;
		bWrongInput = ValidInput(mode, bWrongInput);
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
			if (GetOccupedSpace())
			{
				cout << "Pop element: " << this->Pop() << endl;
			}
			else
			{
				cout << "No element in ring buffer\n";
			}
			break;
		case '3':
			cout << "Free space: " << this->GetFreeSpace() << endl;
			break;
		case '4':
			cout << "Occupied space: " << this->GetOccupedSpace() << endl;
			break;
		case 'q':
			return 'q';
		default:
			bWrongInput = true;
			break;
		}
		cout << *this;
	}
	return '\0';
}