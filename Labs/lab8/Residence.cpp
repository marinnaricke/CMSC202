// File: Residence.cpp

#include <iostream>
#include <string>
using namespace std;

#include "Residence.h"

Residence::Residence()
{
  m_numRooms = 0;
  m_numExWalls = 0;
  m_hasWasher = false;
}

Residence::Residence(int numRooms, int numExWalls, bool hasWasher)
{
  m_numRooms = numRooms;
  m_numExWalls = numExWalls;
  m_hasWasher = hasWasher;
}

double Residence::PropertyValue()
{ 
  double value;
  value = m_numRooms * 10000;
  
  return value;
}

int Residence::NumWindows()
{
  int numWindows;
  numWindows = m_numExWalls * 2;
  
  return numWindows;
}

bool Residence::HasWasher()
{
  if (m_hasWasher == true)
    {
      return true;
    }
  else 
    {
      return false;
    }
}

ostream& operator<<(ostream &outStream, Residence r)
{
  string boolWasher;

  if (r.m_hasWasher == true)
    {
      boolWasher = "true";
    }
  else
    {
      boolWasher = "false";
    }

  outStream << "Number of Rooms: " << r.m_numRooms \
	    << "\nNumber of Walls: " << r.m_numExWalls \
	    << "\nWasher: " << boolWasher \
	    << "\nNumber of Windows: " << r.NumWindows() \
	    << "\nProperty Value: " << r.PropertyValue() << endl;

  return outStream;
}
