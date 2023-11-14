#pragma once
#include "RingBufferItem.h"
#include <ostream>

using std::ostream;

class RingBuffer
{
private:
	int _length;
	int _capacity;
	RingBufferItem* _newestItem;
	RingBufferItem* _oldestItem;

public:
	RingBuffer();
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
	/// <returns>Кольцевой буфер</returns>
	RingBuffer& Pop();

	/// <summary>
	/// Изменить размер буфера
	/// </summary>
	/// <param name="value">значение</param>
	/// <returns>Кольцевой буфер</returns>
	RingBuffer& Resize(const int& value);

	/// <summary>
	/// Контроллер меню
	/// </summary>
	/// <returns>символ q</returns>
	char MenuController();
	friend ostream& operator<<(ostream& os, RingBuffer& buffer);
};