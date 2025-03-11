#include <iostream>
#include <fstream>
#include <sstream>
#include "date.h"
#include "address.h"
#include "student.h"
#include <vector>
#include <map>
void loadStudents(std::vector<Student*>& studentsVector);
void delStudents(std::vector<Student*>& studentsVector);
void printStudents(std::vector<Student*>& studentsVector);
void showStudentNames(std::vector<Student*>& studentsVector);
void findStudent(std::vector<Student*>& studentsVector);
std::string menu();

int main(){
  std::vector<Student*> students;
  loadStudents(students);
  // I wanted to try using a map for the menu option instead of using a series of if's and elses to determine what function to call. 
  std::map<std::string,void(*)(std::vector<Student*>&)> menuChoices = {
    {"1", showStudentNames},
    {"2", printStudents},
    {"3", findStudent}
  };
  bool keepGoing = true;
  while (keepGoing){
    std::string selection = menu();
    //ended up still needing ifs to ensure the selection was valid
    if (selection == "0"){
      keepGoing = false;
    }
    //checks if selection is in map
    else if (menuChoices.find(selection) != menuChoices.end()){
      menuChoices[selection](students);
    }
    else {
      std::cout << "Not a valid option" << std::endl;
    }
  }
  //clean up
  delStudents(students);

  return 0;
} // end main

void loadStudents(std::vector<Student*>& studentsVector){
	std::ifstream inFile;
	std::string currentLine;
	inFile.open("students.csv");
	while(getline(inFile,currentLine)){
		Student* currentStudent = new Student();
		currentStudent->init(currentLine);
		studentsVector.push_back(currentStudent);

	}
}
void delStudents(std::vector<Student*>& studentsVector){
	for( int i = 0; i < studentsVector.size(); i++){
		delete studentsVector[i];  
	}
  studentsVector.clear();
}
void printStudents(std::vector<Student*>& studentsVector){
  for(int i = 0; i < studentsVector.size(); i++){
    studentsVector[i]->printStudent();
    std::cout << std::endl;
  }
  std::cout << std::endl <<"_________________________" << std::endl;
}

void showStudentNames(std::vector<Student*>& studentsVector){
  for(int i = 0; i < studentsVector.size(); i++){
    std::cout << studentsVector[i]->getlastFirst();
    std::cout << std::endl;
  }
  std::cout << std::endl <<"_________________________" << std::endl;
}

void findStudent(std::vector<Student*>& studentsVector){
  std::string searchTerm;
  std::stringstream ss;
  std::string lastName;
  std::cout << "last name of student: ";
  std::cin >> searchTerm;

  for(int i = 0; i < studentsVector.size(); i++){
    ss.clear();
    ss.str(studentsVector[i]->getlastFirst());
    getline(ss,lastName,',');

    if(lastName.find(searchTerm) != std::string::npos){
      studentsVector[i]->printStudent();
      std::cout << std::endl;
      
    }
    
  }
  std::cout << std::endl <<"_________________________" << std::endl;
}

std::string menu(){
  std::cout << "0) quit" << std::endl;
  std::cout << "1) print all student names" << std::endl;
  std::cout << "2) print all student data" << std::endl;
  std::cout << "3) find a student" << std::endl;

  std::cout << "Please choose 0-3: ";
  std::string selection = "";
  std::cin >> selection;
  std::cout << std::endl;
  
  return selection;

}
