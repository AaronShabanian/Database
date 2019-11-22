#include <iostream>
using namespace std;
template <typename T> class ListNode
{
public:
  T data;
  ListNode *next;
  ListNode *prev;

  //constructor/destructor
  ListNode();
  ListNode(T d);
  ~ListNode();
};
template <typename T>
ListNode<T>::ListNode(){}
template <typename T>
ListNode<T>::ListNode(T d){
  data =d;
  next=NULL;
  prev=NULL;
}
template <typename T>
ListNode<T>::~ListNode(){

}
