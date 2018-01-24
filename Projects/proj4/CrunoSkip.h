/* File: CrunoSkip.h
   Project: CMSC 202 Project 4, Spring 2016
   Author: Marinna Ricketts-Uy
   Date: 4/21/16
   Section: 17
   E-mail: pd12778@umbc.edu
*/

#ifndef _CrunoSkip_H_
#define _CrunoSkip_H_

#include "card.h"

class CrunoSkip: public Card
{
 public:

  static const unsigned int SKIP = 16;  // CrunoSkip Action Card has value of 16

  // Default Constructor
  CrunoSkip();

  // Alternate Constructor
  CrunoSkip(unsigned int suit, unsigned int points);

  // Name: toString
  // PreCondition: NONE
  // PostCondition: Returns a string description of the card
  virtual string toString();
  
  // Name: playCard
  // PreCondition: valid pointers
  // PostCondition: NONE
  virtual void playCard(Game *gptr, Player *pptr);
};

#endif
