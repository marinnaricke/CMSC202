/* File: Cruno8.cpp
   Project: CMSC 202 Project 4, Spring 2016
   Author: Marinna Ricketts-Uy
   Date: 4/21/16
   Section: 17
   E-mail: pd12778@umbc.edu
*/

#include <iostream>
using namespace std;

#include "CrunoGame.h"
#include "CrunoPlayer.h"
#include "Cruno8.h"

// Default Constructor
// Calls Cards Constructor
Cruno8::Cruno8(): Card()
{
  // left empty
}

// Alternate Constructor
// Calls Card alternate Constructor
Cruno8::Cruno8(unsigned int s, unsigned int p): Card(s,p)
{
  // left empty
}

// playable
// Returns true because Cruno8 can be played at anytime
bool Cruno8::playable(Game *gptr)
{
  return true;
}

// playCard
// override Card::playCard to have a case where if 8 is played
// then the player picks a suit
void Cruno8::playCard(Game *gptr, Player *pptr)
{
  unsigned int s;

  // allow player to choose a suit
  s = pptr->pickSuit();
  if (s == 1)
    {
      cout << " Clubs picked! " << endl;
    }
  else if (s == 2)
    {
      cout << " Diamonds picked! " << endl;
    }
  else if (s == 3)
    {
      cout << " Hearts picked! " << endl;
    }
  else 
    {
      cout << " Spades picked! " << endl;
    }

  // set card's suit and points
  gptr->setSuit(s);  
  gptr->setPoints(getPoints());

  return;
}
