#pragma once
#include "RingBufferItem.h"
#include <ostream>

using std::ostream;

class RingBuffer
{
public:
	int** _data;
	int _sizeBuffer;
	int _head;
	int _tail;

	RingBuffer(const int& size = 4);
	~RingBuffer();

	/// <summary>
	/// Получить свободное место
	/// </summary>
	/// <returns>число свободных ячеек</returns>
	int GetFreeSpace();

	/// <summary>
	/// Получить занятое место
	/// </summary>
	/// <returns>число занятых ячеек</returns>
	int GetOccupedSpace();

	/// <summary>
	/// Добавить элемент
	/// </summary>
	/// <param name="value">значение</param>
	/// <returns>Кольцевой буфер</returns>
	RingBuffer& Push(const int& value);

	/// <summary>
	/// Удалить элемент
	/// </summary>
	/// <returns>Снятый элемент</returns>
	int Pop();

	/// <summary>
	/// Изменить размер буфера
	/// </summary>
	/// <param name="value">значение</param>
	/// <returns>Кольцевой буфер</returns>
	RingBuffer& Resize(const int& value);

};