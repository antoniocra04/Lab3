#pragma once
#include "Stack.h"

class StackQueue
{
private:
	Stack* _firstStack;
	Stack* _secondStack;

	void MoveToSecondStack();

public:
	StackQueue();
	~StackQueue();

	/// <summary>
	/// Добавить элемент в очередь
	/// </summary>
	/// <param name="value">значение</param>
	/// <returns>Очередь</returns>
	StackQueue& Enqueue(const int& value);

	/// <summary>
	/// Снять элемент с очереди
	/// </summary>
	/// <returns>Очередь</returns>
	StackQueue& Dequeue();

	/// <summary>
	/// Очистить очередь
	/// </summary>
	/// <returns>Очередь</returns>
	StackQueue& Clean();

	/// <summary>
	/// Контроллер меню
	/// </summary>
	/// <returns>символ q</returns>
	char MenuController();
	friend ostream& operator<<(ostream& os, StackQueue& queue);
};