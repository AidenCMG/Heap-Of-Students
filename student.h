#ifndef STUDENT_H_EXISTS
#define STUDENT_H_EXISTS
#include <string>
class Student{
    protected:
        std::string studentString;
        Date* dob;
        Date* expectedGrad;
        Address* address;
        std::string firstName;
        std::string lastName;
        int credits;
    public:
        Student();
        ~Student();
        void init(std::string studentString);
        void printStudent();
        std::string getlastFirst();
};

#endif