/**
 * Copyright (c) 2019 Tobias Briones.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once
#include <stdexcept>
#include <sstream>
#include "../Collection.h"

using std::to_string;
using std::stringstream;

template<typename T>
class List : public Collection<T>
{

protected:
	virtual bool isInBounds(int) const = 0;
	void checkPosition(int) const;
	void checkEmpty() const;
	void checkNonEmpty() const;

public:
	virtual string toString() const = 0;
	virtual int getSize() const = 0;
	virtual bool isEmpty() const = 0;
	virtual void add(T) = 0;
	virtual void clear() = 0;

	virtual T get(int) const = 0;
	virtual T getFirst() const = 0;
	virtual T getLast() const = 0;
	virtual void add(int, T) = 0;
	virtual void set(int, T) = 0;
	virtual void remove(int) = 0;
	virtual void removeFirst() = 0;
	virtual void removeLast() = 0;

};

template<typename T>
void List<T>::checkPosition(int position) const
{
	if (!isInBounds(position))
	{
		string msg = "Invalid position " + to_string(position);
		throw std::runtime_error(msg);
	}
}

template<typename T>
void List<T>::checkEmpty() const
{
	if (!isEmpty())
	{
		string msg = "Non-Empty list";
		throw std::runtime_error(msg);
	}
}

template<typename T>
void List<T>::checkNonEmpty() const
{
	if (isEmpty())
	{
		string msg = "Empty list";
		throw std::runtime_error(msg);
	}
}

template<typename T>
string List<T>::toString() const
{
	int size = getSize();
	stringstream ss; // Possibly need to et a more efficient way to concatenate the strings in C++

	ss << "[ ";
	for (int i = 0; i < size; i++)
	{
		if (i == size - 1)
		{
			ss << get(i) << " ";
			continue;
		}
		ss << get(i) << ", ";
	}
	ss << "]";
	return ss.str();
}
