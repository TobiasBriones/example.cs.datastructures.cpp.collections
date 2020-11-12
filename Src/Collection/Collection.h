/*
 * Copyright (c) 2019 Tobias Briones.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

template<typename T>
class Collection
{

public:
    virtual int getSize() const = 0;

    virtual bool isEmpty() const = 0;

    virtual void add(T) = 0;

    virtual void clear() = 0;
};

// Possible future implementations

/*
// Valid just for numeric and string types T
virtual string toString() const = 0;
// Add iterator, copy()

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


*/
