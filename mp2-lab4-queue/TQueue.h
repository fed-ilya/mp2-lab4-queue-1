#pragma once
#include <iostream>
#include <string>

/* ................... TQueueException ................... */

class TQueueException
{
private:
	std::string desc;

public:
	TQueueException(std::string _desc)
	{
		desc = _desc;
	}
	TQueueException(const TQueueException& e)
	{
		desc = e.desc;
	}

	friend std::ostream& operator<<(std::ostream& os, const TQueueException& e)
	{
		os << "Exception message: " << e.desc << '\n';
		return os;
	}
};


/* ....................... TQueue ........................ */

template <class T>
class TQueue
{
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

	bool operator==(const TQueue<T>& other) const;
	bool operator!=(const TQueue<T>& other) const;

	bool IsEmpty();
	bool IsNotEmpty();

	bool IsFull();
	bool IsNotFull();

	void Push(T element);
	T Pop();

	void Clear();

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
		throw TQueueException("Queue MaxSize cannot be < 2");
	}

	MaxSize = _MaxSize;
	arr = new T[MaxSize];

	Count = 0;
	tail = -1, head = 0;
}

template <class T>
TQueue<T>::TQueue(const TQueue<T>& other)
{
	MaxSize = other.MaxSize;
	arr = new T[MaxSize];

	Count = other.Count;
	tail = other.tail, head = other.head;

	//Копируется только активная часть
	for (int tCount = Count, i = head; tCount > 0; tCount--)
	{
		arr[i] = other.arr[i];
		i = (++i) % MaxSize;
	}
}

template <class T>
TQueue<T>::~TQueue()
{
	delete[] arr;
}

template <class T>
TQueue<T>& TQueue<T>::operator=(const TQueue<T>& other)
{
	if (this == &other)
		return *this;

	if (MaxSize != other.MaxSize) {
		MaxSize = other.MaxSize;
		delete[] arr;
		arr = new T[MaxSize];
	}
	Count = other.Count;
	tail = other.tail, head = other.head;

	//Копируется только активная часть
	for (int tCount = Count, i = head; tCount > 0; tCount--)
	{
		arr[i] = other.arr[i];
		i = (++i) % MaxSize;
	}

	return *this;
}

template <class T>
bool TQueue<T>::operator==(const TQueue<T>& other) const
{
	if (MaxSize != other.MaxSize) return false;
	if (Count != other.Count) return false;
	if (head != other.head) return false;
	if (tail != other.tail) return false;

	for (int tCount = Count, i = head; tCount > 0; tCount--)
	{
		if (arr[i] != other.arr[i]) return false;
		i = (++i) % MaxSize;
	}

	return true;
}

template <class T>
bool TQueue<T>::operator!=(const TQueue<T>& other) const
{
	return !operator==(other);
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
		throw TQueueException("Can't push to a full queue");

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
		throw TQueueException("Can't pop from an empty queue");

	T temp = arr[head];
	head = (++head) % MaxSize;

	Count--;
	return temp;
}

template <class T>
void TQueue<T>::Clear()
{
	Count = 0;
	tail = -1, head = 0;
}