#include <iostream>
#include "RingBufferQueue.h"
#include "RingBuffer.h"
#include "ValidInput.h"
using namespace std;

RingBufferQueue::RingBufferQueue()
{
	RingBuffer* buffer = new RingBuffer;
	_buffer = buffer;
}

RingBufferQueue& RingBufferQueue::Enqueue(const int& value)
{
	if (_buffer->GetFreeSpace() == 0)
	{
		_buffer->Resize(1);
	}

	_buffer->Push(value);
	return *this;
}

RingBufferQueue& RingBufferQueue::Dequeue()
{
	if (_buffer->GetOccupedSpace() > 4)
	{
		_buffer->Resize(-1);
	}

	_buffer->Pop();
	return *this;
}

RingBufferQueue& RingBufferQueue::Clean()
{
    while (_buffer->GetOccupedSpace())
    {
        _buffer->Pop();
    }
}

ostream& operator<<(ostream& os, RingBufferQueue& queue)
{
	os << *(queue._buffer);
	return os;
}

RingBufferQueue::~RingBufferQueue()
{
    Clean();
}

char RingBufferQueue::MenuController()
{
    const char* menu = "Choose one of activity:\n. - Choose another structure\n1 - Enqueue\n2 - Dequeue\nq - quit\nYour choice: ";
    char mode = '\0';
    bool wrongInput = false;

    while (true)
    {
        int value;
        cout << *(_buffer);
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
            if (_buffer->GetOccupedSpace())
            {
                cout << "Dequeue element: " << Dequeue() << endl;
            }
            else
            {
                cout << "No element in queue\n";
            }
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