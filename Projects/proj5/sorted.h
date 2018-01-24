/* File:    sorted.h
   Project: CMSC 202 Project 5, Spring 2016
   Author:  Marinna Ricketts-Uy
   Date:    5/5/16
   Section: 17
   E-mail:  pd12778@umbc.edu

*/

#ifndef SORTED_H
#define SORTED_H

using namespace std;

const int START_CAP = 10; // Start capacity 

template <class T>
class sorted
{
 public:
  
  // Forward declare iterator classes
  class const_iterator;
  class rand_iterator;

  // Default Constructor
  sorted();

  // Non-default constructor 
  sorted( T* data, int len);

  // Copy Constructor
  sorted( const sorted<T>& srtd);

  // Destructor
  ~sorted();

  // Overloaded assignment operator
  // Name: operator=
  // PreCondition:  srtd must be a valid sorted<T> object 
  // PostCondition: Returns a sorted<T> object
  sorted<T> operator=(const sorted<T>& srtd);

  // Name: capacity
  // PreCondition:  None
  // PostCondition: Returns the capacity of the storage array
  int capacity() const;

  // Name: size 
  // PreCondition:  None
  // PostCondition: Returns number of items stored
  int size() const;

  // Name: getStorageArray
  // PreCondition:  None
  // PostCondition: Return the address of the storage array
  T* getStorageArray() const;

  // Name: insert
  // PreCondition:  data must be a valid type T  
  // PostCondition: Returns iterator to inserted item
  const_iterator insert(T data);
  
  // Name: erase
  // PreCondition:  itr must be a valid const_iterator
  // PostCondition: Returns iterator to next item
  const_iterator erase(const_iterator itr);

  // Name: at
  // PreCondition:  indx must be a valid integer
  // PostCondition: Get element at indx position
  const T& at(int indx);

  // Name: begin
  // PreCondition:  None
  // PostCondition: Starting iterator value for const_iterator
  const_iterator begin();

  // Name: end
  // PreCondition:  None
  // PostCondition: Returns ending iterator value for const_iterator
  const_iterator end();

  // Name: rndbegin
  // PreCondition:  None
  // PostCondition: Returns ending iterator value for const_iterator
  rand_iterator rndbegin();

  // Name: rndbegin
  // PreCondition:  seed must be a valid unsigned seed
  // PostCondition: Returns starting iterator value for rand_iterator
  rand_iterator rndbegin( unsigned seed);

  // Name: rndend
  // PreCondition:  None
  // PostCondition: Returns ending iterator value for rand_iterator 
  rand_iterator rndend();

  class const_iterator
  {
  public:

    friend class sorted;
    
    // Default constructor
    const_iterator();
    
    // Non-default constructor 
    const_iterator(T* addr);
    
    // Name: operator++
    // PreCondition:  None
    // PostCondition: Returns a pre-increments const_iterator
    const_iterator operator++();
    
    // Name: operator++
    // PreCondition: None
    // PostCondition: Returns a post-incremented const_iterator
    const_iterator operator++(int);
    
    // Name: operator!=
    // PreCondition: itr must be a valid const_iterator
    // operator!= needed for loop control, e.g. itr != x.end()
    bool operator!=(const const_iterator& itr);
    
    // Name: operator*
    // PreCondition:  None
    // PostCondition: Returns element currently pointed to
    const T& operator*();

  private:
    T* m_current; // pointer to a the current addresss in m_sorted
  };

  class rand_iterator
  {
  public:

    friend class sorted;
    
    // Default constructor
    rand_iterator();
    
    // Non-default constructor
    rand_iterator( sorted<T>* srtdPtr );
    
    // Non-default constructor
    rand_iterator( sorted<T>* srtdPtr, unsigned seed ); 

    // Copy constructor
    rand_iterator( const rand_iterator& itr );
    
    // Destructor
    ~rand_iterator();
    
    // Name: operator++
    // PreCondition:  None
    // PostCondition: pre-increments a rand_iterator
    rand_iterator operator++();
    
    // Name: operator++
    // PreCondition:  None
    // PostCondition: post-increments a rand_iterator
    rand_iterator operator++(int);
    
    // Name: operator!=
    // PreCondition:  itr must be a valid rand_iterator
    // PostCondition: Returns a boolean 
    bool operator!=(const rand_iterator& itr);
    
    // Name: operator*
    // PreCondition:  None
    // PostCondition: Returns a T value
    const T& operator*();
    
    // Name: operator=
    // PreCondition:  itr must be a valid rand_iterator
    // PostCondition: "this" will be equal to itr
    rand_iterator operator=(const rand_iterator& itr);  

  private:
    sorted<T>* m_srtdPtr;  // pointer to a sorted<T> object
    unsigned m_seed;       // seed for generating random
    int m_randCurrent;     // current index in array of indices 
    int m_randSize;        // size of the array of indices
    int* m_random;        // permutation array (array of indices)  
  };

 private:
  T* m_sorted;        // pointer to the storage array
  int m_size;         // size of the storage array
  int m_capacity;     // capacity of the storage array
};

#endif

#include "sorted.cpp"
