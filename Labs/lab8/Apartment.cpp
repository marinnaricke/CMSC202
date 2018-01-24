//File: Apartment.cpp

#include <iostream>
#include <string>
using namespace std;

#include "Apartment.h"

Apartment::Apartment() : Residence(4,4,false), m_story(0)
{

}

Apartment::Apartment(int story, bool hasWasher) : Residence(4,4,hasWasher), \
						  m_story(story)
{
  
}

double Apartment::PropertyValue()
{
  double value;
  
  if (HasWasher() == true)
    {
      value = Residence::PropertyValue() + 100.0;
    }
  else
    {
      value = Residence::PropertyValue();
    }

  return value;
}

int Apartment::getStory()
{
  return m_story;
}

ostream& operator<<(ostream &outStream, Apartment a)
{
  string boolWasher;

  if (a.m_hasWasher == true)
    {
      boolWasher = "true";
    }
  else
    {
      boolWasher = "false";
    }

  outStream << "Number of Rooms: " << a.m_numRooms \
	    << "\nNumber of Walls: " << a.m_numExWalls \
	    << "\nWasher: " << boolWasher \
	    << "\nNumber of Windows: " << a.NumWindows() \
	    << "\nProperty Value: " << a.PropertyValue() \
	    << "\nStory: " << a.m_story << endl;

  return outStream;
}
