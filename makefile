heapOfStudents: main.o student.o address.o date.o
	g++ main.o student.o address.o date.o -o horseRace

address.o: address.cpp address.h
	g++ -c address.cpp 

date.o: date.cpp date.h
	g++ -c date.cpp

student.o: student.cpp student.h
	g++ -c student.cpp 

main.o: main.cpp address.h date.h
	g++ -c main.cpp