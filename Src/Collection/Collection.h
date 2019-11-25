/**
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
	// Add iterator and toString()

};
