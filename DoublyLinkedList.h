#include "ListNode.h"
#include <iostream>
using namespace std;
template <typename T> class DoublyLinkedList
{
private:
  ListNode<T>* front;
  ListNode<T> *back;
  unsigned int size;
public:
  DoublyLinkedList();
  ~DoublyLinkedList();
  //inserts in front
  void insertFront(T d);
  //inserts in back
  void insertBack(T d);
  //removes object from front of linkedlist
  T removeFront();
  //removes object from back of list
  T removeBack();
  //adds object to front of linked list
  T returnFront();
  //deletes element of linked list given index
  T deletePos(int pos);
  //returns how many times it found an object
  int find(T d);
  ListNode<T>* remove(T d);
  bool isEmpty();
  //prints list
  void printList();
  //prints single element of list given index
  T printElement(int num);
  unsigned int getSize();
};
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(){

  typedef ListNode<T> Node;
  size=0;
  front=NULL;
  back=NULL;

}
template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList(){

}
//prints list
template <typename T>
void DoublyLinkedList<T>::printList(){
  ListNode<T> *curr=front;
  while(curr!= NULL){
    cout<<curr->data<<", ";
    curr = curr->next;
  }
}
//prints single element of list given index
template <typename T>
T DoublyLinkedList<T>::printElement(int num){
  int counter=0;
  ListNode<T> *curr=front;
  while(counter< num){
    curr = curr->next;
    counter++;
  }
  return curr->data;
}
//deletes element of linked list given index
template <typename T>
T DoublyLinkedList<T>::deletePos(int pos){
  ListNode<T> *curr=front;
  int counter=0;
  while(counter!=pos){
    curr=curr->next;
    counter++;
  }
  return curr->data;
}
//returns how many times it found an object
template <typename T>
int DoublyLinkedList<T>::find(T d){
  ListNode<T> *curr=front;
  int counter=0;
  if(curr->data==d){
    return counter;
  }
  while(curr->next!=NULL){
    counter++;
    curr=curr->next;
    if(curr->data==d){
      return counter;
    }
  }
  return -1;
}
//adds object to front of linked list
template <typename T>
void DoublyLinkedList<T>::insertFront(T d){
  ListNode<T> *node = new ListNode<T>(d);
  if(size==0){
    back=node;
  }
  else{
  node->next=front;
  front->prev=node;
}
front=node;
size++;
}
//removes object from front of linkedlist
template <typename T>
T DoublyLinkedList<T>::removeFront()
{
  ListNode<T> *ft=front;
  if(front->next==NULL){
    //only one element in the List
    back=NULL;
  }
  else{
    front->next->prev=NULL;
  }
  front=front->next;
  T temp =ft->data;
  ft->next=NULL;
  size--;
  delete ft;
  return temp;
}
//inserts object in back of linked list
template <typename T>
void DoublyLinkedList<T>::insertBack(T d)
{
  ListNode<T> *node = new ListNode<T>(d);
  if(size==0){
    front=node;
  }
  else{
  back->next=node;
  node->prev=back;
}
back=node;
size++;
}
//removes object from back of linked list
template <typename T>
T DoublyLinkedList<T>::removeBack()
{
  if(size==1){
    removeFront();
  }
  else{
    ListNode<T> *bk=back;
    back=back->prev;
    bk->prev=NULL;
    bk->prev->next=NULL;
    T temp=bk->data;
    delete bk;
    size--;
    return temp;
  }
}
//returns size
template <typename T>
unsigned int DoublyLinkedList<T>::getSize(){
  return size;
}
//removes given object of a linked list
template <typename T>
ListNode<T>* DoublyLinkedList<T>::remove(T d)
{
  ListNode<T> *curr=front;
  while(curr->data != d){
    curr=curr->next;
    if(curr==NULL){
      return NULL;
    }
  }
  if (curr==front){
    front=curr->next;
  }
  else
  {
      curr->prev->next=curr->next;
  }
  if(curr==back){
    back=curr->prev;
  }
  else{
    curr->next->prev=curr->prev;
  }
  curr->next=NULL;
  curr->prev=NULL;
  size--;
  return curr;
}
//returns object from front of a linked list
template <typename T>
T DoublyLinkedList<T>::returnFront(){
  ListNode<T> *curr=front;
  T answer=curr->data;
  return answer;
}
