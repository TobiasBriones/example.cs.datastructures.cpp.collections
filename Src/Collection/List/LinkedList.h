/*
 * Copyright (c) 2019 Tobias Briones.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include "List.h"

template<typename T>
class LinkedList : public List<T>
{

private:
    class Node
    {

    public:
        T item;
        Node* previous;
        Node* next;

        Node();
    };

    int size;
    Node* const tail;
    Node* const head;

    void init();

protected:
    bool isInBounds(int) const;

public:
    LinkedList();

    LinkedList(LinkedList<T>*);

    ~LinkedList();

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

template<typename T>
LinkedList<T>::Node::Node()
{
    this->item = NULL;
    this->previous = NULL;
    this->next = NULL;
}

template<typename T>
LinkedList<T>::LinkedList() :
    tail(new Node()),
    head(new Node())
{
    init();
}

template<typename T>
LinkedList<T>::LinkedList(LinkedList<T>* const src) :
    tail(new Node()),
    head(new Node())
{
    init();

    for (int i = 0; i < size; i++)
    {
        add(src->get(i));
    }
}

template<typename T>
LinkedList<T>::~LinkedList()
{
    clear();
    delete tail;
    delete head;
}

// --------------------------------------------- PRIVATE METHODS --------------------------------------------- //
template<typename T>
void LinkedList<T>::init()
{
    size = 0;
    tail->next = head;
    head->previous = tail;
}

// --------------------------------------------- PROTECTED METHODS --------------------------------------------- //
template<typename T>
bool LinkedList<T>::isInBounds(int position) const
{
    return position >= 0 && position < size;
}

// --------------------------------------------- PUBLIC METHODS --------------------------------------------- //
template<typename T>
int LinkedList<T>::getSize() const
{
    return size;
}

template<typename T>
bool LinkedList<T>::isEmpty() const // Abstract this method
{
    return size == 0;
}

template<typename T>
void LinkedList<T>::add(T item)
{
    if (isEmpty())
    {
        tail->item = item;
        head->item = item;
        size++;
        return;
    }
    if (size == 1)
    {
        head->item = item;
        size++;
        return;
    }
    Node* node = new Node();
    Node* previousNode = head->previous;

    previousNode->next = node;
    node->item = head->item;
    node->previous = previousNode;
    node->next = head;
    head->item = item;
    head->previous = node;
    size++;
}

template<typename T>
void LinkedList<T>::clear()
{
    Node* currentNode = tail->next;
    Node* tmp = 0;

    while (currentNode != head)
    {
        tmp = currentNode;
        currentNode = currentNode->next;
        delete tmp;
    }
    init();
}

template<typename T>
T LinkedList<T>::get(int position) const
{
    checkPosition(position);
    Node* node = tail;
    int i = 0;

    while (i != position)
    {
        node = node->next;
        i++;
    }
    return node->item;
}

template<typename T>
T LinkedList<T>::getFirst() const
{
    checkNonEmpty();
    return tail->item;
}

template<typename T>
T LinkedList<T>::getLast() const
{
    checkNonEmpty();
    return head->item;
}

template<typename T>
void LinkedList<T>::add(int position, T item)
{
    if (position == size)
    {
        add(item);
        return;
    }
    checkPosition(position);
    Node* node = new Node();

    if (position == 0)
    {
        node->item = tail->item;
        node->previous = tail;
        node->next = tail->next;
        tail->item = item;
        tail->next = node;
        size++;
        return;
    }
    Node* nextNode = tail;
    Node* previousNode = 0;
    int i = 0;

    while (i != position)
    {
        nextNode = nextNode->next;
        i++;
    }
    previousNode = nextNode->previous;
    node->item = item;
    node->previous = previousNode;
    node->next = nextNode;
    previousNode->next = node;
    nextNode->previous = node;
    size++;
}

template<typename T>
void LinkedList<T>::set(int position, T item)
{
    checkPosition(position);
    if (position == 0 || position == (size - 1))
    {
        if (size == 1)
        {
            tail->item = item;
            head->item = item;
            return;
        }
        if (position == 0)
        {
            tail->item = item;
        }
        else
        {
            head->item = item;
        }
        return;
    }
    Node* targetNode = tail;
    int i = 0;

    while (i != position)
    {
        targetNode = targetNode->next;
        i++;
    }
    targetNode->item = item;
}

template<typename T>
void LinkedList<T>::remove(int position)
{
    checkPosition(position);
    if (position == 0 || position == (size - 1))
    {
        if (position == 0)
        {
            removeFirst();
        }
        else
        {
            removeLast();
        }
        return;
    }
    int i = 0;
    Node* targetNode = tail;
    Node* previousNode = 0;
    Node* nextNode = 0;

    while (i != position)
    {
        targetNode = targetNode->next;
        i++;
    }
    previousNode = targetNode->previous;
    nextNode = targetNode->next;

    previousNode->next = nextNode;
    nextNode->previous = previousNode;
    size--;

    delete targetNode;
    targetNode = 0;
}

template<typename T>
void LinkedList<T>::removeFirst()
{
    checkNonEmpty();
    if (size == 1)
    {
        clear();
        return;
    }
    if (size == 2)
    {
        T headItem = head->item;

        clear();
        add(headItem);
        return;
    }
    Node* nextNode = tail->next;

    tail->item = nextNode->item;
    tail->next = nextNode->next;
    size--;
    delete nextNode;
}

template<typename T>
void LinkedList<T>::removeLast()
{
    checkNonEmpty();
    if (size == 1)
    {
        clear();
        return;
    }
    if (size == 2)
    {
        T tailItem = tail->item;

        clear();
        add(tailItem);
        return;
    }
    Node* previousNode = head->previous;

    head->item = previousNode->item;
    head->previous = previousNode->previous;
    size--;
    delete previousNode;
}
