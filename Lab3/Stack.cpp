#include "Stack.h"
#include "ValidInput.h"

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