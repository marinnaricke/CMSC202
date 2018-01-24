/* File:    iterator_ex.cpp
   Project: CMSC 202 Project 5, Spring 2016
   Author:  Marinna Ricketts-Uy
   Date:    5/5/16
   Section: 17
   E-mail:  pd12778@umbc.edu
*/

#include <iostream>
using namespace std;

#include "iterator_ex.h"

// Default constructor
// Sets the private variable to the empty C-string
iterator_ex::iterator_ex()
{
  m_message = "";
}

// Non-default constructor
// Sets the private variable to a user_supplied C-string
iterator_ex::iterator_ex(const char* message)
{
  m_message = message;
}

// Accessor function
// Returns the C-string stored in the private variable
// Note: here throw() indicates that the what() function
//  will not throw an exception
const char* iterator_ex::what() const throw()
{
  return m_message;
}
