/* File: CrunoReverse.h
   Project: CMSC 202 Project 4, Spring 2016
   Author: Marinna Ricketts-Uy
   Date: 4/21/16
   Section: 17
   E-mail: pd12778@umbc.edu
*/

#ifndef _CrunoReverse_H_
#define _CrunoReverse_H_

#include "card.h"

class CrunoReverse: public Card
{
 public:

  static const unsigned int REVERSE = 17; // Reverse Action Card has value of 17

  // Default Constructor
  CrunoReverse();

  // Alternate Constructor
  CrunoReverse(unsigned int suit, unsigned int points);

  // Name: toString
  // PreCondition:  NONE
  // PostCondition: Returns a string description of the card
  virtual string toString();
  
  // Name: playCard
  // PreCondition:  valid pointers
  // PostCondition: NONE
  virtual void playCard(Game *gtr, Player *pptr);

};

#endif
