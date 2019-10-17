//
// Created by mfbut on 2/16/2019.
//

#ifndef TESTDOUBLELINKEDLIST_CONSTDOUBLYLINKEDLISTITERATOR_H
#define TESTDOUBLELINKEDLIST_CONSTDOUBLYLINKEDLISTITERATOR_H
template<typename T>
class DoublyLinkedList;

template<typename T>
class ConstDoublyLinkedListIterator {
//you must implement at least the methods below
  //you are free to add (and will likely need to add)
  //more members and methods

 public:
	 DoublyLinkedList<T>& linkedlist;
	 const DoubleLinkedNode<T>* thisnode;

	 ConstDoublyLinkedListIterator(DoublyLinkedList<T>& linkedList);
	 ConstDoublyLinkedListIterator(DoublyLinkedList<T>& linkedList, DoubleLinkedNode<T>* start);

	 ConstDoublyLinkedListIterator(const ConstDoublyLinkedListIterator& orig) = default;

  //are the two iterators equal?
  //they are if they are over the same doubly linked list
  //and (they are referring to the same element in the list
  //or they are out of bounds)
	 bool operator==(const ConstDoublyLinkedListIterator<T>& rhs) const {
		 if (&linkedlist != &rhs.list) {
			 return false;
		 }
		 else {
			 return thisnode == rhs.pos;
		 }
  }

  //are the two iterators different?
	 bool operator!=(const ConstDoublyLinkedListIterator<T>& rhs) const {
		 return !(*this == rhs);
  }

  //is the iterator safe to dereference?
	 operator bool() const {
		 return thisnode != nullptr;
  }

  //go to the next element
	 ConstDoublyLinkedListIterator<T>& operator++() {
		 if (thisnode) {
			 thisnode = thisnode->getNext();
			 return *this;
		 }
		 else {
			 throw LinkedListEmptyError();
		 }
  }
  const ConstDoublyLinkedListIterator<T> operator++(int) {
	  ConstDoublyLinkedListIterator<T> cur(*this);
	  ++(*this);//thisno de = thisnode->getNext();
	  return cur;
  }

  //go to the previous element
  ConstDoublyLinkedListIterator<T>& operator--() {
	  if (thisnode) {
		  thisnode = thisnode->getPrev();
		  return *this;
	  }
	  else {
		  throw LinkedListEmptyError();
	  }
  }
  const ConstDoublyLinkedListIterator<T> operator--(int) {
	  ConstDoublyLinkedListIterator<T> cur(*this);
	  thisnode = thisnode->getPrev();
	  return cur;
  }

  //get a const reference to the value
  const T& operator*() const {
	  return thisnode->getData();
  }

};

#endif //TESTDOUBLELINKEDLIST_CONSTDOUBLYLINKEDLISTITERATOR_H
#include "DoublyLinkedList.h"	

template<typename T>
ConstDoublyLinkedListIterator<T>::DoublyLinkedListIterator(DoublyLinkedList<T>& linkedList) : linkedlist(linkedlist), thisnode(linkedlist.head) {}

template<typename T>
ConstDoublyLinkedListIterator<T>::DoublyLinkedListIterator(DoublyLinkedList<T>& linkedList, DoubleNode<T>* start) : linkedlist(linkedlist), thisnode(start) {}