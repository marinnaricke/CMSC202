/* File: Cruno8.h
   Project: CMSC 202 Project 4, Spring 2016
   Author: Marinna Ricketts-Uy
   Date: 4/21/16
   Section: 17
   E-mail: pd12778@umbc.edu
*/

#ifndef _Cruno8_H_
#define _Cruno8_H_

#include "card.h"

class Cruno8: public Card
{
 public:

  // Default Constructor
  Cruno8();

  // Alternate Constructor
  Cruno8(unsigned int suit, unsigned int points);

  // Name: playable
  // PreCondition:  gptr must be a valid Game pointer
  // PostCondition: Returns true
  virtual bool playable(Game *gptr);
  
  // Name: playCard
  // PreCondition: valid pointers
  // PostCondition: NONE
  virtual void playCard(Game *gptr, Player *pptr);

};

#endif
