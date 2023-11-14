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
}

StackQueue::~StackQueue()
{
    Clean();
}

ostream& operator<<(ostream& os, StackQueue& queue)
{
	os << "First stack:";
	os << *(queue._firstStack) << endl;
	os << "Second stack:";
	os << *(queue._secondStack);

	return os;
}

char StackQueue::MenuController()
{
    const char* menu = "Choose one of activity:\n. - Choose another structure\n1 - Enqueue\n2 - Dequeue\nq - quit\nYour choice: ";
    char mode = '\0';
    bool wrongInput = false;

    while (true)
    {
        int value;
        bool bValueInput;
        cout << "First stack:";
        cout << *(_firstStack) << endl;
        cout << "Second stack:";
        cout << *(_secondStack) << endl;
        cout << menu;
        wrongInput = ValidInput(mode, wrongInput);
        system("cls");
        switch (mode)
        {
        case '.':
            return '.';
        case '1':
            cout << "Enter enqueue element: ";
            while (ValidInput(value))
            {
                cout << "Enter correct integer: ";
            }
            Enqueue(value);
            break;
        case '2':
            Dequeue();
            break;
        case 'q':
            return 'q';
        default:
            wrongInput = true;
            break;
        }
    }
    return mode;
}