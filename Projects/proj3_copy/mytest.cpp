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
#include "Time.h"
#include "TrainCar.h"

int main() 
{

  // Creating TrainCar objects
  TrainCar car0(TrainCar::Locomotive);
  TrainCar car1(TrainCar::CoachClass);
  TrainCar car2(TrainCar::BusinessClass);
  TrainCar car3(TrainCar::DiningCar);
  TrainCar car4(TrainCar::SnackCar);
  TrainCar car5(TrainCar::SleepingCar);

  // Printing a character graphic representation of a train car
  // Uses the overloaded insertion operator from TrainCar.cpp
  cout << "Printing out the individual TrainCar Graphics" << endl;
  cout << car0 << endl;
  cout << car1 << endl;
  cout << car2 << endl;
  cout << car3 << endl;
  cout << car4 << endl;
  cout << car5 << endl;

  // Creating a Train object
  Train* train1 = new Train();

  train1->addCar(TrainCar::Locomotive);
  train1->addCar(TrainCar::CoachClass);
  train1->addCar(TrainCar::CoachClass);
  train1->addCar(TrainCar::CoachClass);
  train1->addCar(TrainCar::BusinessClass);
  train1->addCar(TrainCar::SnackCar);

  // Printing a character graphic representation of the train
  // Uses the overloaded insertion operator from Train.cpp
  cout << "Printing out the entire Train" << endl;
  cout << *train1 << endl;

  //Testing that my time prints out correctly
  //Overloaded insertion operator<<
  cout << "Testing insertion operator for the time" << endl;
  Time time1(13,59);
  cout << time1 << endl;

  //Testing that minutes can be added to the time object
  //Overloaded operator+
  cout << "Testing the Overloaded operator+" << endl;
  Time time2(23,00);
  cout << time2 + 120 << endl;

  //Testing the outcome of comparing two Time Objects
  //Overloaded operator<
  cout << "Testing the Overloaded operator<" << endl;
  Time t0(13,00);
  Time t1(13,25);

  cout << "Expected result: true" << endl;
  bool b = (t0 < t1);
  cout << "Actual result: " << b << endl;

  return 0;
}
