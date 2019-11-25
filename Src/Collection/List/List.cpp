/**
 * Copyright (c) 2019 Tobias Briones.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "List.h"

template<typename T>
void List<T>::checkPosition(int position) const
{
	if (!isInBounds(position))
	{
		string msg = "Invalid position " + to_string(position);
		throw std::runtime_error(msg);
	}
}

template class List<int>;