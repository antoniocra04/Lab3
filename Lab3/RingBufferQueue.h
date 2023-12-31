#pragma once
#include <ostream>
#include "RingBuffer.h"

using std::ostream;

class RingBufferQueue
{
public:
	RingBuffer* _ringBuffer;
	int _sizeBuffer;

	/// <summary>
	/// Изменить размер буфера
	/// </summary>
	/// <param name="increase">0 - уменьшить в 2 раза, 1 - увеличить в 2 раза</param>
	void ResizeBuffer(bool increase);

	RingBufferQueue();
	~RingBufferQueue();

	/// <summary>
	/// Добавить элемент в очередь
	/// </summary>
	/// <param name="value">значение</param>
	/// <returns>Очередь</returns>
	RingBufferQueue& Enqueue(const int& value);

	/// <summary>
	/// Снять элемент с очереди
	/// </summary>
	/// <returns>Снятый элемент</returns>
	int Dequeue();
};