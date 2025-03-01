#include <iostream>
#include <fstream>
#include <sstream>
#include "date.h"
#include "address.h"
#include "student.h"
#include <vector>
void loadStudents(std::vector<Student*>& studentsVector);
void delStudents(std::vector<Student*>& studentsVector);
void printStudents(std::vector<Student*>& studentsVector);
void showStudentNames(std::vector<Student*>& studentsVector);
void findStudent(std::vector<Student*>& studentsVector);

int main(){
  std::vector<Student*> students;
  loadStudents(students);
  findStudent(students);
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
}

void showStudentNames(std::vector<Student*>& studentsVector){
  for(int i = 0; i < studentsVector.size(); i++){
    std::cout << studentsVector[i]->getlastFirst();
    std::cout << std::endl;
  }
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
      std::cout << studentsVector[i]->getlastFirst();
    }
    
  }
}
