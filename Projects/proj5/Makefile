CFLAGS = -ansi -Wall

my_array_driver: my_array.o my_array_driver.o
	g++ $(CFLAGS) my_array.o my_array_driver.o -o my_array_driver
my_array.o: my_array.cpp my_array.h
	g++ $(CFLAGS) -c my_array.cpp
my_array_driver.o: my_array_driver.cpp my_array.cpp my_array.h
	g++ $(CFLAGS) -c my_array_driver.cpp

###################################################

myTest: sorted.o iterator_ex.o mytest.o
	g++ $(CFLAGS) sorted.o iterator_ex.o mytest.o -o myTest
sorted.o: sorted.cpp sorted.h iterator_ex.cpp iterator_ex.h
	g++ $(CFLAGS) -c sorted.cpp
mytest.o: mytest.cpp sorted.h sorted.cpp
	g++ $(CFLAGS) -c mytest.cpp
iterator_ex.o: iterator_ex.cpp iterator_ex.h
	g++ $(CFLAGS) -c iterator_ex.cpp

###################################################

PHONY: clean

clean:
	rm -f *# *~ 