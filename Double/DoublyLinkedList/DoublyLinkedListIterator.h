
// Created by mfbut on 2/11/2019.
//

#ifndef LINKEDLIST_GENERICDOUBLYLINKEDLISTITERATOR_H
#define LINKEDLIST_GENERICDOUBLYLINKEDLISTITERATOR_H


template<typename T>
class DoublyLinkedList; 

template<typename T>
class DoublyLinkedListIterator {
  //you must implement at least the methods below
  //you are free to add (and will likely need to add)
  //more members and methods
	

 public:
	 DoublyLinkedList<T>& linkedlist;
	 DoubleLinkedNode<T>* thisnode;

	 DoublyLinkedListIterator(DoublyLinkedList<T>& linkedList);
	 DoublyLinkedListIterator(DoubleLinkedList<T>& linkedList, DoubleLinkedNode<T>* start);

	 DoublyLinkedListIterator(const DoublyLinkedListIterator<T>& orig) = default;
 
  //are the two iterators equal?
  //they are if they are over the same doubly linked list
  //and (they are referring to the same element in the list
  //or they are out of bounds)
	 bool operator==(const DoublyLinkedListIterator<T>& rhs) const {
		 if (&linkedlist != &rhs.list) {
			 return false;
		 }
		 else {
			 return thisnode == rhs.pos; 
		 }
  }
  
  //are the two iterators different?
	 bool operator!=(const DoublyLinkedListIterator<T>& rhs) const {
		 return !(*this == rhs);
  }

  //is the iterator safe to dereference?
	 operator bool() const {
		 return thisnode != nullptr; 
  }

  //go to the next element
	 DoublyLinkedListIterator<T>& operator++() {
		 if (thisnode) {
			 thisnode = thisnode->getNext();
			 return *this;
		 }
		 else {
			 throw LinkedListEmptyError();
		 }
  }
  const DoublyLinkedListIterator<T> operator++(int) {
	  DoublyLinkedListIterator<T> cur(*this);
	  ++(*this);//thisnode = thisnode->getNext();
	  return cur;
  }

  //go to the previous element
  DoublyLinkedListIterator<T>& operator--() {
	  if (thisnode) {
		  thisnode = thisnode->getPrev();
		  return *this;
	  }
	  else {
		  throw LinkedListEmptyError();
	  }
  }
	  //pre	
  const DoublyLinkedListIterator<T> operator--(int) {
	  DoublyLinkedListIterator<T> cur(*this);
	  --(*this);//thisnode = thisnode->getPrev();
	  return cur; 
  }

  //get a const reference to the value
  const T& operator*() const {
	  return thisnode->getData();
  }

  //get a non const iterator
  T& operator*() {
	  return thisnode->getData();
  }

};

#endif //LINKEDLIST_GENERICDOUBLYLINKEDLISTITERATOR_H
#include "DoublyLinkedList.h"	

template<typename T>
DoublyLinkedListIterator<T>::DoublyLinkedListIterator(DoublyLinkedList<T>& linkedList) : linkedlist(linkedlist), thisnode(linkedlist.head){}

template<typename T>
DoublyLinkedListIterator<T>::DoublyLinkedListIterator(DoublyLinkedList<T>& linkedList, DoubleLinkedNode<T>* start) : linkedlist(linkedlist), thisnode(start) {}


	
