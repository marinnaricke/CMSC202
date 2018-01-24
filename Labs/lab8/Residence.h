// File: Residence.h

#ifndef RESIDENCE_H
#define RESIDENCE_H

class Residence {
 public:

  Residence();
  Residence(int numRooms, int numExWalls, bool hasWasher);
  
  double PropertyValue();
  int NumWindows();
  friend ostream& operator<<(ostream &outStream, Residence r);

 protected:
  
  bool HasWasher();
  int m_numRooms;
  int m_numExWalls;
  bool m_hasWasher;

};

#endif
