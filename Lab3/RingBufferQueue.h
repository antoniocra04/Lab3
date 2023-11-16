#pragma once
#include <ostream>
#include "RingBuffer.h"

using std::ostream;

class RingBufferQueue
{
private:
	RingBuffer* _ringBuffer;
	int _sizeBuffer;
	void ResizeBuffer(bool increase);

public:
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

	/// <summary>
	/// Контроллер меню
	/// </summary>
	/// <returns>символ q</returns>
	char MenuController();
	friend ostream& operator<<(ostream& os, RingBufferQueue& queue);
};