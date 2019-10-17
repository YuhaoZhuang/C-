	//
// Created by mfbut on 2/11/2019.
//

#ifndef LINKEDLIST_DOUBLYLINKEDLIST_H
#define LINKEDLIST_DOUBLYLINKEDLIST_H

#include <vector>
#include <memory>
#include "DoubleLinkedNode.h"
#include "DoublyLinkedListIterator.h"
#include "ReverseDoublyLinkedListIterator.h"

template<typename T>
class DoublyLinkedList {
 public:
  using Node_Ptr = DoubleLinkedNode<T>*;
  using iterator =  DoublyLinkedListIterator<T>/*put the type of your iterator here*/;
  using const_iterator = ConstDoublyLinkedListIterator<T> /*put the type of your const iterator here*/;
  using reverse_iterator = ReverseDoublyLinkedListIterator<T>/*put the type of your reverse iterator here*/;
  using const_reverse_iterator =ConstReverseDoublyLinkedListIterator<T> /*put the type of your const reverse iterator here*/;

  //create a Doubly Linked List that has the same values
  //as in the vector and in the same order
  explicit DoublyLinkedList(const std::vector<T>& values);
  {
	  for (int i = 0; i < values.size(); i++) {
		  push_back(values);
	  }
	  len = values.size();
  }
  //create an empty DoublyLinkedList
  DoublyLinkedList() {
	  len = 0;
	  head = nullptr;
	  tail = nullptr;
  }


  virtual ~DoublyLinkedList();

  //remove all of the elements from your list
  void clear() {
	  for (i = 0; i < len; i++) {
		  
	  }
  }

  //get a reference to the front element in the list
  const T& front() const;
  T& front() {
	  if (head) {
		  return head->data;
	  }
  }
  

  //get a reference to the last element in the list
  const T& back() const;
  T& back() {
	  if (tail) {
		  return tail->data;
	  }
  }

  //add a value to the front of the list
  void push_front(const T& value) {
	  len += 1;
	  //Doub
	  DoubleLinkedNode<T>* new_node = new DoubleLinkedNode<T>(value, nullptr, head);

	  if (head != nullptr) {
		  head->setPrev(new_node); 
	  }
	  else {
		  tail = new_node;
	  }
	  head = new_node; 
  }

  //add a value to the back of the list
  void push_back(const T& value) {
	  len += 1;
	  DoubleLinkedNode<T>* new_node = new DoubleLinkedNode<T>(value);
	  DoubleLinkedNode<T>* last = head; 
	  new_node->next = nullptr;
	  if (empty()) {
		  new_node->prev(nullptr);
		  head = new_node;
		  tail = new_node;
	  }
	  else {
		  tail->setNext(new_node);
		  new_node->setPrev(tail);
		  tail = new_node; 
	  }
  }

  //is the list empty?
  bool empty() const {
	  if (head == nullptr & tail == nullptr) {
		  return true;
	  }
	  else {
		  return false;
	  }
  }

  //return the number of elements in the list                                                                                                                 
  int size() const {
	  return len;
  }

  //return a constant bidirectional iterator to the front of the list
  const_iterator begin() const {
	  return iterator(this, this->Head);
  }
  const_iterator end() const {
	  return iterator(this, this->tail);
  }

  //return a nonconstant bidirectional iterator to the front of the list
  iterator begin() {
	  return iterator(this, this->head);
  }
  iterator end() {
	  return iterator(this,this->tail);
  }

  const_reverse_iterator crbegin() const {
	  return const_reverse_iterator(this, this->tail);
  }
  const_reverse_iterator crend() const {
	  return const_revrse_iterator(this, this->head);
  }

  reverse_iterator rbegin() {
	  return reverse_iterator(this, this->head);
  }
  reverse_iterator rend() {
	  return reverse_iterator(this, this->tail);
  }

  //insert the value at the position in the list
  //I promise not to use the iterator again after the insertion is done
  //An example if we had the list 1 <-> 9 <-> 17
  //And the iterator was pointing to the 9 and we wanted to
  //insert -22 the result would be
  //1 <-> 22 <-> 9 <-> 17
  void insert(iterator& position, const T& value) {
	 
  }

  //remove the element at the position pointed to
  //by the iterator.
  //I promise not to use the iterator again after the erase is done
  //An example if we had the list 1 <-> 9 <-> 17
  //And when the wanted to erase the iterator was at the 9
  //1 <-> 17
  void erase(iterator& position) {

  }

// private:
  Node_Ptr head;
  Node_Ptr tail;
  int len;
};

//write to the stream each element in the list in order
//with a space in between them
template<typename T>
std::ostream& operator<<(std::ostream& out, const DoublyLinkedList<T>& doublyLinkedList);

//read elements from the stream as long as it is good
// or until a newline (\n) is encountered
//if a newline is encontered it should be consumed
template<typename T>
std::istream& operator>>(std::istream& in, DoublyLinkedList<T>& doublyLinkedList);


#endif //LINKEDLIST_DOUBLYLINKEDLIST_H
