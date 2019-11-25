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
		void shiftRigth(int);
		void shiftLeft(int);

	protected:
		bool isInBounds(int) const;

	public:
		ArrayList();
		ArrayList(ArrayList<T>*);
		ArrayList(int);
		~ArrayList();

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
