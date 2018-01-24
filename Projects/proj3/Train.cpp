// File:    Train.cpp
// Project: CMSC 202 Project 3, Spring 2016
// Author:  Marinna Ricketts-Uy
// Date:    3/31/16
// Section: 17
// Email:   pd12778@umbc.edu
//
// CMSC 202 Project File
//
// TWO CONSTRUCTORS ARE GIVEN.  IMPLEMENT THE REMAINDER OF
// THE CLASS AND THE OVERLOADED INSERTION OPERATOR
//


#include <iostream>
using namespace std;

#include "TrainCar.h"
#include "Train.h"

// Default constructor.  Initialize variables and create dummy node.
Train::Train() : m_number(0), m_departs( Time() ), m_destination ( "" ),
		 m_numCoachClass(0), 
		 m_numBusinessClass(0), m_numSleepingCar(0),
		 m_hasSnackCar(false)

{
  m_head = new TrainCar(); // dummy node
}

// Non-default constructor.  Initialize variables and create dummy node.
Train::Train( int num, Time dep, string dest) 
  : m_number(num), m_departs(dep), m_destination(dest),
    m_numCoachClass(0), 
    m_numBusinessClass(0), m_numSleepingCar(0) ,
    m_hasSnackCar(false)

{
  m_head = new TrainCar(); // dummy node
}

//
// IMPLEMENT THE REMAINDER OF THE CLASS AND THE OVERLOADED
// INSERTION OPERATOR
//

// Destructor needed to destroy linked list
Train::~Train()
{
  TrainCar *current = m_head;
  TrainCar *next;
  
  while (current != NULL)
    {
      next = current->m_next;
      delete current;
      current = next;
    }
}

