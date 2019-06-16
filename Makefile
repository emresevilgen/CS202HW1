# Title : Homework 1
# Author : Munib Emre Sevilgen
# ID: 21602416
# Section : 1
# Assignment : 1
# Description : makefile


hw1: main.o sorting.o
	g++ main.o sorting.o -o hw1

main.o: main.cpp
	g++ -c main.cpp

sorting.o: sorting.cpp sorting.h
	g++ -c sorting.cpp

clean:
	rm *.o hw1
