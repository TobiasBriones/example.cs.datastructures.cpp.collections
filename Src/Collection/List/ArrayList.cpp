/**
 * Copyright (c) 2019 Tobias Briones.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "ArrayList.h"

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
		T* oldArrayPtr = array;
		int newCapacity = capacity * FACTOR;
		array = new T[newCapacity];

		for (int i = 0; i < size; i++) 
		{
			array[i] = oldArrayPtr[i];
		}
		delete[] oldArrayPtr;
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

template<typename T>
void ArrayList<T>::shiftLeft(int position)
{
	size--;
	for (int i = position; i < size; i++) 
	{
		array[i] = array[i + 1];
	}
}

// --------------------------------------------- PROTECTED METHODS --------------------------------------------- //
template<typename T>
bool ArrayList<T>::isInBounds(int position) const 
{
	return position >= 0 && position < size;
}

// --------------------------------------------- PUBLIC METHODS --------------------------------------------- //
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
T ArrayList<T>::get(int position) const 
{
	if (!isInBounds(position)) 
	{
		string msg = "Invalid position " + to_string(position);
		throw std::runtime_error(msg);
	}
	return array[position];
}

template<typename T>
T ArrayList<T>::getFirst() const 
{
	if (isEmpty()) 
	{
		string msg = "Empty list";
		throw std::runtime_error(msg);
	}
	return array[0];
}

template<typename T>
T ArrayList<T>::getLast() const 
{
	if (isEmpty()) 
	{
		string msg = "Empty list";
		throw std::runtime_error(msg);
	}
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
void ArrayList<T>::add(T item)
{
	checkRange();
	array[size] = item;
	size++;
}

template<typename T>
void ArrayList<T>::add(int position, T item) 
{
	if (!isInBounds(position)) {
		if (position == size)
		{
			add(item);
		}
		else 
		{
			string msg = "Invalid position " + to_string(position);
			throw std::runtime_error(msg);
		}
		return;
	}
	shiftRigth(position);
	array[position] = item;
}

template<typename T>
void ArrayList<T>::set(int position, T item)
{
	if (!isInBounds(position)) 
	{
		string msg = "Invalid position " + to_string(position);
		throw std::runtime_error(msg);
	}
	array[position] = item;
}

template<typename T>
void ArrayList<T>::remove(int position)
{
	if (!isInBounds(position)) 
	{
		string msg = "Invalid position " + to_string(position);
		throw std::runtime_error(msg);
	}
	shiftLeft(position);
}

template<typename T>
void ArrayList<T>::removeFirst()
{
	if (isEmpty()) 
	{
		string msg = "Empty list";
		throw std::runtime_error(msg);
	}
	remove(0);
}

template<typename T>
void ArrayList<T>::removeLast()
{
	if (isEmpty())
	{
		string msg = "Empty list";
		throw std::runtime_error(msg);
	}
	remove(size - 1);
}

template<typename T>
void ArrayList<T>::clear() {
	delete[] array;
	capacity = DEFAULT_CAPACITY;
	size = 0;
	array = 0;

	init(capacity);
}

template class ArrayList<int>;
