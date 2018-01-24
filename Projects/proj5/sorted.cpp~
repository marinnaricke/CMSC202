/* File:    sorted.cpp
   Project: CMSC 202 Project 5, Spring 2016
   Author:  Marinna Ricketts-Uy
   Date:    5/5/16
   Section: 17
   E-mail:  pd12778@umbc.edu

*/

#ifndef SORTED_CPP
#define SORTED_CPP

#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

#include "sorted.h"
#include "iterator_ex.h"

// ** sorted Class Public Functions **

// Default constructor
template <class T>
sorted<T>::sorted()
{
  m_size = 0;
  m_capacity = START_CAP;
  m_sorted = new T[m_capacity];
}

// Non-default constructor 
// copies data from array to sorted
template <class T>
sorted<T>::sorted( T* data, int len )
{
  m_sorted = new T[len];

  // copy data to m_data
  for (int i = 0; i < len; i++)
    {
      m_sorted[i] = data[i];
    }

  m_size = len;
  m_capacity = START_CAP;
}

// Copy constructor
template <class T>
sorted<T>::sorted( const sorted<T>& srtd )
{
  m_capacity = srtd.m_capacity;
  m_size = srtd.m_size;

  m_sorted = new T[m_capacity];

  for (int i = 0; i < m_size; i++)
    {
      m_sorted[i] = srtd.m_sorted[i];
    }
}

// Destructor
template <class T>
sorted<T>::~sorted()
{
  delete [] m_sorted ;
}

// operator=
// Overloaded assignment operator
template <class T>
sorted<T> sorted<T>::operator=(const sorted<T>& srtd)
{
  this->m_size = srtd.m_size;
  this->m_capacity = srtd.m_capacity;
  this->m_sorted = new T[srtd.m_capacity];

  for (int i = 0; i < srtd.size(); i++)
    {
      m_sorted[i] = srtd.m_sorted[i];
    }

  return *this;
}

// capacity
// Return the capacity of the storage array
template <class T>
int sorted<T>::capacity() const
{
  return m_capacity;
}

// size
// Return number of items stored
template <class T>
int sorted<T>::size() const
{
  return m_size;
}

// getStorageArray
// Return the address of the storage array;
// for use in grading programs
template <class T>
T* sorted<T>::getStorageArray() const
{
  return *m_sorted;
}

// insert
// Insert an item in sorted; return iterator to inserted item
template <class T>
typename sorted<T>::const_iterator sorted<T>::insert(T data)
{
  int position;

  if (m_size == 0)
    {
      position = 0;
    }
  else
    {
      for (int i = 0; i < m_size; i++)
	{
	  if (data <= m_sorted[i])
	    {
	      position = i;
	      i = m_size;
	    }
	  else if (data > m_sorted[i])
	    {
	      position = i + 1;
	    }
	}
    }

  // increase size and capacity to make room for new data
  m_size++;
  if (m_capacity == m_size)
    {
      m_capacity = m_size * 2;
    }

  T * temp = new T[m_capacity];

  for (int i = 0; i < m_size; i++)
    {
      // All data before the new data that is to be inserted
      if (i < position)
	{
	  temp[i] = m_sorted[i];
	}

      // Insert the new data at the correct position
      if (i == position)
	{
	  temp[i] = data;
	}

      // All data after the new data that is to be inserted
      if (i > position)
	{
	  temp[i] = m_sorted[i-1];
	}
    }

  // Set original array to new array
  m_sorted = temp;

  return const_iterator(&m_sorted[position]);
}

// erase
// Remove an item from sorted; return iterator to next item
// after the erased item
template <class T>
typename sorted<T>::const_iterator sorted<T>::erase(const_iterator itr)
{
  T * end = &m_sorted[m_size]; // one past the end of data
  T * ptr = itr.m_current;        // element to erase

  // to erase element at ptr, shift elements from ptr+1 to
  // the end of the array down one position
  while (ptr+1 != end)
    {
      *ptr = *(ptr+1);
      ptr++;
    }

  m_size--;
  
  return itr;
}

// at
// Get element at indx position
template <class T> 
const T& sorted<T>::at(int indx)
{
  return m_sorted[indx];
}

// begin
// Starting iterator value for const_iterator
template <class T>
typename sorted<T>::const_iterator sorted<T>::begin()
{
  return const_iterator(&m_sorted[0]);
}

// end
// Ending iterator value for const_iterator; typically,
// one element beyond the last valid element in the array.
template <class T>
typename sorted<T>::const_iterator sorted<T>::end()
{
  return const_iterator(&m_sorted[m_size]);
}

// rndbegin
// Starting iterator value for rand_iterator. Should use constant
// value or time(NULL) as seed value for srand().
template <class T>
typename sorted<T>::rand_iterator sorted<T>::rndbegin()
{
  return rand_iterator(this);
}

// rndbegin
// Starting iterator value for rand_iterator with seed for
// srand() specified.  Given a sorted<T> object x, repeated 
// use of rndbegin( unsigned seed ) with the same seed value
// must produce the same permutation of the elements of x.
template <class T>
typename sorted<T>::rand_iterator sorted<T>::rndbegin( unsigned seed )
{
  return rand_iterator(this,seed);
}

// rndend
// Ending iterator value for rand_iterator
template <class T>
typename sorted<T>::rand_iterator sorted<T>::rndend()
{
  rand_iterator end(this);

  // Increments rand_iterator to the "end" of 
  // m_random array of indices
  for (int i = 0; i < m_size; i++)
    {
      ++end;
    }

  return end;
}

// ** const_iterator public functions **

// Default constructor
template <class T>
sorted<T>::const_iterator::const_iterator()
{
  m_current = NULL;
}

