#include <iostream>
#include "RingBufferQueue.h"
#include "RingBuffer.h"
#include "ValidInput.h"
using namespace std;

RingBufferQueue::RingBufferQueue()
{
    _sizeBuffer = 4;
    _ringBuffer = new RingBuffer(_sizeBuffer);
}

RingBufferQueue& RingBufferQueue::Enqueue(const int& value)
{
    if (!_ringBuffer->GetFreeSpace())
    {
        ResizeBuffer(true);
    }
    _ringBuffer->Push(value);

    return *this;
}

int RingBufferQueue::Dequeue()
{
    int result = _ringBuffer->Pop();
    if (_ringBuffer->GetFreeSpace() <= _sizeBuffer / 2 && _ringBuffer->GetFreeSpace() >= 4)
    {
        ResizeBuffer(false);
    }
    return result;
}

void RingBufferQueue::ResizeBuffer(bool increase)
{
    _sizeBuffer = increase ? _sizeBuffer * 2 : _sizeBuffer / 2;
    RingBuffer* newBuffer = new RingBuffer(_sizeBuffer);

    int occupiedSpace = _ringBuffer->GetOccupedSpace();
    for (int i = 0; i < occupiedSpace; i++)
    {
        newBuffer->Push(_ringBuffer->Pop());
    }
    delete _ringBuffer;
    _ringBuffer = newBuffer;
}

ostream& operator<<(ostream& os, RingBufferQueue& queue)
{
	os << *(queue._ringBuffer);
	return os;
}

RingBufferQueue::~RingBufferQueue()
{
    delete _ringBuffer;
}

char RingBufferQueue::MenuController()
{
    const char* menu = "Choose one of activity:\n. - Choose another structure\n1 - Enqueue\n2 - Dequeue\nq - quit\nYour choice: ";
    char mode = '\0';
    bool wrongInput = false;

    while (true)
    {
        int value;
        cout << *(_ringBuffer);
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
            if (_ringBuffer->GetOccupedSpace())
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