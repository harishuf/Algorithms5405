CC=g++
#CFLAGS=-c -g
CFLAGS=-c -O3

all:Skyscraper
Skyscraper: main.o task1.o utility.o task2.o task3.o task4.o
	${CC} main.o task1.o task2.o utility.o task3.o task4.o -o Skyscraper
main.o: main.cpp task1.hpp
	${CC} ${CFLAGS} main.cpp 
task1.o: task1.cpp task1.hpp
	${CC} ${CFLAGS} task1.cpp
task2.o: task2.cpp task2.hpp
	${CC} ${CFLAGS} task2.cpp
task3.o: task3.cpp task3.hpp
	${CC} ${CFLAGS} task3.cpp
task4.o: task4.cpp task4.hpp
	${CC} ${CFLAGS} task4.cpp
utility.o: utility.cpp utility.hpp
	${CC} ${CFLAGS} utility.cpp

clean:
	rm *.o Skyscraper
