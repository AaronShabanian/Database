#include <iostream>
using namespace std;
template <typename T> class TreeNode{
public:
  TreeNode();
  TreeNode(T k);
  ~TreeNode();
  T key;
  TreeNode *left;
  TreeNode *right;
};
template <typename T>
TreeNode<T>::TreeNode(){
  key=NULL;
  left=NULL;
  right=NULL;
}
template <typename T>
TreeNode<T>::TreeNode(T k){
  key=k;
  left=NULL;
  right=NULL;
}
template <typename T>
TreeNode<T>::~TreeNode(){

}
