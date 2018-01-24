// File:    TrainCar.cpp
// Project: CMSC 202 Project 3, Spring 2016
// Author:  Marinna Ricketts-Uy 
// Date:    3/31/16
// Section: 17
// E-mail:  pd12778@umbc.edu
//
// CMSC 202 Project file
//
// COMPLETE THE IMPLEMENTATION AS INSTRUCTED
//

#include <iostream>
using namespace std;

#include "TrainCar.h"

// Default Constructor
TrainCar::TrainCar() : m_next( NULL ), m_type( NoType )
{ /* empty constructor body */ }

// Alternate Constructor
TrainCar::TrainCar( TrainCar::cType car ) : m_next( NULL ), m_type( car )
{ /* empty constructor body */ }

// setType
// Sets the m_type of the TrainCar
void TrainCar::setType( TrainCar::cType car ) 
{
  m_type = car;
}

// getType
// Gets the m_type of the TrainCar
TrainCar::cType TrainCar::getType() const {
  return m_type;
}

//
// IMPLEMENT THE OVERLOADED INSERTION OPERATOR
//

// operator<<
// Overloaded insertion operator to print out a
//  character graphic for each TrainCar
ostream& operator<<(ostream &outStream, const TrainCar& car)
{
  switch (car.getType())
    {
    case 0:
      outStream << "// Locomotive ]]";
      break;
    case 1:
      outStream << "[ oo Coach oo ]";
      break;
    case 2:
      outStream << "[ Business ]";
      break;
    case 3:
      outStream << "[ - Dining - ]";
      break;
    case 4:
      outStream << "[ -- Snack -- ]";
      break;
    case 5:
      outStream << "[ o Sleeper o ]";
      break;
    default:
      outStream << "";
      break;
    }
  
  return outStream;
}
