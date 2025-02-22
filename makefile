heapOfStudents: main.o student.o address.o date.o
	g++ -g main.o student.o address.o date.o -o heapOfStudents

address.o: address.cpp address.h
	g++ -g -c address.cpp 

date.o: date.cpp date.h
	g++ -g -c date.cpp

student.o: student.cpp student.h
	g++ -g -c student.cpp 

main.o: main.cpp address.h date.h
	g++ -g -c main.cpp

run: heapOfStudents
	./heapOfStudents

clean:
	rm *.o 
	rm heapOfStudents

debug: heapOfStudents
	gdb ./heapOfStudents

valgrind: heapOfStudents
	valgrind --leak-check=full ./heapOfStudents