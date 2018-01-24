CPPFLAGS = -ansi -Wall

station_test: station_test.o TrainStation.o Train.o TrainCar.o Time.o
	g++ $(CPPFLAGS) station_test.o TrainStation.o Train.o Time.o TrainCar.o -o station_test

station_test.o: station_test.cpp TrainStation.cpp TrainStation.h Train.cpp \
	Train.h TrainCar.cpp TrainCar.h Time.cpp Time.h
	g++ $(CPPFLAGS) -c station_test.cpp

TrainStation.o: TrainStation.cpp TrainStation.h Train.cpp Train.h \
	TrainCar.cpp TrainCar.h Time.cpp Time.h
	g++ $(CPPFLAGS) -c TrainStation.cpp

Train.o: Train.cpp Train.h TrainCar.cpp TrainCar.h Time.cpp Time.h
	g++ $(CPPFLAGS) -c Train.cpp

TrainCar.o: TrainCar.cpp TrainCar.h
	g++ $(CPPFLAGS) -c TrainCar.cpp

Time.o: Time.cpp Time.h
	g++ $(CPPFLAGS) -c Time.cpp


make: Makefile
	emacs Makefile

run: station_test
	./station_test
val: station_test
	valgrind station_test

.PHONY: clean
.PHONY: cleaner
.PHONY: cleanest
clean:
	rm -f *~ *#
cleaner: clean
	rm -f *.o
cleanest: cleaner
	rm -f station_test
