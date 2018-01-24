// File:    Train.h
// Project: CMSC 202 Project 3, Spring 2016
// Author:  Marinna Ricketts-Uy
// Date:    3/31/16
// Section: 17 
// E-mail:  pd12778@umbc.edu
//
// CMSC 202 Project File
//
// YOU MAY *ONLY* ADD PRIVATE HELPER FUNCTIONS
//


#ifndef TRAIN_H
#define TRAIN_H

#include "TrainCar.h"
#include "Time.h"

#include <iostream>
using namespace std;

class Train {
 public:

  // Constructors; see implementations in Train.cpp
  Train();
  Train( int num, Time dep, string dest );

  // Destructor needed to destroy linked list
  ~Train();

  // Add a car to the train.
  //
  // A train must have at least one locomotive and one coach car.
  // All other car types are optional.  See the TrainCar class for
  // definitions of the car types.
  //
  // addCar() must place cars in correct order within the linked list:
  // 
  //    1. Locomotive(s) - 1st non-dummy node(s)
  //    2. Business Class
  //    3. Coach
  //    4. Sleeping Cars
  //
  //    Snack Car 
  //       a. If the train has both Business Class and Coach, the Snack Car
  //          must be placed between coach and business.
  //       b. If the train has no Business Class, then the Snack Car must
  //          be placed in the middle of the Coach cars; if there is an 
  //          odd number of Coach cars, it should be placed closer to the
  //          locomotive.
  //
  //    Dining Car
  //       a. A train has a Dining Car if and only if it has one or more
  //          sleeping cars.  The Dining Car should be placed between the
  //          coach cars and the sleeping cars.
  //
  void addCar( TrainCar::cType car );

  // Remove a car from the train
  // 
  // removeCar() must keep the cars in the correct order / position
  // within the train.  Return true if successful; false if there is
  // no car of the specified type in the train.
  bool removeCar( TrainCar::cType car );

  // Name: getNumber
  // PreCondition:  None
  // PostCondition: Returns the train number 
  int getNumber() const;

  // Name: setNumber
  // PreCondition:  None
  // PostCondition: Sets the train number
  void setNumber( int num );

  // Name: getDepartureTime
  // PreCondition:  None
  // PostCondition: Returns the departure time object
  Time getDepartureTime() const;

  // Name: setDepartureTime
  // PreCondition:  t is a Time object with hours and minutes
  // PostCondition: Sets the departure time
  void setDepartureTime( const Time& t );

  // Name: getDestination
  // PreCondition: None
  // PostCondition: Returns the destination
  string getDestination() const;

  // Name: setDestination
  // PreCondition:  dest is a string 
  // PostCondition: Sets the train's destination
  void setDestination( string dest );

  // Check that the train is valid; must have at least one
  // locomotive and one CoachClass car, and the first non-dummy node
  // must be a Locomotive.  
  // addCar() and removeCar() should ensure that all cars are in the
  // correct position.

  // Name: isValid
  // PreCondition: None
  // PostCondition: Returns true or false
  bool isValid();

  // Overloaded insertion operator prints a character graphics
  // representation of the train

  // Name: operator<<
  // PreCondition: t is a pointer to a Train
  // PostCondition: Returns an overloaded outStream
  friend ostream& operator<<(ostream &outStream, const Train& t);

 private:
  
  int m_number;               // train number
  Time m_departs;             // departure time
  string m_destination;       // destination
  TrainCar *m_head;           // head of linked list

  // These variables are optional, but will make programming addCar()
  // and removeCar() easier.  

  int m_numCoachClass;        // number of CoachClass cars
  int m_numBusinessClass;     // number of BusinessClass cars
  int m_numSleepingCar;       // number of SleepingCar cars
  bool m_hasSnackCar;         // true if has SnackCar

  //
  // MAY ADD PRIVATE HELPER FUNCTIONS HERE
  //
 
  // Name: getNumCoach
  // PreCondition: None
  // PostCondition: Returns the number of CoachClass TrainCars
  int getNumCoach();

  // Name: getNumBusiness
  // PreCondition: None
  // PostCondition: Returns the number of BusinessClass TrainCars
  int getNumBusiness();

  // Name: getNumSleeping
  // PreCondition: None
  // PostCondtion: Returns the number of SleepingCar TrainCars
  int getNumSleeping();

  // Name: HasSnack
  // PreCondition: None
  // PostCondition: Returns true or false
  bool HasSnack();

};

#endif  
