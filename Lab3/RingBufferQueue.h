#pragma once
#include <ostream>
#include "RingBuffer.h"

using std::ostream;

class RingBufferQueue
{
private:
	RingBuffer* _buffer;

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
	/// <returns>Очередь</returns>
	RingBufferQueue& Dequeue();

	/// <summary>
	/// Очистить очередь
	/// </summary>
	/// <returns>Очередь</returns>
	RingBufferQueue& Clean();

	/// <summary>
	/// Контроллер меню
	/// </summary>
	/// <returns>символ q</returns>
	char MenuController();
	friend ostream& operator<<(ostream& os, RingBufferQueue& queue);
};