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
const std::string& Heap<Key, Element>::minElement() const throw(EmptyContainerException) {
    if(isEmpty()) {
        throw EmptyContainerException();
    }
    return heap[1].second;
}

template <typename Key, typename Element>
const int& Heap<Key, Element>::minKey() const throw(EmptyContainerException) {
    if(isEmpty()) {
        throw EmptyContainerException();
    }
    return heap[1].first;
}



