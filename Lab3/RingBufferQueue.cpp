#include "RingBufferQueue.h"
#include "RingBuffer.h"
#include "ValidInput.h"

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

RingBufferQueue::~RingBufferQueue()
{
    delete _ringBuffer;
}