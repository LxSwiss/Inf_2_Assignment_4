//
//  Heap.cpp
//  Heap
//
//  Created by Loc Nguyen on 21.03.12.
//  Copyright (c) 2012 Universität Zürich. All rights reserved.
//
#include "Heap.h"
#include <iostream>
#include "Exception.h"
#include "EmptyContainerException.h"

template <typename Key, typename Element>
Heap<Key, Element>::Heap(int capac)
: heap(capac), sizeOfHeap(1) {

}

template <typename Key, typename Element>
int Heap<Key, Element>::size() const {
	return sizeOfHeap-1;
}

template <typename Key, typename Element>
bool Heap<Key, Element>::isEmpty() const{
	return sizeOfHeap==1;
}

template <typename Key, typename Element>
const std::string& Heap<Key, Element>::minElement() const throw(EmptyContainerException){
    if(isEmpty()) {
        throw EmptyContainerException();
    }
    return heap[1].second;  //dafuq??
}

template <typename Key, typename Element>
const int& Heap<Key, Element>::minKey() const throw(EmptyContainerException){
    if(isEmpty()) {
        throw EmptyContainerException();
    }
    return heap[1].first;
}


template <typename Key, typename Element>
void Heap<Key, Element>::insertItem(const Key& k, const Element& e) {

    Node newNode = Node(k, e);
    int currentPos = sizeOfHeap;
    int parent = getParent(currentPos);

    // insert the new element newNode in the vector heap at last position
    heap[currentPos] = newNode;
    sizeOfHeap++;
    upheap(currentPos, parent);

}

template <typename Key, typename Element>
void Heap<Key, Element>::removeMin() throw(EmptyContainerException) {
    if(isEmpty()) {
        throw EmptyContainerException();
    }

    // remove Node
    sizeOfHeap--;

    // last node is now first node
    heap[1] = heap[sizeOfHeap];
    downheap(1, 2); //currentPost: 1, left childPos: 2
}


template <typename Key, typename Element>
int Heap<Key, Element>::getParent(int childPos) {
    if(childPos == 1) {
        return 0;
    }
    if(childPos%2 != 0) {
        return (childPos-1)/2;
    }
    return (childPos/2);
}


template <typename Key, typename Element>
void Heap<Key, Element>::upheap(int current, int parent) {
    if(current == 1) {
        return;
    }
    Node tmpNode = heap[current];
    Node parentNode = heap[getParent(current)];
    if(tmpNode.first < parentNode.first) {
        //swap
        heap[0] = heap[current];
        heap[current] = heap[parent];
        heap[parent] = heap[0];
        upheap(getParent(current), getParent(getParent(current)));
    } else {
        //you're finished
        return;
    }
}

template <typename Key, typename Element>
void Heap<Key, Element>::downheap(int current, int child) {
    Node currentNode = heap[current];
    Node childNode = heap[child];

    //if left node has a smaller key, try the right one
    if(childNode.first > currentNode.first) {
        childNode = heap[child+1];
        child++;
    }

    //if the value of the childnode is smaller than the current one you're finished
    if(childNode.first >= currentNode.first) {
        return;
    }
    // else swap the elements
    heap[0] = heap[current];
    heap[current] = heap[child];
    heap[child] = heap[0];

    downheap(child, 2*child);
}


template class Heap<int, std::string>;

