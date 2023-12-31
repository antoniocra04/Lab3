#pragma once
#include "StackItem.h"
#include <ostream>

using std::ostream;

class Stack 
{
public:
	int _length;
	StackItem* _lastItem;

	Stack();
	~Stack();

	/// <summary>
	/// Добавить элемент в стек
	/// </summary>
	/// <param name="value">значение</param>
	/// <returns>Стек</returns>
	Stack& Push(const int& value);

	/// <summary>
	/// Удалить элемент из стека
	/// </summary>
	/// <returns>Стек</returns>
	Stack& Pop();

	/// <summary>
	/// Очистить стек
	/// </summary>
	/// <returns>Стек</returns>
	Stack& Clean();

	/// <summary>
	/// Получить последний элемент стека
	/// </summary>
	/// <returns>значение элемента</returns>
	int GetLastItem();
};