// File: Pair.h

#ifndef PAIR_H
#define PAIR_H

template <class T>

class Pair
{
 public:
  Pair();
  Pair(T first, T second);
  
  T first();
  T second();

  bool operator==(const Pair<T> &rhs) const;

 private:
  T m_first;
  T m_second;


};

#endif

#include "Pair.cpp"
