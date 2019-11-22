#include <iostream>
#include "Runner.h"
using namespace std;
Runner::Runner(){

}
Runner::~Runner(){

}
//un Serializes faculty members by iterating through each line of the file and checking for {}
void Runner::unFacultySerialize(){
  readfile2.open("facultyTable.txt");
  if(readfile2.is_open()){
    int len=0;
    int id=0;
    //placeholders holds the string and it is then converted to an int double or copied to another string
    // depending on the counter
    string placeholders;
    string line;
    string name;
    string level;
    string department;
    int counter=0;
    while(getline(readfile2, line)){
      len=line.length();
      counter=0;
      for(int i=0; i<len; i++){
        if(line[i]=='{'){
          i++;
          while(line[i]!='}'){
            placeholders+=line[i];
            i++;
          }
          if(line[i]=='}'){
            //checks to see what placeholders is in this current instance
            if(counter==0){
              stringstream place(placeholders);
              place>>id;
            }
            if(counter==1){
              name=placeholders;
            }
            if(counter==2){
              level=placeholders;
            }
            if(counter==3){
              department=placeholders;
            }
            placeholders="";
            counter++;
          }
        }
      }
      //creates faculty object and inserts it into the tree
      Faculty faculty(id,name,level,department);
      facultyTree.insert(faculty);
  }
  cout<<"Faculty members added"<<endl;
}
else{
  cout<<"No Faculty members to add";
}
}
//this is mostly the same as unFacultySerialize just uses different variables
void Runner::unStudentSerialize(){
  string placeholders;
  readfile.open("studentTable.txt");
  if(readfile.is_open()){
    string line;
    string len;
    int id;
    string placeholders;
    int counter;
    string name;
    string standing;
    string major;
    double gpa;
    int advisor;
    while(getline(readfile, line)){
      len=line.length();
      counter=0;
      for(int i=0; i<line.length(); i++){
          if(line[i]=='{'){
            i++;
            while(line[i]!='}'){
              placeholders+=line[i];
              i++;
            }
            if(line[i]=='}'){
              if(counter==0){
                stringstream place(placeholders);
                place>>id;
              }
              else if(counter==1){
                name=placeholders;
              }
              else if(counter==2){
                standing=placeholders;
              }
              else if(counter==3){
                major=placeholders;
              }
              else if(counter==4){
                gpa= atof(placeholders.c_str());
              }
              else if(counter==5){
                stringstream place(placeholders);
                place>>advisor;
              }
              placeholders="";
              counter++;
            }
          }
      }
      Faculty faculty(advisor);
      if(facultyTree.search(faculty)==true){
        facultyTree.values->assignStudent(id);
      }
      Student student(id,name,standing,major,gpa,advisor);
      studentTree.insert(student);
    }
    cout<<"Students have been successfully added"<<endl;
  }
  else{
    cout<<"No students to add"<<endl;
  }
}
//uses a recursive function to print each students elements to the studentTable
void Runner::recStudentSerialize(TreeNode<Student> *node){
  if(node==NULL){
    return;
  }
  recStudentSerialize(node->left);
  myfile<<"{"<<node->key.getStudentid()<<"}";
  myfile<<"{"<<node->key.getStudentName()<<"}";
  myfile<<"{"<<node->key.getStanding()<<"}";
  myfile<<"{"<<node->key.getMajor()<<"}";
  myfile<<"{"<<node->key.getAdvisor()<<"}";
  myfile<<"{"<<node->key.getGPA()<<"}"<<endl;
  recStudentSerialize(node->right);
}
void Runner::StudentSerialize(){
  myfile.open ("studentTable.txt");
  recStudentSerialize(studentTree.root);
  myfile.close();
}
//uses a recursive function to write out each faculty member to facultyTable
void Runner::FacultySerialize(){
  myfile2.open("facultyTable.txt");
  recFacultySerialize(facultyTree.root);
}
void Runner::recFacultySerialize(TreeNode<Faculty> *snode){
  if(snode==NULL){
    return;
  }

  recFacultySerialize(snode->left);
  myfile2<<"{"<<snode->key.getInstructorId()<<"}";
  myfile2<<"{"<<snode->key.getName()<<"}";
  myfile2<<"{"<<snode->key.getLevel()<<"}";
  myfile2<<"{"<<snode->key.getDepartment()<<"}"<<endl;
  recFacultySerialize(snode->right);
}
void Runner::chooseAction(){
  //unSerializes
  unFacultySerialize();
  unStudentSerialize();
  //Used 4 boolean stack to determine the last action that was completed
  typedef GenStack<bool> types;
  types t(10);
  typedef GenStack<bool> add;
  add a(10);
  typedef GenStack<bool> addFac;
  add fac(10);
  typedef GenStack<bool> delFac;
  add delfac(10);
  //used stacks that hold ids so the program knows what to delete or add
  typedef GenStack<int> identifier;
  identifier idz(10);
  typedef GenStack<int> identifiers;
  identifiers idzz(10);
  typedef GenStack<int> FacIdentifiers;
  FacIdentifiers facIdz(10);
  //Holds stack of students or faculty that have been deleted incase they want to be added back in Rollback
  typedef GenStack<Student> StudentStacks;
  StudentStacks studentstacks(10);
  typedef GenStack<Faculty> FacultyStacks;
  FacultyStacks facultystacks(10);
  Faculty facultys(2);
  //varibles that are used at various times
  int recall=-1;
  int idQuery=0;
  int idQuery2=0;
  int studentId=0;
  int id10=0;
  int id11=0;
  string studentName;
  string major;
  string standing;
  double gpa=0;
  int choice=0;
  int advisorId=0;
  while (true){
    choice=0;
    cout<<endl;
    cout<<"1. Print all students and their information"<<endl;
    cout<<"2. Print all faculty and their information "<<endl;
    cout<<"3. Find and display student information providing the students id "<<endl;
    cout<<"4. Find and display faculty information providing the faculty id"<<endl;
    cout<<"5. Providing a student’s id, print the name and info of their faculty advisor"<<endl;
    cout<<"6. Providing a faculty id, print ALL the names and info of his/her advisees."<<endl;
    cout<<"7. Add a new student"<<endl;
    cout<<"8. Delete a student by entering the id"<<endl;
    cout<<"9. Add a new faculty member"<<endl;
    cout<<"10. Delete a faculty member by entering id number"<<endl;
    cout<<"11. Change a student’s advisor given the student id and the new faculty id."<<endl;
    cout<<"12.Remove an advisee from a faculty member providing the ids"<<endl;
    cout<<"13. Rollback"<<endl;
    cout<<"14. Exit"<<endl<<endl;
    cout<<"Enter the number corresponding to the action you would like to complete (1-14)"<<endl;
    cin>>choice;

    if(choice==1){
      printStudents();
    }

    else if (choice ==2){
      printFacultys();
    }

    else if(choice ==3){
      cout<<"Enter Student ID #"<<endl;
      cin>>idQuery;
      findStudent(idQuery);//update
    }

    else if(choice ==4){
      cout<<"Enter Faculty ID #"<<endl;
      cin>>idQuery;
      findFaculty(idQuery);//update
    }

    else if(choice ==5){
      cout<<"Enter Student ID #"<<endl;
      cin>>idQuery;
      findStudentAdvisor(idQuery);//update
    }

    else if(choice ==6){
      cout<<"Enter Faculty ID #"<<endl;
      cin>>idQuery;
      findFacultyAdvisee(idQuery);//update
    }

    else if(choice ==7){
      //pushes to various stacks to know what to Rollback if the user requests
      a.push(false);
      t.push(true);
      fac.push(false);
      delfac.push(false);
      cout<<"Enter Student ID"<<endl;
      cin>>studentId;

      //to make sure that the input is actually a number
      while(!cin)
        {
          cout<<"It must be an integer. Try again"<<endl;
          cin.clear();
          cin.ignore();
          cin >> studentId;
        }
        idz.push(studentId);

      cout<<"Enter student Name"<<endl;
      cin.ignore(256, '\n');
      getline(cin, studentName, '\n');
      cout<<"Enter student standing(freshman, sophomore, junior, senior)"<<endl;
      getline(cin, standing, '\n');
      cout<<"Enter student major"<<endl;
      getline(cin, major, '\n');
      cout<<"Enter students gpa"<<endl;
      cin>>gpa;
      while(!cin)
        {
          cout<<"It must be a number. Try again"<<endl;
          cin.clear();
          cin.ignore();
          cin >> gpa;
        }
      Faculty faculty(advisorId);
      while(true){
        cout<<"Enter advisors id"<<endl;
        cin>>advisorId;
        Faculty faculty(advisorId);
        if(facultyTree.search(faculty)==true){
          idz.push(faculty.getInstructorId());
          break;
        }
        cout<<"Faculty member does not exist"<<endl;
      }
      //assigns student to a faculty member that they want to be assigned too
      facultyTree.values->assignStudent(studentId);
      while(!cin)
        {
          cout<<"It must be a number. Try again"<<endl;
          cin.clear();
          cin.ignore();
          cin >> advisorId;
        }
      Student student(studentId,studentName,standing,major,gpa,advisorId);
      addStudent(student);//update
    }

    else if(choice ==8){
      //pushes to boolean stack so Rollaback can do the correct action of the user requests
      delfac.push(false);
      fac.push(false);
      a.push(true);
      t.push(false);
      cout<<"Enter Student ID #"<<endl;
      cin>>idQuery;
      idzz.push(idQuery);
      deleteStudent(idQuery);
      Student student=*studentTree.values;
      //pushes student that is going to be deleted to a stack so it can be re added
      studentstacks.push(student);
    }

    else if (choice ==9){
      fac.push(true);
      a.push(false);
      t.push(false);
      delfac.push(false);
      cout<<"Enter Faculty ID"<<endl;
      cin>>studentId;
      facIdz.push(studentId);

      while(!cin)
        {
          cout<<"It must be a number. Try again"<<endl;
          cin.clear();
          cin.ignore();
          cin >> studentId;
        }

      cout<<"Enter Faculty Name"<<endl;
      cin.ignore(256, '\n');
      getline(cin, studentName, '\n');
      cout<<"Enter faculty position"<<endl;
      getline(cin, standing, '\n');
      cout<<"Enter faculty department"<<endl;
      getline(cin, major, '\n');
      Faculty faculty(studentId,studentName,standing,major);
      addFaculty(faculty);
    }

    else if (choice ==10){
      delfac.push(true);
      fac.push(false);
      t.push(false);
      a.push(false);
      cout<<"Enter Faculty ID #"<<endl;
      cin>>idQuery;
      facIdz.push(idQuery);
      deleteFaculty(idQuery);
      //pushes student that is going to be deleted to a stack so it can be re added
      Faculty faculty=*facultyTree.values;
      facultystacks.push(faculty);
    }

    else if (choice ==11){
      cout<<"Enter Student ID #"<<endl;
      cin>>idQuery;
      cout<<"Enter Faculty ID #"<<endl;
      cin>>idQuery2;
      changeAdvisor(idQuery,idQuery2);
    }

    else if (choice ==12){
      cout<<"Enter Student ID #"<<endl;
      cin>>idQuery;
      cout<<"Enter Faculty ID #"<<endl;
      cin>>idQuery2;
      removeAdvisee(idQuery,idQuery2);
    }

    else if (choice ==13){
      if(!a.isEmpty()){
        cout<<"Processing....(ignore any text until a success message is seen)"<<endl<<endl;
        //delete student already fixes the linkedList maintaining structural integrity
        if(t.pop()==true){
            id11=idz.pop();
            id10=idz.pop();
            deleteStudent(id10);

          }


        //used for structural integrity to add a student back to a linked list based off of a boolean based stack and idz
        //from an int stack
        if(a.pop()==true){

          id10=idzz.pop();
          findStudent(id10);
          findFaculty((studentTree.values)->getAdvisor());
          addStudent(studentstacks.pop());
          facultyTree.values->assignStudent(id10);

        }
        //if last action was deleteing a faculty member it will add it back based off of what was in the FacIdz stack
        //and what was  in the boolean stacks
        if(delfac.pop()==true){

          id10=facIdz.pop();
          findFaculty(id10);
          addFaculty(facultystacks.pop());

        }
        //if last action was adding a faculty member it will delete it
        if(fac.pop()==true){

          id10=facIdz.pop();
          deleteFaculty(id10);

        }
        cout<<endl;
        cout<<"Successfully undid last change"<<endl;
      }
      else{
        cout<<endl;
        cout<<"Nothing to Rollback at this time"<<endl;
      }
    }
    else if (choice==14){

     StudentSerialize();
     FacultySerialize();
      exit(0);

    }
  }
}
//This prints all students
void Runner::printStudents(){

  studentPrintTree();
}
//This prints one individual student
void Runner::printStudent(Student student){

  cout<<"ID: "<<student.getStudentid()<<" ";
  cout<<"   Name: "<<student.getStudentName()<<" ";
  cout<<"   Major: "<<student.getMajor()<<" ";
   cout<<"   Class standing: "<<student.getStanding()<<" ";
   cout<<"   Advisor ID: "<<student.getAdvisor()<<" ";
   cout<<"   GPA: "<<student.getGPA()<<endl;
}
//Overridden print from BST class to be allowed to print Faculty Members rather than integers both printFacultys() and
//FacultyRecPrint;
void Runner::printFacultys(){
  FacultyRecPrint(facultyTree.root);
}
void Runner::FacultyRecPrint(TreeNode<Faculty> *node){

  if(node==NULL){
    return;
  }

  FacultyRecPrint(node->left);
  cout<<"ID: "<<(node->key).getInstructorId()<<" ";
  cout<<"   Name: "<<(node->key).getName()<<" ";
  cout<<"   Position: "<<(node->key).getLevel()<<" ";
  cout<<"   Department: "<<(node->key).getDepartment();
  cout<<"   Students: ";
  (node->key).printLists();
  cout<<endl;
  FacultyRecPrint(node->right);
}
void Runner::printFaculty(Faculty faculty){

  cout<<"ID: "<<faculty.getInstructorId()<<" ";
  cout<<"   Name: "<<faculty.getName()<<" ";
  cout<<"   Position: "<<faculty.getLevel()<<" ";
  cout<<"   Department: "<<faculty.getDepartment();
  cout<<"   Students: ";
  faculty.printLists();
  cout<<endl;
}
//prints student given id
void Runner::findStudent(int id){

  Student student(id);
  if(studentTree.search(student)==true){
    Student students = *studentTree.values;
    printStudent(students);
  }
  else{
    cout<<"Student could not be found"<<endl;
  }

}
//prints faculty member given id
void Runner::findFaculty(int id){

  Faculty faculty(id);
  if(facultyTree.search(faculty)==true){
    Faculty faculty=*facultyTree.values;
    printFaculty(faculty);
  }
  else{
    cout<<"Faculty member could not be found"<<endl;
  }
}
//prints faculty member of student given student id
void Runner::findStudentAdvisor(int id){

  int facID=0;
  Student student(id);
  if(studentTree.search(student)==true){
    Student students=*studentTree.values;
    facID=students.getAdvisor();
    findFaculty(facID);
  }
  else{
    cout<<"Student could not be found"<<endl;
  }

}
//prints student linked list given faculty id number
void Runner::findFacultyAdvisee(int id){

  Faculty faculty(id);
  if(facultyTree.search(faculty)==true){
    Faculty faculty=*facultyTree.values;
    int counters=0;
    faculty.resetCounter();
    while(counters<faculty.getAdviseSize()){
      findStudent(faculty.giveListElemenet());
      counters++;
    }
  }
  else{
    cout<<"Faculty member could not be found"<<endl;
  }

}
//adds student
void Runner::addStudent(Student student){

  studentTree.insert(student);
}
//searches for student then deletes it
void Runner::deleteStudent(int id){

  Student student(id);
  if(studentTree.search(student)==true){
    Student students = *studentTree.values;
    removeAdvisee(students.getStudentid(),students.getAdvisor());
    studentTree.deleteNode(students);
    cout<<"Student deleted successfully"<<endl;
  }
  else{
    cout<<"Student could not be found"<<endl;

  }
}
//adds faculty member
void Runner::addFaculty(Faculty faculty){

  facultyTree.insert(faculty);

}
//deletes faculty member
void Runner::deleteFaculty(int id){

  Faculty faculty(id);
  int id1;
  int size=0;
  int element=0;
  int counter=0;

  if(facultyTree.search(faculty)==true){

    Faculty facultys=*facultyTree.values;

    if(facultys.getAdviseSize()>0){

      cout<<"Where would you like to assign the faculty members advisees (Enter a different faculty members ID) "<<endl;
      cin>>id1;
      Faculty facultyss(id1);
      size=facultys.getAdviseSize();

      if(facultyTree.search(facultyss)==true){

          Faculty facultysss=*facultyTree.values;
          facultys.resetCounter();

          while(counter<size){

            element=facultys.giveListElemenet();
            facultyTree.values->assignStudent(element);
            Student student(element);
           if(studentTree.search(student)==true){

             studentTree.values->changeAdvisor(id1);

           }
            counter++;
          }
      }
    }
    facultyTree.deleteNode(facultys);
    cout<<"Faculty member deleted successfully"<<endl;
  }
  else{
    cout<<"Faculty member could not be found"<<endl;
  }
}
//changes advisor given student id and new faculty id
void Runner::changeAdvisor(int studentId, int facultyId){
  Faculty facultys(facultyId);
  Student student(studentId);
  int oldId=0;
  //finds faculty member from id and finds student and finds student old faculty member
  if(facultyTree.search(facultys)==true){

    if(studentTree.search(student)==true){

      facultyTree.values->assignStudent(studentId);
      oldId=studentTree.values->getAdvisor();
      studentTree.values->changeAdvisor(facultyId);
      removeAdvisee(studentId,oldId);
    }
    else{
      cout<<"Student could not be found"<<endl;
    }
  }
  else{
    cout<<"Faculty member does not exist"<<endl;
  }
}
//removes advisee given to studentId and facultyId
void Runner::removeAdvisee(int studentId, int facultyId){
  if(facultyTree.search(facultyId)==true){

  //  Faculty faculty=*facultyTree.values;
    if(studentTree.search(studentId)==true){
      facultyTree.values->remove(studentId);
    }
    else{
      cout<<"Student does not exist"<<endl;
    }
  }
  else{
    cout<<"Faculty member does not exist"<<endl;
  }
}
//overloaded printing from BST class so I can print student information
void Runner::studentRecPrint(TreeNode<Student> *node){
  if(node==NULL){
    return;
  }

  studentRecPrint(node->left);
  cout<<"ID: "<<(node->key).getStudentid()<<" ";
  cout<<"   Name: "<<(node->key).getStudentName()<<" ";
  cout<<"   Major: "<<(node->key).getMajor()<<" ";
  cout<<"   Class standing: "<<(node->key).getStanding()<<" ";
  cout<<"   Advisor ID: "<<(node->key).getAdvisor()<<" ";
  cout<<"   GPA: "<<(node->key).getGPA()<<endl;
  studentRecPrint(node->right);
}

void Runner::studentPrintTree(){
  studentRecPrint(studentTree.root);
}
