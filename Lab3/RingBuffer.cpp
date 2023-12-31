#include "RingBuffer.h"
#include "RingBufferItem.h"
#include "ValidInput.h"

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

