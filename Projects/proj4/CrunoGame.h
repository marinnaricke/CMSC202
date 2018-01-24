/* File: CrunoGame.h
   Project: CMSC 202 Project 4, Spring 2016
   Author: Marinna Ricketts-Uy
   Date: 4/21/16
   Section: 17
   E-mail: pd12778@umbc.edu
*/

#ifndef _CRUNOGAME_H_
#define _CRUNOGAME_H_

#include "game.h"
#include "player.h"

class Cruno8;
class CrunoReverse;
class CrunoSkip;
class CrunoDraw2;
class CrunoPlayer;

const int PER_SUIT = 2;   // two action cards per suit

class CrunoGame: public Game
{
 public:

  // Default Constructor
  CrunoGame();

  // Name: initialize 
  // PreCondition:  numPlayers must be an integer
  // PostCondition: NONE
  virtual void initialize(int numPlayers);

  // Name: dealOneCard
  // PreCondition:  NONE
  // PostCondition: Returns a Card pointer
  virtual Card * dealOneCard();

  // Name: timesReversed
  // PreCondition:  num must be an integer
  // PostCondition: timesReversed is incremented
  void timesReversed(int num);
  
  // Name: nextPlayer
  // PreCondition:  NONE
  // PostCondition: Returns m_currentPlayer
  virtual unsigned int nextPlayer();

  // Name: playerAfter
  // PreCondition:  thisPlayer must be an unsigned integer
  // PostCondition: Returns an unsigned integer
  virtual unsigned int playerAfter(unsigned int thisPlayer);

  // Name: getPlayer
  // PreCondition:  p must be an unsigned integer
  // PostCondition: Returns a Player pointer
  Player * getPlayer(unsigned int p);

 protected:
  int m_timesReversed; // stores the number of times a CrunoReverse was played
};

#endif
