#pragma once
#include "Stack.h"

class StackQueue
{
public:
	Stack* _firstStack;
	Stack* _secondStack;

	/// <summary>
	/// переместить во второй стек
	/// </summary>
	void MoveToSecondStack();

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
};