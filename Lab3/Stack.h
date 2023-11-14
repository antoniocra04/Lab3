#pragma once
#include "StackItem.h"
#include <ostream>

using std::ostream;

class Stack 
{
private:
	int _length;
	StackItem* _lastItem;

public:
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

	/// <summary>
	/// Контроллер меню
	/// </summary>
	/// <returns>возвращает q</returns>
	char MenuController();
	friend ostream& operator<<(ostream& os, Stack& stack);
};