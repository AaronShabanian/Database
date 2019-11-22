#include <iostream>
using namespace std;
template <typename T> class GenStack
{
public:
  GenStack();//constructor
  GenStack(int maxSize);//overloaded constructor
  ~GenStack();//desructor
  //pushes to stack
  void push(T d);
  //pops from stack
  T pop();
  //shows top value
  T peek();
  //checks if full
  bool isFull();
  //checks if empty
  bool isEmpty();
  int size;
  int top;
  T *myArray;
  T *myArray2;
  //Returns true if stack constains value that user puts, didn't end up using it
  bool contains(T d);
  //Doubles stack size
  void makeBigger();
};
template <typename T>
GenStack<T>::GenStack()//default constructor
{

  myArray=new T[128];
  size=5;
  top=-1;
}
template <typename T>
GenStack<T>::GenStack(int maxSize){
  myArray= new T[maxSize];
  size=maxSize;
  top = -1;
}
template <typename T>
GenStack<T>::~GenStack()
{
  delete myArray;
}
template <typename T>
void GenStack<T>::push(T d){
  myArray[++top]=d;
}
template <typename T>
T GenStack<T>::pop(){
  return myArray[top--];
}
template <typename T>
T GenStack<T>::peek(){
  return myArray[top];
}
template <typename T>
bool GenStack<T>::isFull()
{
  return(top==size-1);
}
template <typename T>
//Checks if the stack contains a value, Used it originally but didn't end up using it
bool GenStack<T>::contains(T d)
{
  for(int i=0; i<size; i++){
    if(d==myArray[i]){
    cout<<"true"<<endl;
    return true;
    }
  }
  return false;
}
template <typename T>
void GenStack<T>::makeBigger(){
  myArray2=new T[size*2];
  size=size*2;
  for(int i=0; i<size;i++){
    myArray2[i]=myArray[i];
  }
  myArray=myArray2;
}
template <typename T>
bool GenStack<T>::isEmpty(){
  return(top==-1);
}
