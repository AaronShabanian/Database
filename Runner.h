#include "Student.h"
#include "Faculty.h"
#include "BST.h"
#include "GenStack.h"
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#define FILE_NAME "studentTable.txt"
class Runner{
public:
  Runner();
  ~Runner();
  ofstream myfile;
  ofstream myfile2;
  ifstream readfile;
  ifstream readfile2;
  Student checker;
  /*unSerializes and inserts nodes back in trees
  serializes by putting all elements in brackets in studentTable and facultyTable
  unserializes by iterating through the string per line */
  void recStudentSerialize(TreeNode<Student> *node);
  void StudentSerialize();
  void unStudentSerialize();
  void recFacultySerialize(TreeNode<Faculty> *node);
  void FacultySerialize();
  void unFacultySerialize();
  /*
   chooseAction() is the main driver method of the program, Its primary use is to get the users input
   and direct them to different functions depending on their choice
   Rollback is also contained in this function and is made with 4 boolean stacks to establish the last action that took place
   , 3 stacks that hold ids and 2 stacks that hold faculty and student objects that were deleted to be added back.
  */
  void chooseAction();
  //prints all students and information
  void studentPrintTree();
  void printStudents();
  void studentRecPrint(TreeNode<Student> *node);
  //prints all Faculty members and information
  void FacultyRecPrint(TreeNode<Faculty> *node);
  void printFacultys();
  //prints individual faculty member and information
  void printFaculty(Faculty faculty);
  //prints individual student member and information
  void printStudent(Student student);
  //finds student based on id# calls BST search
  void findStudent(int id);
  //finds faculty based on id# calls BST search
  void findFaculty(int id);
  //finds student advisor
  void findStudentAdvisor(int id);
  //finds faculty advisee
  void findFacultyAdvisee(int id);
  //adds student
  void addStudent(Student student);
  //delete student
  void deleteStudent(int id);
  //add faculty member
  void addFaculty(Faculty faculty);
  //deletes faculty member
  void deleteFaculty(int id);
  //changes students avisor which uses other methods that have been created
  void changeAdvisor(int studentId, int facultyId);
  //removes advisee from linked list
  void removeAdvisee(int studentId, int facultyId);
  //instantiating student tree and faculty tree
  typedef BST<Student> Tree;
  Tree studentTree;
  typedef BST<Faculty> Tree1;
  Tree1 facultyTree;

};
