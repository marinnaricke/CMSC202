// File: Pair.cpp

#ifndef PAIR_CPP
#define PAIR_CPP

#include <iostream>
using namespace std;

#include "Pair.h"

template <class T>
Pair<T>::Pair()
{
  //empty constructor
}

template <class T>
Pair<T>::Pair(T first, T second)
{
  m_first = first;
  m_second = second;
}

template <class T>
T Pair<T>::first()
{
  return m_first;
}

template <class T>
T Pair<T>::second()
{
  return m_second;
}

template <class T>
bool Pair<T>::operator== (const Pair<T> &rhs) const
{
  //code here to see if first==first and second==second
  // OR first==second and second==first
  if (rhs.m_first == m_first && rhs.m_second == m_second)
    {
      return true;
    }
  else if (m_first == rhs.m_second && m_second == rhs.m_first)
    {
      return true;
    }
  else
    {
      return false;
    }

}

#endif
