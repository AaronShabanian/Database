#include <iostream>
#include "Student.h"
using namespace std;
Student::Student(){

}
Student::Student(int id){
  studentid=id;
}
Student::Student(int id, string name, string standing,string major, double gpa, int advisor){
  studentid=id;
  studentName=name;
  studentStanding=standing;
  major1=major;
  gpa1=gpa;
  advisor1=advisor;

}
Student::~Student(){

}
int Student::getStudentid(){
  return studentid;
}
string Student::getStudentName(){
  return studentName;
}
string Student::getStanding(){
  return studentStanding;
}
string Student::getMajor(){
  return major1;
}
double Student::getGPA(){
  return gpa1;
}
int Student::getAdvisor(){
  return advisor1;
}
bool operator <(const Student &c1, const Student &c2){
  if(c1.studentid<c2.studentid){
    return true;
  }
  else{
    return false;
  }
}
bool operator >(const Student &c1, const Student &c2){
  if(c1.studentid>c2.studentid){
    return true;
  }
  else{
    return false;
  }
}
bool operator !=(const Student &c1, const Student &c2){
  if(c1.studentid!=c2.studentid){
    return true;
  }
  else{
    return false;
  }
}
