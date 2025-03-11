# Heap-Of-Students  


This project takes in a csv of student data and parses it to be easily sortable by different categories.


Here is the general algorithm for the init method of the Date class:
```
init(dateString):
    Create a stringstream from dateString
    string strDay = "";
    string strMonth = "";
    string strYear = "";
    stringstream converter;
    
    Read month from stringstream up to the first '/' and assign it to strMonth
    converter << strMonth;
    converter >> month;

    Clear converter (reset its state)
    
    Read day from stringstream up to the next '/' and assign it to strDay
    Convert strDay to an integer and assign it to day

    Clear converter (reset its state)

    Read year from stringstream up to the next '/' and assign it to strYear
    Convert strYear to an integer and assign it to year
```
The purpose of the init is to convert the values into ints so they can be compared if needed.

Algorithm for the student init:
```
init(studentString):
    Set studentString to the input studentString
    Create a new stringstream from studentString
    
    Read firstName from stringstream up to the first comma
    Read lastName from stringstream up to the next comma
    
    array addressParser[4] = empty;

    Read and store the address parts (street, city, state, zip) from stringstream into addressParser

    Call address.init() with the parsed address parts (street, city, state, zip)

    Read the date of birth (dob) string from stringstream up to the next comma
    Call dob.init() with the dob string

    Read the expected graduation date string from stringstream up to the next comma
    Call expectedGrad.init() with the expected graduation date string

    Read the credits string from stringstream up to the next comma
    Convert the credits string to an integer and assign it to the credits member
```
 This init parses a string containing all the students info and places them into the appropriate areas.

 The following is the algorithm for main:
 ```
 function main():
    vector<Student> students
    keepGoing = True
    map 0-4 to the corresponding functions
    while(keepGoing):
        selection = menu()
        if selection = "0":
        keepGoing = false
        else if selection in map:
            call function at selection
    delStudents()
    

choice = input()
for length of map:
    if choice == mapKey:

function loadStudents(vector& studentVector):
    open students.csv
    while(inFile):
        create student
        read line and send string to student object
        place student in vector

function delStudents(vector& studentVector)
    for student in students:
        delete object from heap at position student

function menu():
    print("0) quit")
    print("1) print all student names")
    print("2) print all student data")
    print("3) find a student")
    selection = input("Choose 0-3")
    return selection
```