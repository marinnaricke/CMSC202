//File: Apartment.h

#ifndef APARTMENT_H
#define APARTMENT_H

#include "Residence.h"

class Apartment: public Residence
{
 public:
  Apartment();
  Apartment(int story, bool hasWasher);

  double PropertyValue();
  int getStory();
  friend ostream& operator<<(ostream &outStream, Apartment a);

 private:
  int m_story;  
};

#endif
