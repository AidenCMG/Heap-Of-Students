#include "date.h"
#include "address.h"
#include "student.h"
#include <iostream>
#include <sstream>

Student::Student(){
    studentString = "";
    Date* dob = new Date();
    Date* expectedGrad =  newDate();
    Address* address = Address();
     firstName = "";
     lastName = "";
     credits = 0;
}

Student::~Student(){
    delete dob;
    delete expectedGrad;
    delete address;
}

void Student::init(std::string studentString){
    Student::studentString = studentString;
    std::stringstream ss;
    ss.str(studentString);
    getline(ss,Student::firstName,',');
    getline(ss,Student::lastName,',');
}

void Student::printStudent(){
    std::cout << firstName << " " << lastName << std::endl;
}

std::string Student::getFirstLast(){
    return "";
}