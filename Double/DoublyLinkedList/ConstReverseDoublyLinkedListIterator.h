//
// Created by mfbut on 2/16/2019.
//

#ifndef TESTDOUBLELINKEDLIST_CONSTREVERSEDOUBLYLINKEDLISTITERATOR_H
#define TESTDOUBLELINKEDLIST_CONSTREVERSEDOUBLYLINKEDLISTITERATOR_H

template<typename T>
class DoublyLinkedList;

template<typename T>
class ConstReverseDoublyLinkedListIterator {
//you must implement at least the methods below
  //you are free to add (and will likely need to add)
  //more members and methods
	DoublyLinkedList<T>& linkedlist;
	DoubleLinkedNode<T>* thisnode;

	ConstReverseDoublyLinkedListIterator(DoublyLinkedList<T>& linkedList);
	ConstReverseDoublyLinkedListIterator(DoublyLinkedList<T>& linkedList, DoubleLinkedNode<T>* start);
  //copy constructor
	ConstReverseDoublyLinkedListIterator(const ConstReverseDoublyLinkedListIterator& orig) = default; 

  //are the two iterators equal?
  //they are if they are over the same doubly linked list
  //and (they are referring to the same element in the list
  //or they are out of bounds)
	bool operator==(const ConstReverseDoublyLinkedListIterator<T>& rhs) const {
		if (&linkedlist != &rhs.list) {
			return false;
		}
		else {
			return thisnode == rhs.pos;
		}
  }

  //are the two iterators different?
	bool operator!=(ConstReverseDoublyLinkedListIterator<T>& rhs) const {
		return !(*this == rhs);
  }

  //is the iterator safe to dereference?
	operator bool() const {
		return thisnode != nullptr;
  }

  //go to the next element
	ConstReverseDoublyLinkedListIterator<T>& operator++() {
		if (thisnode) {
			thisnode = thisnode->getNext();
			return *this;
		}
		else {
			throw LinkedListEmptyError();
		}
  }
	const ConstReverseDoublyLinkedListIterator<T> operator++(int) {
		ConstReverseDoublyLinkedListIterator<T> cur(*this);
		++(*this);//thisnode = thisnode->getNext();
		return cur;
  }

  //go to the previous element
	ConstReverseDoublyLinkedListIterator<T>& operator--() {
		if (thisnode) {
			thisnode = thisnode->getPrev();
			return *this;
		}
		else {
			throw LinkedListEmptyError();
		}
  }
	const ConstReverseDoublyLinkedListIterator<T> operator--(int) {
		ConstReverseDoublyLinkedListIterator<T> cur(*this);
		--(*this);//thisnode = thisnode->getPrev();
		return cur;
  }

  //get a const reference to the value
	const T& operator*() const {
		return thisnode->getData();
  }

};

#endif //TESTDOUBLELINKEDLIST_CONSTREVERSEDOUBLYLINKEDLISTITERATOR_H
#include "DoublyLinkedList.h"	

template<typename T>
ConstReverseDoublyLinkedListIterator<T>::DoublyLinkedListIterator(DoublyLinkedList<T>& linkedList) : linkedlist(linkedlist), thisnode(linkedlist.head) {}

template<typename T>
ConstReverseDoublyLinkedListIterator<T>::DoublyLinkedListIterator(DoublyLinkedList<T>& linkedList, DoubleLinkedNode<T>* start) : linkedlist(linkedlist), thisnode(start) {}