// Non-default constructor 
// Sets value to given address
template <class T>
sorted<T>::const_iterator::const_iterator(T* addr)
{
  m_current = addr;
}

// Pre-increment
template <class T>
typename sorted<T>::const_iterator sorted<T>::const_iterator::operator++()
{
  ++m_current;
  return *this;
}

// Post-increment
template <class T>
typename sorted<T>::const_iterator sorted<T>::const_iterator::operator++(int)
{
  const_iterator result(*this);
  ++(*this);
  return result;
}

// operator!= 
// Needed for loop control, e.g. itr != x.end()
template <class T>
bool sorted<T>::const_iterator::operator!=(const const_iterator& itr)
{
  return m_current != itr.m_current;
}

// Unary dereference operator
// Returns element currently pointed to by the const_iterator
template <class T>
const T& sorted<T>::const_iterator::operator*()
{
  return *m_current; 
}

// ** rand_iterator public functions **

// Default constructor
// Not fully initialized since it has no
//  connection to a sorted<T> object
template <class T>
sorted<T>::rand_iterator::rand_iterator()
{
  //empty constructor
}

// Non-default constructor
// Pointer to sorted<T> object passed as a parameter, 
//  which allows the rand_iterator to access variables 
//  of the associated sorted<T> container.
template <class T>
sorted<T>::rand_iterator::rand_iterator( sorted<T>* srtdPtr )
{
  m_srtdPtr = srtdPtr;
  m_seed = time(NULL);  
  m_randCurrent = 0;    // current index position of array of indices

  m_randSize = srtdPtr->m_size;
  m_random = new int[m_randSize];

  // make an array of indices
  for (int i = 0; i < m_randSize; i++)
    {
      m_random[i] = i;
    }

  // shuffle the indices
  int j;
  srand(m_seed);
  for (int i = 0; i < m_randSize; i++)
    {
      int temp;

      j = rand() % m_randSize;
      temp = m_random[i];
      m_random[i] = m_random[j];
      m_random[j] = temp;
    }
}

// Non-default constructor; pointer to sorted<T> passed as in
// previous constructor, but also passes seed for random number
// generator
template <class T>
sorted<T>::rand_iterator::rand_iterator( sorted<T>* srtdPtr, unsigned seed )
{
  m_srtdPtr = srtdPtr;
  m_seed = seed;
  m_randCurrent = 0;  // current index position of array of indices

  m_randSize = srtdPtr->m_size;
  m_random = new int[m_randSize];

  // make an array of indices
  for (int i = 0; i < m_randSize; i++)
    {
      m_random[i] = i;
    }

  // shuffle the indices
  int j;
  srand(m_seed);
  for (int i = 0; i < m_randSize; i++)
    {
      int temp;

      j = rand() % m_randSize;
      temp = m_random[i];
      m_random[i] = m_random[j];
      m_random[j] = temp;
    }
}

// Copy constructor
template <class T>
sorted<T>::rand_iterator::rand_iterator( const rand_iterator& itr )
{
  // Copy over member variables
  m_srtdPtr = itr.m_srtdPtr;
  m_seed = itr.m_seed;
  m_randCurrent = itr.m_randCurrent;
  m_randSize = itr.m_randSize;

  // Create new random array of indices
  m_random = new int[m_randSize];

  // Copy over array of indices
  for (int i = 0; i < m_randSize; i++)
    {
      m_random[i] = itr.m_random[i];
    }

}

// Destructor
template <class T>
sorted<T>::rand_iterator::~rand_iterator()
{
  delete [] m_random;
}

// operator++
// pre-increment
template <class T>
typename sorted<T>::rand_iterator sorted<T>::rand_iterator::operator++()
{
  // Check if the size of the sorted<T> object has been changed
  if (m_srtdPtr->m_size != m_randSize)
    {
      throw iterator_ex("Size has been changed, can't pre-increment");
    }

  ++m_randCurrent;
  return *this;
}

// operator++
// post-increment
template <class T>
typename sorted<T>::rand_iterator sorted<T>::rand_iterator::operator++(int)
{
  // Check if the size of the sorted<T> object has been changed
  if (m_srtdPtr->m_size != m_randSize)
    {
      throw iterator_ex("Size has been changed, can't post-increment");
    }

  rand_iterator result(*this);
  ++(*this);
  return result;
}

// operator!= 
// needed for loop control, e.g. itr != x.end()
template <class T>
bool sorted<T>::rand_iterator::operator!=(const rand_iterator& itr)
{  
  // Check if the size of sorted<T> object has been changed
  if (m_srtdPtr->m_size != m_randSize)
    {
      throw iterator_ex("Size has been changed, can't use operator!=");
    }

  return m_randCurrent != itr.m_randCurrent;
}

// operator*
// Unary dereference operator
// Returns the element at sorted<T> object using array of indices
template <class T>
const T& sorted<T>::rand_iterator::operator*()
{
  // Check if the size of sorted<T> object has been changed
  if (m_srtdPtr->m_size != m_randSize)
    {
      throw iterator_ex("Size has been changed, can't use operator*");
    }

  return m_srtdPtr->at(m_random[m_randCurrent]);
}

// operator=
// Overloaded assignment operator
template <class T>
typename sorted<T>::rand_iterator sorted<T>::rand_iterator::operator=(const rand_iterator& itr)
{ 
  // Copy over member variables
  this->m_randCurrent = itr.m_randCurrent;
  this->m_randSize = itr.m_randSize;
  this->m_srtdPtr = itr.m_srtdPtr;
  this->m_seed = itr.m_seed;

  // Create new random indices array
  this->m_random = new int[m_randSize];
  
  // Copy over random indices array
  for (int i = 0; i < m_randSize; i++)
    {
      m_random[i] = itr.m_random[i];
    }

  return *this;
}

#endif