// addCar 
// Given the cType of the car, returns a boolean
void Train::addCar(TrainCar::cType car)
{
  TrainCar *current = m_head;
  TrainCar *tempCar;
  TrainCar *prev;

  if (car == 0)
    {
      //Locomotive TrainCar goes after the Dummy Node
      if (current->m_next != NULL)
	{
	  tempCar = new TrainCar(car);
	  tempCar->m_next = current->m_next;
	  current->m_next = tempCar;
	  return;
	}
      else 
	{
	  current->m_next = new TrainCar(car);
	  return;
	}
    }
  else if (car == 1)
    {
      // If nothing currently in Train besides m_head/Dummy
      if (current->m_next == NULL)
	{
	  current->m_next = new TrainCar(car);
	  return;
	}

      // If first car after Dummy Node is currently CoachClass
      else if (current->m_next->getType() == 1) 
	{
	  tempCar = new TrainCar(car);
	  tempCar->m_next = current->m_next;
	  current->m_next = tempCar;
	  return;
	}

      // If Train contains a Locomotive TrainCar
      else if (current->m_next->getType() == 0)
	{
	  current = current->m_next;

	  if (getNumBusiness() == 0)
	    {
              // Traverse to the end of all Locomotives
              while (current->m_next != NULL)
                {
                  prev = current;
                  current = current->m_next;
                }

	      //If last TrainCar is a Locomotive
              if (current->getType() == 0)
                {
                  tempCar = new TrainCar(car);
                  tempCar->m_next = current->m_next;
                  current->m_next = tempCar;
                  return;
                }
	      else if (current->getType() == 1)
		{
		  tempCar = new TrainCar(car);
		  tempCar->m_next = current->m_next;
		  current->m_next = tempCar;
		  return;
		}
	    }
	  else
	    {
	      // Traverse to the end of all Business
	      while (current->m_next != NULL)
		{
		  prev = current;
		  current = current->m_next;
		}

	      if (current->getType() == 2)
		{
		  tempCar = new TrainCar(car);
		  tempCar->m_next = current->m_next;
		  current->m_next = tempCar;
		  return;
		}
	      else
		{
		  tempCar = new TrainCar(car);
		  tempCar->m_next = prev->m_next;
		  prev->m_next = tempCar;
		  return;
		}
	    }
	}
    }
  else if (car == 2)
    {
      // If nothing currently in Train besides m_head/Dummy
      if (current->m_next == NULL)
	{
	  current->m_next = new TrainCar(car);
	  return;
	}

      else if(current->m_next->getType() == 2)
	{
	  tempCar = new TrainCar(car);
	  tempCar->m_next = current->m_next;
	  current->m_next = tempCar;
	  return;
	}

      // BusinessClass TrainCar goes after the Locomotive
      else if (current->m_next->getType() == 0)
	{
	  if (current->m_next->m_next->getType() != 0)
	    {
	      current = current->m_next;
	      tempCar = new TrainCar(car);
	      tempCar->m_next = current->m_next;
	      current->m_next = tempCar;
	      return;
	    }
	      
	  // Traverse to the end of all Locomotives
	  while (current->m_next != NULL)
	    {
	      prev = current;
	      current = current->m_next;
	    }

	  // Locomotive -> NULL
	  if (current->getType() == 0)
	    {
	      tempCar = new TrainCar(car);
	      tempCar->m_next = current->m_next;
	      current->m_next = tempCar;
	      return;
	    }
	  
	  // Locomotive -> Coach -> NULL
	  else if (current->getType() == 1 && prev->getType() == 0)
	    {
	      tempCar = new TrainCar(car);
	      tempCar->m_next = prev->m_next;
	      prev->m_next = tempCar;
	      return;
	    }
	  else if (current->getType() == 2)
	    {
	      tempCar = new TrainCar(car);
	      tempCar->m_next = current->m_next;
	      current->m_next = tempCar;
	      return;
	    }
	}
    }
  else if (car == 4)
    {
      // Only add if there isn't a SnackCar already
      if (HasSnack() == false)
	{
	  // If nothing currently in Train besides m_head/Dummy
	  if (current->m_next == NULL)
	    {
	      current->m_next = new TrainCar(car);
	      return;
	    }

	  while (current != NULL)
	    {
	      // If train contains both BusinessClass, and CoachClass
	      // Add between Business and Coach
	      if (current->getType() == 2)
		{
		  if (current->m_next != NULL && current->m_next->getType()== 1)
		    {
		      tempCar = new TrainCar(car);
		      tempCar->m_next = current->m_next;
		      current->m_next = tempCar;
		      return;
		    }
		}
	      
	      else if (current->getType() == 1)
		{
		  if (getNumCoach() == 1)
		    {
		      tempCar = new TrainCar(car);
		      tempCar->m_next = m_head->m_next->m_next;
		      m_head->m_next->m_next = tempCar;
		      return;		      
		    }
		  // Train contains odd number of CoachClass TrainCars
		  if (getNumCoach() % 3 == 0 )
		    {
		      tempCar = new TrainCar(car);
		      tempCar->m_next = current->m_next;
		      current->m_next = tempCar;
		      return;
		    }

		  // Train contains even number of CoachClass TrainCars
		  else if (getNumCoach() % 2 == 0)
		    {
		      int endLocation = 0;
		      while (endLocation < (getNumCoach()/2) - 1 )
			{
			  current = current->m_next;
			  endLocation += 1;
			}
		      tempCar = new TrainCar(car);
		      tempCar->m_next = current->m_next;
		      current->m_next = tempCar;
		      return;
		    }
		}

	      current = current->m_next;
	    }
	}
    }
  else if (car == 5)
    {
      // SleepCar gets placed after CoachClass
      while (current->m_next != NULL)
	{
	  prev = current;
	  current = current->m_next;
	}

      tempCar = new TrainCar(car);
      tempCar->m_next = current->m_next;
      current->m_next = tempCar;

      prev = current;

      // DiningCar should be added when SleepingCar is added
      if (getNumSleeping() == 1)
	{
	  tempCar = new TrainCar(TrainCar::DiningCar);
	  tempCar->m_next = prev->m_next;
	  prev->m_next = tempCar;
	}
    }   
}

