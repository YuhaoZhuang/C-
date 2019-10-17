//
// Created by mfbut on 2/11/2019.
//

#ifndef LINKEDLIST_DOUBLELINKEDNODE_H
#define LINKEDLIST_DOUBLELINKEDNODE_H
#include <iostream>

//the class that represents a node in the list

template<typename T>
class DoubleLinkedNode {
public:

	DoubleLinkedNode(const T& data);
	DoubleLinkedNode(const T& data, DoubleLinkedNode<T> *prev, DoubleLinkedNode<T> *next);
	
	void setNext(DoubleLinkedNode<T>* next);
	void setPrev(DoubleLinkedNode<T>* prev);
	DoubleLinkedNode<T>* getNext() const;
	DoubleLinkedNode<T>* getPrev() const;
	const T& getData() const;
	private:
	T data;
	DoubleLinkedNode<T> *prev;
	DoubleLinkedNode<T> *next;

};


#endif //LINKEDLIST_DOUBLELINKEDNODE_H

template<typename T>
 DoubleLinkedNode<T>::DoubleLinkedNode(const T & data) : data(data), prev(nullptr),next(nullptr)
{
}

 template<typename T>
  DoubleLinkedNode<T>::DoubleLinkedNode(const T & data, DoubleLinkedNode<T>* prev, DoubleLinkedNode<T>* next) : data(data),prev(prev),next(next)
 {
 }	

template<typename T>
void DoubleLinkedNode<T>::setNext(DoubleLinkedNode<T>* next) {
	this.next = next; 
}

template<typename T>
void DoubleLinkedNode<T>::setPrev(DoubleLinkedNode<T>* prev) {
	this.prev = prev;
}

template<typename T>
 DoubleLinkedNode<T>* DoubleLinkedNode<T>::getPrev() const
{
	return prev;
}

 template<typename T>
 DoubleLinkedNode<T>* DoubleLinkedNode<T>::getNext() const
 {
	 return next;
 }

 template<typename T>
 const T& DoubleLinkedNode<T>::getData() const
 {
	 return data;
 }



