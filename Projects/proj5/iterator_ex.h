/* File:    iterator_ex.h
   Project: CMSC 202 Project 5, Spring 2016
   Author:  Marinna Ricketts-Uy
   Date:    5/5/16
   Section: 17
   Email:   pd12778@umbc.edu

*/

#ifndef ITERATOR_EX_H_
#define ITERATOR_EX_H

#include <exception>
using namespace std;

class iterator_ex: public exception
{
 public:
  
  // Default constructor
  // Sets the private variable to the empty C-string
  iterator_ex();

  // Non-default constructor
  // Sets the private variable to a user_supplied C-string
  iterator_ex(const char* message);

  // Accessor function
  // Returns the C-string stored in the private variable
  // Note: here throw() indicates that the what() function
  //  will not throw an exception
  const char* what() const throw();

 private:
  const char* m_message;
};

#endif
