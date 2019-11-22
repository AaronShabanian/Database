#include <iostream>
using namespace std;
class Student{
public:
  Student();
  Student(int id);
  Student(int id, string name, string standing,string major, double gpa, int advisor );
  ~Student();
  //vars
  int studentid;
  string studentName;
  string studentStanding;
  string major1;
  double gpa1;
  int advisor1;
  //various getter methods
  int getStudentid();
  string getStudentName();
  void changeAdvisor(int id);
  string getStanding();
  string getMajor();
  double getGPA();
  int getAdvisor();
  //used for overloading the operators to compare ids
  friend bool operator< (const Student &c1, const Student &c2);
  friend bool operator!= (const Student &c1, const Student &c2);
  friend bool operator> (const Student &c1, const Student &c2);
};
