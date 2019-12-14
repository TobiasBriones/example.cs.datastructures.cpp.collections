/**
 * Copyright (c) 2019 Tobias Briones.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once
#include "List.h"

template <typename T>
class ArrayList : public List<T>
{

private:
	static const int DEFAULT_CAPACITY;
	static const float FACTOR;
	int capacity;
	int size;
	T* array;

	void init(int);
	void checkRange();
	void shiftLeft(int);
	void shiftRigth(int);

protected:
	bool isInBounds(int) const;

public:
	ArrayList();
	ArrayList(ArrayList<T>*);
	ArrayList(int);
	~ArrayList();

	string toString() const;
	int getSize() const;
	bool isEmpty() const;
	void add(T);
	void clear();

	T get(int) const;
	T getFirst() const;
	T getLast() const;
	void add(int, T);
	void set(int, T);
	void remove(int);
	void removeFirst();
	void removeLast();

};

template<typename T> const int ArrayList<T>::DEFAULT_CAPACITY = 10;
template<typename T> const float ArrayList<T>::FACTOR = 1.5;

template<typename T>
ArrayList<T>::ArrayList()
{
	init(DEFAULT_CAPACITY);
}

template<typename T>
ArrayList<T>::ArrayList(ArrayList<T>* const list)
{
	init(list->size);
}

template<typename T>
ArrayList<T>::ArrayList(int initialCapacity) {
	if (initialCapacity <= 0)
	{
		string msg = "List capacity must be positive";
		throw std::runtime_error(msg);
	}
	init(initialCapacity);
}

template<typename T>
ArrayList<T>::~ArrayList()
{
	delete[] array;
	array = 0;
}

// --------------------------------------------- PRIVATE METHODS --------------------------------------------- //
template<typename T>
void ArrayList<T>::init(int capacity)
{
	this->capacity = capacity;
	this->size = 0;
	this->array = new T[capacity];
}

template<typename T>
void ArrayList<T>::checkRange() {
	if (size == capacity)
	{
		capacity *= FACTOR;
		T* newArray = new T[capacity];

		for (int i = 0; i < size; i++)
		{
			newArray[i] = array[i];
		}
		delete[] array;
		array = newArray;
	}
}

template<typename T>
void ArrayList<T>::shiftLeft(int position)
{
	size--;
	for (int i = position; i < size; i++)
	{
		array[i] = array[i + 1];
	}
}

template<typename T>
void ArrayList<T>::shiftRigth(int position)
{
	checkRange();
	for (int i = size; i > position; i--)
	{
		array[i] = array[i - 1];
	}
	size++;
}

// --------------------------------------------- PROTECTED METHODS --------------------------------------------- //
template<typename T>
bool ArrayList<T>::isInBounds(int position) const
{
	return position >= 0 && position < size;
}

// --------------------------------------------- PUBLIC METHODS --------------------------------------------- //
template<typename T>
string ArrayList<T>::toString() const {
	return List<T>::toString();
}

template<typename T>
int ArrayList<T>::getSize() const
{
	return size;
}

template<typename T>
bool ArrayList<T>::isEmpty() const
{
	return size == 0;
}

template<typename T>
void ArrayList<T>::add(T item)
{
	checkRange();
	array[size] = item;
	size++;
}

template<typename T>
void ArrayList<T>::clear() {
	delete[] array;
	capacity = DEFAULT_CAPACITY;
	size = 0;
	array = 0;

	init(capacity);
}

template<typename T>
T ArrayList<T>::get(int position) const
{
	checkPosition(position);
	return array[position];
}

template<typename T>
T ArrayList<T>::getFirst() const
{
	checkNonEmpty();
	return array[0];
}

template<typename T>
T ArrayList<T>::getLast() const
{
	checkNonEmpty();
	return array[size - 1];
}

//template<>
//string ArrayList<string>::toString() const {
//	if (isEmpty()) {
//		return "";
//
//	}
//	string str = "";
//
//	for (int i = 0; i < size; i++) {
//		str += array[i] + "\n";
//
//	}
//	return str;
//
//}
//
//template<>
//string ArrayList<int>::toString() const {
//	if (isEmpty()) {
//		return "";
//
//	}
//	string str = "";
//
//	for (int i = 0; i < size; i++) {
//		str += to_string(array[i]) + "\n";
//
//	}
//	return str;
//
//}


template<typename T>
void ArrayList<T>::add(int position, T item)
{
	if (position == size)
	{
		add(item);
		return;
	}
	checkPosition(position);
	shiftRigth(position);
	array[position] = item;
}

template<typename T>
void ArrayList<T>::set(int position, T item)
{
	checkPosition(position);
	array[position] = item;
}

template<typename T>
void ArrayList<T>::remove(int position)
{
	checkPosition(position);
	shiftLeft(position);
}

template<typename T>
void ArrayList<T>::removeFirst()
{
	checkNonEmpty();
	remove(0);
}

template<typename T>
void ArrayList<T>::removeLast()
{
	checkNonEmpty();
	remove(size - 1);
}
