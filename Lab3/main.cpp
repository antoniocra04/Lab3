#include <iostream>
#include "Stack.h"
#include "RingBuffer.h"
#include "RingBufferQueue.h"
#include "StackQueue.h"
#include "ValidInput.h"

using namespace std;

void PrintStack(Stack* stack)
{
    cout << "Current stack:";

    StackItem* current = stack->_lastItem;

    cout << endl;

    for (int i = 0; i < stack->_length; i++)
    {
        cout << "|" << current->_value << "|" << endl;
        current = current->_prev;
    }

    cout << "length: " << stack->_length << endl;
}

void PrintRingBuffer(RingBuffer* ringBuffer)
{
    cout << "Ring Buffer: [ ";
    for (int i = 0; i < ringBuffer->_sizeBuffer; i++)
    {
        if (ringBuffer->_data[i])
        {
            cout << *ringBuffer->_data[i] << " ";
        }
        else
        {
            cout << "* ";
        }
    }
    cout << "]" << endl;
}

void PrintRingBufferQueue(RingBufferQueue* queue)
{
    PrintRingBuffer(queue->_ringBuffer);
}

void PrintStackQueue(StackQueue* queue)
{
    cout << "First stack:";
    PrintStack(queue->_firstStack);
    cout << "Second stack:";
    PrintStack(queue->_secondStack);
}

void ControllerQueueRing()
{
    const char* menu = "Choose one of activity:\n1 - Enqueue\
        \n2 - Dequeue\nq - Choose another structure\nYour choice: ";
    char mode = '\0';
    RingBufferQueue* queueRing = new RingBufferQueue;

    while (mode != 'q')
    {
        int value;
        PrintRingBufferQueue(queueRing);
        cout << menu;
        mode = ValidInput<char>();
        system("cls");
        switch (mode)
        {
        case '1':
            cout << "Enter enqueue element: ";
            value = ValidInput<int>();
            queueRing->Enqueue(value);
            break;
        case '2':
            queueRing->Dequeue();
            break;
        default:
            break;
        }
    }
    delete queueRing;
}

void ControllerRingBuffer()
{
    const char* menu =
        "Choose one of activity:\n1 - Push\n2 - Pop\n3 - Show free space\
        \n4 - Show occupied space\nq - Choose another structure\nYour choice: ";

    char mode = '\0';
    RingBuffer* ringBuffer = new RingBuffer;

    while (mode != 'q')
    {
        PrintRingBuffer(ringBuffer);
        cout << menu;
        mode = ValidInput<char>();
        system("cls");
        int value;
        switch (mode)
        {
        case '1':
            cout << "Enter push element: ";
            value = ValidInput<int>();
            ringBuffer->Push(value);
            break;
        case '2':
            if (ringBuffer->GetOccupedSpace())
            {
                cout << "Pop element: " << ringBuffer->Pop() << endl;
            }
            else
            {
                cout << "No element in ring buffer\n";
            }
            break;
        case '3':
            cout << "Free space: " << ringBuffer->GetFreeSpace() << endl;
            break;
        case '4':
            cout << "Occupied space: " << ringBuffer->GetOccupedSpace() << endl;
            break;
        default:
            break;
        }
    }
    delete ringBuffer;
}

void ControllerStackQueue()
{
    const char* menu = "Choose one of activity:\n1 - Enqueue\n2 - Dequeue\
                \nq - Choose another structure\nYour choice: ";
    char mode = '\0';
    StackQueue* queueStack = new StackQueue;

    while (mode != 'q')
    {
        PrintStackQueue(queueStack);
        cout << menu;
        mode = ValidInput<char>();
        system("cls");
        int value;
        switch (mode)
        {
        case '1':
            cout << "Enter enqueue element: ";
            value = ValidInput<int>();
            queueStack->Enqueue(value);
            break;
        case '2':
            queueStack->Dequeue();
            break;
        default:
            break;
        }
    }
    delete queueStack;
}

void ControllerStack()
{
    const char* menu = "Choose one of activity:\n1 - Push\n2 - Pop\
        \nq - Choose another structure\nYour choice: ";
    char mode = '\0';
    Stack* stack = new Stack;

    while (mode != 'q')
    {
        PrintStack(stack);
        cout << menu;
        mode = ValidInput<char>();
        system("cls");
        int value;
        switch (mode)
        {
        case '1':
            cout << "Enter push element: ";
            value = ValidInput<int>();
            stack->Push(value);
            break;
        case '2':
            stack->Pop();
            break;
        default:
            break;
        }
    }
    delete stack;
}

void MainController()
{
    string menu = "Choose one of structure:\n1 - Stack\n2 - Ring buffer \
        \n3 - Queue (Ring) \n4 - Queue (Stack)\nq - Quit\nYour choice: ";
    char mode = '\0';

    while (mode != 'q')
    {
        cout << menu;
        mode = ValidInput<char>();
        system("cls");
        switch (mode)
        {
        case '1':
            ControllerStack();
            break;
        case '2':
            ControllerRingBuffer();
            break;
        case '3':
            ControllerQueueRing();
            break;
        case '4':
            ControllerStackQueue();
            break;
        default:
            break;
        }
    }
}

int main()
{
    MainController();
    return 0;
}