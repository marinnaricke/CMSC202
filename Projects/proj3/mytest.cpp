// File:    mytest.cpp
// Project: CMSC 202 Project 3, Spring 2016
// Author:  Marinna Ricketts-Uy
// Date:    3/31/16
// Section: 17
// E-mail:  pd12778@umbc.edu
//
// This file exercises the working parts of my submission, and uses the Train
//  class, the Time class and the TrainCar class

#include <iostream>
using namespace std;


#include "Train.h"
#include "TrainStation.h"

int main() 
{

  // *** Using the TrainCar Class ***
  // Creating TrainCar objects
  cout << "\nTesting with TrainCar Class " << endl;
  cout << "----------------------------------------" << endl;
  TrainCar car0(TrainCar::Locomotive);
  TrainCar car1(TrainCar::CoachClass);
  TrainCar car2(TrainCar::BusinessClass);
  TrainCar car3(TrainCar::DiningCar);
  TrainCar car4(TrainCar::SnackCar);
  TrainCar car5(TrainCar::SleepingCar);

  // Printing a character graphic representation of a train car
  // Uses the overloaded insertion operator from TrainCar.cpp
  cout << "Printing out the individual TrainCar Graphics: " << endl;
  cout << car0 << endl;
  cout << car1 << endl;
  cout << car2 << endl;
  cout << car3 << endl;
  cout << car4 << endl;
  cout << car5 << endl;

  // *** Using the Train Class ***
  // Creating a Train object
  cout << "\nTesting with Train Class " << endl;
  cout << "-------------------------------------" << endl;
  Train* train1 = new Train();

  train1->addCar(TrainCar::Locomotive);  
  train1->addCar(TrainCar::CoachClass);  
  train1->addCar(TrainCar::CoachClass);
  train1->addCar(TrainCar::CoachClass);    

  //train1->addCar(TrainCar::DiningCar);
  //train1->addCar(TrainCar::SleepingCar);
  //train1->addCar(TrainCar::BusinessClass);
  //train1->addCar(TrainCar::SnackCar);

  // Printing a character graphic representation of the train
  // Uses the overloaded insertion operator from Train.cpp
  cout << "Printing out the entire Train: " << endl;
  cout << *train1 << endl;
  
  delete train1;
  train1 = NULL;

  // *** Using the Time Class ***
  //Testing that my time object prints out correctly
  //Overloaded insertion operator<<
  cout << "\nTesting with Time Class " << endl;
  cout << "------------------------------------" << endl;
  cout << "Testing insertion operator for the time: " << endl;
  Time time1(13,59);
  cout << time1 << endl;

  //Testing that minutes can be added to the time object
  //Overloaded operator+
  cout << "Testing the Overloaded operator+: " << endl;
  Time time2(23,00);
  cout << time2 + 120 << endl;

  //Testing the outcome of comparing two Time Objects
  //Overloaded operator<
  cout << "Testing the Overloaded operator<: " << endl;
  Time t0(13,00);
  Time t1(13,25);

  cout << "Expected result: true" << endl;
  bool b = (t0 < t1);
  cout << "Actual result: " << b << endl;

  //*** Using the TrainStationClass ***
  // Testing that the program can use the TrainStationClass
  cout << "\nTesting with TrainStation Class " << endl;
  cout << "--------------------------------------------" << endl;

  Train* ner111 = new Train( 111, Time(13, 25), "Boston" );
  
  ner111->addCar( TrainCar::Locomotive );
  ner111->addCar( TrainCar::CoachClass );
  ner111->addCar( TrainCar::CoachClass );
  ner111->addCar( TrainCar::CoachClass );
  ner111->addCar( TrainCar::BusinessClass );
  ner111->addCar( TrainCar::SnackCar );

  Train *ner531 = new Train( 531, Time(13, 30), "Montreal" );
  
  ner531->addCar( TrainCar::Locomotive );
  ner531->addCar( TrainCar::CoachClass );
  ner531->addCar( TrainCar::CoachClass );
  ner531->addCar( TrainCar::CoachClass );
  ner531->addCar( TrainCar::CoachClass );
  ner531->addCar( TrainCar::SnackCar );
  ner531->addCar( TrainCar::SleepingCar );
  ner531->addCar( TrainCar::SleepingCar );

  Train *ner227 = new Train( 227, Time(13, 40), "Lynchburg");
  
  ner227->addCar( TrainCar::Locomotive );
  ner227->addCar( TrainCar::CoachClass );
  ner227->addCar( TrainCar::CoachClass );
  ner227->addCar( TrainCar::CoachClass );
  ner227->addCar( TrainCar::SnackCar );

  Train *invalid = new Train( 0, Time(13, 50), "Nowhere" );

  invalid->addCar( TrainCar::Locomotive );

  Train *ner032 = new Train( 32, Time(13, 55), "New York" );
  
  ner032->addCar( TrainCar::Locomotive );
  ner032->addCar( TrainCar::CoachClass );
  ner032->addCar( TrainCar::CoachClass );
  ner032->addCar( TrainCar::CoachClass );
  ner032->addCar( TrainCar::SnackCar );

  TrainStation unionStation(4);

  unionStation.addTrain( ner111 );
  unionStation.addTrain( ner531 );
  unionStation.addTrain( ner227 );
  unionStation.addTrain( invalid );
  unionStation.addTrain( ner032);

  unionStation.departureBoard( Time(13, 00), 60 );

  unionStation.departure( ner111 );

  unionStation.addTrain( ner032 );
  
  unionStation.departureBoard( Time(13, 00), 60 );

  unionStation.departure( ner531 );

  unionStation.departureBoard( Time(13, 30), 60 );

  unionStation.departure( invalid );

  unionStation.removeTrain( invalid );

  unionStation.departureBoard( Time(13, 30), 60 );

  return 0;
}
