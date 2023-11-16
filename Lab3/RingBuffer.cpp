#include <iostream>
#include "RingBuffer.h"
#include "RingBufferItem.h"
#include "ValidInput.h"
using namespace std;

RingBuffer::RingBuffer(const int& size)
{
	_sizeBuffer = size;
	_data = new int* [_sizeBuffer];
	_head = -1;
	_tail = 0;
	for (int i = 0; i < _sizeBuffer; i++)
	{
		_data[i] = nullptr;
	}
}

int RingBuffer::GetFreeSpace()
{
	if (_head == -1)
	{
		return _sizeBuffer;
	}
	return _tail > _head ? _sizeBuffer - _tail + _head : _head - _tail;
}

int RingBuffer::GetOccupedSpace()
{
	return _sizeBuffer - GetFreeSpace();
}

RingBuffer& RingBuffer::Push(const int& value)
{
	if (_head == _tail)
	{
		_head++;
		_head %= _sizeBuffer;
	}

	_data[_tail++] = new int(value);
	_tail %= _sizeBuffer;

	if (_head == -1)
	{
		_head = _tail - 1;
	}
	return *this;
}

int RingBuffer::Pop()
{
	int result;
	if (_head == -1)
	{
		cout << "empty buffer" << endl;
		return 0;
	}
	result = *_data[_head];
	delete _data[_head];
	_data[_head++] = nullptr;

	_head %= _sizeBuffer;
	if (_head == _tail)
	{
		_head = -1;
	}

	return result;
}

ostream& operator<<(ostream& os, RingBuffer& buffer)
{
	os << "Ring Buffer: [ ";
	for (int i = 0; i < buffer._sizeBuffer; i++)
	{
		if (buffer._data[i])
		{
			os << *buffer._data[i] << " ";
		}
		else
		{
			os << "* ";
		}
	}
	os << "]" << endl;

	return os;
}

RingBuffer& RingBuffer::Resize(const int& value)
{
	return *this;
}

RingBuffer::~RingBuffer()
{
	for (int i = 0; i < _sizeBuffer; i++)
	{
		if (_data[i])
		{
			delete _data[i];
		}
	}
	delete[] _data;
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