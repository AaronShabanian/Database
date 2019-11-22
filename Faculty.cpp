#include <iostream>
using namespace std;
#include "Faculty.h"
Faculty::Faculty(){

}
Faculty::Faculty(int id){
  instructorId=id;
}
Faculty::Faculty(int id, string name, string level, string department){
  instructorId=id;
  facultyName=name;
  level1=level;
  department1=department;
}
Faculty::~Faculty(){
}
int Faculty::getInstructorId(){
  return instructorId;
}
int Faculty::getAdviseSize(){
  return list.getSize();
}
string Faculty::getLevel(){
  return level1;
}
void Faculty::assignStudent(int id){
  //students=id;
  list.insertFront(id);
}
void Faculty::printLists(){
  list.printList();
}
void Faculty::remove(int id){
  list.remove(id);
}
void Faculty::resetCounter(){
  counter=0;
}
int Faculty::giveListElemenet(){
  answer=list.printElement(counter);
  counter++;
  return answer;
}
string Faculty::getName(){
  return facultyName;
}
string Faculty::getDepartment(){
  return department1;
}
//overloads the operators to compare ids of each object
bool operator <(const Faculty &c1, const Faculty &c2){
  if(c1.instructorId<c2.instructorId){
    return true;
  }
  else{
    return false;
  }
}
bool operator >(const Faculty &c1, const Faculty &c2){
  if(c1.instructorId>c2.instructorId){
      return true;
  }
  else{
    return false;
  }
}
bool operator !=(const Faculty &c1, const Faculty &c2){
  if(c1.instructorId!=c2.instructorId){
    return true;
  }
  else{
    return false;
  }
}
