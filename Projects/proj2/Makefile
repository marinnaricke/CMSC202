CPPFLAGS = -ansi -Wall

mytest: mytest.o pokerhand.o card.o
	g++ mytest.o pokerhand.o card.o -o mytest
mytest.o: mytest.cpp pokerhand.h card.h
	g++ -c mytest.cpp
pokerhand.o: pokerhand.cpp pokerhand.h
	g++ -c pokerhand.cpp
card.o: card.cpp card.h
	g++ -c card.cpp