// removeCar
// Given the cType of the car, returns a boolean if car is removed
bool Train::removeCar(TrainCar::cType car)
{
  TrainCar *current = m_head;
  TrainCar *prev = m_head;

  if (car == 3)
    {
      // Remove all SleepingCars when removing DiningCar
      while (getNumSleeping() != 0)
	{
	  removeCar(TrainCar::SleepingCar);
	}

      // Traverse through list to find the car to be removed
      while (current != NULL && current->getType() != car)
	{
	  prev = current;
	  current = current->m_next;
	}

      // If car to be removed doesn't exist
      if (current == NULL)
	{
	  return false;
	}
      
      // Removes car
      else 
	{
	  prev->m_next = current->m_next;
	  return true;
	}
    }
  else if (car == 5)
    {
      // when the train contains more than one sleeping car
      // just remove that car
      if (getNumSleeping() > 1)
	{
	  // Traverse through list to find the car to be removed
	  while (current != NULL && current->getType() != car)
	    {
	      prev = current;
	      current = current->m_next;
	    }

	  prev->m_next = current->m_next;
	  return true;
	} 

      // when there's only one SleepingCar, removing DiningCar as well
      else if (getNumSleeping() == 1)
	{
	  // Traverse through list to find the car to be removed
	  while (current != NULL && current->getType() != car)
	    {
	      prev = current;
	      current = current->m_next;
	    }

	  prev->m_next = current->m_next;
	  
	  if (prev->getType() == 3)
	    {
	      removeCar(TrainCar::DiningCar);
	      
	    }
	  return true;
	}
      else 
	{
	  return false;
	}
    }
  else
    {
      // Traverse through list to find the car to be removed
      while (current != NULL && current->getType() != car)
	{
	  prev = current;
	  current = current->m_next;
	}

      // If car to be removed doesn't exist
      if (current == NULL)
	{
	  return false;
	}
      else 
	{
	  prev->m_next = current->m_next;
	  return true;
	}
    }
}

// getNumCoach
// Returns the number of CoachClass TrainCars
int Train::getNumCoach()
{
  m_numCoachClass = 0;
  TrainCar* current = m_head->m_next;

  // Traverse through linked list and find any CoachClass TrainCars
  while (current != NULL)
    {
      if (current->getType() == 1)
	{
	  m_numCoachClass += 1;
	}
      current = current->m_next;
    }
  
  return m_numCoachClass;
}

// getNumBusiness
// Returns the number of BusinessClass TrainCars
int Train::getNumBusiness()
{
  m_numBusinessClass = 0;
  TrainCar* current = m_head->m_next;
  
  // Traverse through linked list and find any BusinessClass TrainCars
  while (current != NULL)
    {
      if (current->getType() == 2)
	{
	  m_numBusinessClass += 1;
	}
      current = current ->m_next;
    }

  return m_numBusinessClass;
}

// getNumSleeping
// Returns the number of SleepingCar TrainCars
int Train::getNumSleeping()
{
  m_numSleepingCar = 0;
  TrainCar* current = m_head->m_next;

  // Traverse through linked list and find any SleepingCars
  while (current != NULL)
    {
      if (current->getType() == 5)
	{
	  m_numSleepingCar += 1;
	}
      current = current->m_next;
    }

  return m_numSleepingCar;
}

// HasSnack
// Returns a boolean if train contains a SnackCar
bool Train::HasSnack()
{
  
  TrainCar* current = m_head->m_next;

  while (current != NULL)
    {
      if (current->getType() == 4)
	{
	  m_hasSnackCar = true;
	}
      current = current->m_next;
    }

  return m_hasSnackCar;
}

// getNumber
// Returns the train number
int Train::getNumber() const
{
  return m_number;
}

// setNumber
// Sets the train number
void Train::setNumber(int num)
{
  m_number = num;
}

// getDepartureTime
// Gets the departure time
Time Train::getDepartureTime() const
{
  return m_departs;
}

// setDepartureTime
// Sets the departure time
void Train::setDepartureTime(const Time& t)
{
  m_departs = t;
}

// getDestination
// Gets the train's destination
string Train::getDestination() const
{
  return m_destination;
}

// setDestination
// Sets the train's destination
void Train::setDestination(string dest)
{
  m_destination = dest;
}

// isValid
// Checks that the train is valid
bool Train::isValid()
{
  int numLocos;
  TrainCar* current = m_head;

  while (current != NULL)
    {
      if (current->getType() == 0)
	{
	  numLocos += 1;
	}
      current = current->m_next;
    }

  // Must be at least one Locomotive
  // Must be one or more CoachClass
  if (numLocos > 0 && getNumCoach() != 0)
    {
      return true;
    }
  else if (numLocos > 0 && getNumCoach() == 0)
    {
      cerr << "Error in Train::isValid() : Train #" << m_number << " does not have any coaches" << endl; 
      return false;
    } 
  else
    {
      cerr << "Error in Train::isValid() : Train #" << m_number << " does not have a locomotive" << endl;
      return false;
    }
}

// operator<<
// Overloaded insertion operator prints a character graphics of the train
ostream& operator<<(ostream &outStream, const Train& t)
{
  TrainCar* current = t.m_head->m_next;

  while (current != NULL)
    {
      outStream << *current;
      current = current->m_next;
    }

  return outStream;
}
