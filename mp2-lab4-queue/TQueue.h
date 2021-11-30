#pragma once
#include "Exception.h"

template <class T>
class TQueue {
private:
	T* arr;
	//Максимальное число элементов
	int MaxSize;
	//Реальное число элементов
	int Count;
	int head, tail;

public:
	TQueue(int _MaxSize = 100);
	TQueue(const TQueue<T>& other);
	~TQueue();
	TQueue<T>& operator=(const TQueue<T>& other);

	bool IsEmpty();
	bool IsNotEmpty();

	bool IsFull();
	bool IsNotFull();

	void Push(T element);
	T Pop();

	friend std::ostream& operator<<(std::ostream& out, const TQueue& q)
	{
		out << "[ ";

		for (int tCount = q.Count, i = q.head; tCount > 0; tCount--)
		{
			out << q.arr[i] << ' ';
			i = (++i) % q.MaxSize;
		}

		out << "]";

		return out;
	}
};


template <class T>
TQueue<T>::TQueue(int _MaxSize)
{
	//Нельзя создать очередь с размером < 2
	if (_MaxSize <= 1) {
		throw Exception(__FILE__, __FUNCTION__,
				__LINE__, "Queue MaxSize cannot be < 2");
	}

	MaxSize = _MaxSize;
	Count = 0;
	arr = new T[MaxSize];
	tail = -1, head = 0;
}

template <class T>
TQueue<T>::TQueue(const TQueue<T>& other)
{
	MaxSize = other.MaxSize;
	Count = other.Count;
	arr = new T[MaxSize];
	tail = other.tail, head = other.head;
	
	//TODO улучшить (копировать только активную часть)
	for (int i = 0; i < MaxSize; i++)
		arr[i] = other.arr[i];
}

template <class T>
TQueue<T>::~TQueue()
{
	delete[] arr;
}

template <class T>
TQueue<T>& TQueue<T>::operator=(const TQueue<T>& other) {
	if (this == &other)
		return *this;

	if (MaxSize != other.MaxSize) {
		MaxSize = other.MaxSize;
		delete[] arr;
		arr = new T[MaxSize];
	}
	Count = other.Count;
	tail = other.tail, head = other.head;

	//TODO улучшить (копировать только активную часть)
	for (int i = 0; i < MaxSize; i++)
		arr[i] = other.arr[i];
	return *this;
}

template <class T>
bool TQueue<T>::IsEmpty()
{
	return (Count == 0);
}

template <class T>
bool TQueue<T>::IsNotEmpty()
{
	return (Count > 0);
}

template <class T>
bool TQueue<T>::IsFull()
{
	return (Count == MaxSize);
}

template <class T>
bool TQueue<T>::IsNotFull()
{
	return (Count < MaxSize);
}

template <class T>
void TQueue<T>::Push(T element)
{
	if (IsFull())
		throw Exception(__FILE__, __FUNCTION__,
			__LINE__, "Can't push to the full queue");

	/*
	По сути эквивалентно:
	tail++;
	if (tail == MaxSize) {
		tail = 0;
	}*/
	tail = (++tail) % MaxSize;

	arr[tail] = element;

	Count++;
}

template <class T>
T TQueue<T>::Pop()
{
	if (IsEmpty())
		throw Exception(__FILE__, __FUNCTION__,
			__LINE__, "Can't pop from an empty queue");

	T temp = arr[head];
	head = (++head) % MaxSize;

	Count--;
	return temp;
}