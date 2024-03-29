#include <iostream>
#include "DoublyLinkedList.h"
using namespace std;
class Faculty{
public:
  Faculty();
  Faculty(int id);
  Faculty(int id, string name, string level, string department);
  ~Faculty();
  int instructorId;
  string facultyName;
  string level1;
  string department1;
  int getInstructorId();
  string getName();
  string getLevel();
  string getDepartment();
  void printLists();
  int giveListElemenet();
  int getAdviseSize();
  void resetCounter();
  int answer=0;
  int counter=0;
  void remove(int id);
  //int students;
  void assignStudent(int id);
  typedef DoublyLinkedList<int> List;
  List list;
  friend bool operator< (const Faculty &c1, const Faculty &c2);
  friend bool operator> (const Faculty &c1, const Faculty &c2);
  friend bool operator!= (const Faculty &c1, const Faculty &c2);
};
