/**
 * Copyright (c) 2019 Tobias Briones.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once
#include <string>
#include <stdexcept>
#include "../Collection.h"

using std::string;
using std::to_string;

template<typename T>
class List : public Collection<T>
{

protected:
	virtual bool isInBounds(int) const = 0;

public:
	/*List();
	List(List<T>*);
	~List();*/

	virtual int getSize() const = 0;
	virtual bool isEmpty() const = 0;
	virtual T get(int) const = 0;
	virtual T getFirst() const = 0;
	virtual T getLast() const = 0;
	//virtual string toString() const = 0;
	virtual void add(T) = 0;
	virtual void add(int, T) = 0;
	virtual void set(int, T) = 0;
	virtual void remove(int) = 0;
	virtual void removeFirst() = 0;
	virtual void removeLast() = 0;
	virtual void clear() = 0;

};
