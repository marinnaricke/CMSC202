/* File: CrunoDraw2.h
   Project: CMSC 202 Project 4, Spring 2016
   Author: Marinna Ricketts-Uy
   Date: 4/21/16
   Section: 17
   E-mail: pd12778@umbc.edu
*/

#ifndef _CrunoDraw2_H_
#define _CrunoDraw2_H_

#include "card.h"

class CrunoDraw2: public Card
{
 public:

  static const unsigned int DRAW_2 = 15; // Draw2 Action Card has value of 15

  // Default Constructor
  CrunoDraw2();

  // Alternate Constructor
  CrunoDraw2(unsigned int suit, unsigned int points);

  // Name: toString
  // PreCondition:  NONE
  // PostCondition: Returns a string description of the card
  virtual string toString();

  // Name: playCard
  // PreCondition:  valid pointers
  // PostCondition: NONE
  virtual void playCard(Game *gptr, Player *pptr);
};

#endif
