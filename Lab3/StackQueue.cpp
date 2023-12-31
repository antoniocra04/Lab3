#include <iostream>
#include "StackQueue.h"
#include "StackItem.h"
#include "ValidInput.h"

using namespace std;

StackQueue::StackQueue()
{
	_firstStack = new Stack;
	_secondStack = new Stack;
}

void StackQueue::MoveToSecondStack()
{
	while (_firstStack->GetLastItem() != NULL)
	{
		_secondStack->Push(_firstStack->GetLastItem());
		_firstStack->Pop();
	}
}

StackQueue& StackQueue::Enqueue(const int& value)
{
	_firstStack->Push(value);
	return *this;
}

StackQueue& StackQueue::Dequeue()
{
	if (_secondStack->GetLastItem() == NULL)
	{
		MoveToSecondStack();
		_secondStack->Pop();
	}
	else
	{
		_secondStack->Pop();
	}

	return *this;
}

StackQueue& StackQueue::Clean()
{
    _firstStack->Clean();
    _secondStack->Clean();
    return *this;
}

StackQueue::~StackQueue()
{
    Clean();
}
