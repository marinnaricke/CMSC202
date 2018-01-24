//File: Tent.h

#ifndef TENT_H
#define TENT_H

#include "Residence.h"

class Tent: public Residence
{
 public:
  Tent();

  double PropertyValue();
  int NumWindows();
};

#endif
