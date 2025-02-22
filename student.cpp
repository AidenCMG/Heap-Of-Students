#include "date.h"
#include "address.h"
#include "student.h"
#include <iostream>
#include <sstream>

Student::Student(){
    studentString = "";
    dob = new Date();
    expectedGrad =  new Date();
    address = new Address();
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

    std::string addressParser[4] = {"", "", "", ""};

    getline(ss,addressParser[0],',');
    getline(ss,addressParser[1],',');
    getline(ss,addressParser[2],',');
    getline(ss,addressParser[3],',');
    address->init(addressParser[0],addressParser[1],addressParser[2],addressParser[3]);

    std::string dateString = "";

    getline(ss,dateString, ',');
    dob->init(dateString);
    getline(ss,dateString,',');
    expectedGrad->init(dateString);

    std::stringstream converter;
    std::string sNum;
    getline(ss,sNum,',');
    converter << sNum;
    converter >> credits;
}

void Student::printStudent(){
    std::cout << firstName << " " << lastName << std::endl;
    address->printAddress();
    std::cout << "DOB: ";
    dob->printDate();
    std::cout << "Grad: ";
    expectedGrad->printDate();
    std::cout << "Credits: " << credits << std::endl;
}

std::string Student::getlastFirst(){
    return lastName + ", " + firstName;
}