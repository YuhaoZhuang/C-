//
// Created by mfbut on 2/13/2019.
//

#ifndef LINKEDLIST_GENERICREVERSEDOUBLYLINKEDLISTITERATOR_H
#define LINKEDLIST_GENERICREVERSEDOUBLYLINKEDLISTITERATOR_H

template<typename T>
class DoublyLinkedList;

template<typename T>
class ReverseDoublyLinkedListIterator {
 public:
  //you must implement at least the methods below
  //you are free to add (and will likely need to add)
  //more members and methods
	 DoublyLinkedList<T>& linkedlist;
	 DoubleLinkedNode<T>* thisnode;
	 ReverseDoublyLinkedListIterator(DoublyLinkedList<T>& linkedList);
	 ReverseDoublyLinkedListIterator(DoublyLinkedList<T>& linkedList, DoubleLinkedNode<T>* start);
  //copy constructor
	 ReverseDoublyLinkedListIterator(const ReverseDoublyLinkedListIterator& orig) = default; 

  //are the two iterators equal?
  //they are if they are over the same doubly linked list
  //and (they are referring to the same element in the list
  //or they are out of bounds)
	 bool operator==(const ReverseDoublyLinkedListIterator<T>& rhs) const {
		 if (&linkedlist != &rhs.list) {
			 return false;
		 }
		 else {
			 return thisnode == rhs.pos;
		 }
  }

  //are the two iterators different?
	 bool operator!=(ReverseDoublyLinkedListIterator<T>& rhs) const {
		 return !(*this == rhs);
  }

  //is the iterator safe to dereference?
	 operator bool() const {
		 return thisnode != nullptr;
  }

  //go to the next element
	 ReverseDoublyLinkedListIterator<T>& operator++() {
		 if (thisnode) {
			 thisnode = thisnode->getNext();
			 return *this;
		 }
		 else {
			 throw LinkedListEmptyError();
		 }
  }
	 const ReverseDoublyLinkedListIterator<T> operator++(int) {
		 ReverseDoublyLinkedListIterator<T> cur(*this);
		 ++(*this);//thisnode = thisnode->getNext();
		 return cur;
  }

  //go to the previous element
	 ReverseDoublyLinkedListIterator<T>& operator--() {
		 if (thisnode) {
			 thisnode = thisnode->getPrev();
			 return *this;
		 }
		 else {
			 throw LinkedListEmptyError();
		 }
  }
	 const ReverseDoublyLinkedListIterator<T> operator--(int) {
		 ReverseDoublyLinkedListIterator<T> cur(*this);
		 --(*this);//thisnode = thisnode->getPrev();
		 return cur;
  }

  //get a const reference to the value
	 const T& operator*() const {
		 return thisnode->getData();
  }

  //get a non-const reference to the value
	 T& operator*() {
		 return thisnode->getData();
  }

};

#endif //LINKEDLIST_GENERICREVERSEDOUBLYLINKEDLISTITERATOR_H
#include "DoublyLinkedList.h"	

template<typename T>
ReverseDoublyLinkedListIterator<T>::DoublyLinkedListIterator(DoublyLinkedList<T>& linkedList) : linkedlist(linkedlist), thisnode(linkedlist.tail) {}

template<typename T>
ReverseDoublyLinkedListIterator<T>::DoublyLinkedListIterator(DoublyLinkedList<T>& linkedList, DoubleLinkedNode<T>* start) : linkedlist(linkedlist), thisnode(start) {}
