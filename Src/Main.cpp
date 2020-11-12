/*
 * Copyright (c) 2019 Tobias Briones.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <iostream>
#include "Collection/List/ArrayList.h"
#include "Collection/List/LinkedList.h"

using namespace std;

int main()
{
    // pseudo unit tests for now :/ ^.^
    // This is the LinkedList I implemented some years ago and left behind
    // It has a bug when calling more than once removeFirst or removeLast
    // I'll take care of that later
    LinkedList<int> ll;

    ll.add(5);
    ll.add(632);
    ll.add(347);
    ll.add(678);
    ll.add(4);

    for (int i = 0; i < ll.getSize(); i++)
    {
        cout << ll.get(i) << std::endl;
    }

    ll.removeFirst();
    cout << std::endl;

    for (int i = 0; i < ll.getSize(); i++)
    {
        cout << ll.get(i) << std::endl;
    }
    ll.removeLast();
    cout << std::endl;

    for (int i = 0; i < ll.getSize(); i++)
    {
        cout << ll.get(i) << std::endl;
    }
    cout << std::endl;

    ll.add(632);
    ll.add(347);
    ll.add(678);
    ll.add(4);

    for (int i = 0; i < ll.getSize(); i++)
    {
        cout << ll.get(i) << std::endl;
    }
    cout << std::endl;

    ll.remove(4);

    for (int i = 0; i < ll.getSize(); i++)
    {
        cout << ll.get(i) << std::endl;
    }
    cout << std::endl;

    ll.set(2, 45);

    for (int i = 0; i < ll.getSize(); i++)
    {
        cout << ll.get(i) << std::endl;
    }
    cout << std::endl;

    ll.add(5, 3);

    for (int i = 0; i < ll.getSize(); i++)
    {
        cout << ll.get(i) << std::endl;
    }
    cout << std::endl;
    cout << ll.getFirst() << std::endl;
    cout << std::endl;
    cout << ll.getLast() << std::endl;

    cout << std::endl;
    cout << ll.get(5) << std::endl;
    ll.clear();

    for (int i = 0; i < ll.getSize(); i++)
    {
        cout << ll.get(i) << std::endl;
    }
    cout << std::endl;
    return 0;
}
