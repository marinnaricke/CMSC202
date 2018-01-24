/* File: CrunoPlayer.h
   Project: CMSC 202 Project 4, Spring 2016
   Author: Marinna Ricketts-Uy
   Date: 4/21/16
   Section: 17
   E-mail: pd12778@umbc.edu
*/

#ifndef _CrunoPlayer_H_
#define _CrunoPlayer_H_

#include "player.h"

class CrunoPlayer: public Player
{
 public:

  // Constructor
  CrunoPlayer(Game *gptr, unsigned int numCards);

  // Name: playOneCard
  // PreCondition:  lastCard must be a reference to a boolean, oneCardLeft
  //                must be a reference to a boolean.
  // PostCondition: Returns a Card pointer
  virtual Card * playOneCard(bool &lastCard, bool &oneCardLeft);

  // Name: getNumHearts
  // PreCondition:  NONE
  // PostCondition: Returns an integer with the number of heart suits
  int getNumHearts();

  // Name: getNumDiamonds
  // PreCondition:  NONE
  // PostCondition: Returns an integer 
  int getNumDiamonds();

  // Name: getNumSpades
  // PreCondition:  NONE
  // PostCondition: Returns an integer
  int getNumSpades();

  // Name: getNumClubs
  // PreCondition:  NONE
  // PostCondition: Returns an integer
  int getNumClubs();

  // Name: gameOverPenalty
  // PreCondition:  NONE
  // PostCondition: Returns an integer
  virtual int gameOverPenalty();

  // Name: pickSuit
  // PreCondition:  NONE
  // PostCondition: Returns an unsigned int
  virtual unsigned int pickSuit();

 private:

  int m_numClubs;    // number of clubs in player's hand
  int m_numHearts;   // number of hearts in player's hand
  int m_numSpades;   // number of spades in player's hand
  int m_numDiamonds; // number of diamonds in player's hand

};

#endif
