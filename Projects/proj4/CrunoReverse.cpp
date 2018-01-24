/* File: CrunoReverse.cpp
   Project: CMSC 202 Project 4, Spring 2016
   Author: Marinna Ricketts-Uy
   Date: 4/21/16
   Section: 17
   E-mail: pd12778@umbc.edu
*/

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#include "CrunoGame.h"
#include "CrunoPlayer.h"
#include "CrunoReverse.h"

// Default Constructor
// Sets the initial values
CrunoReverse::CrunoReverse(): Card()
{
  // empty constructor
}

// Alternate Constructor
// Sets the suit of the card and points
CrunoReverse::CrunoReverse(unsigned int s, unsigned int p)
{  
  if (s > Spades) {   // sanity check
    s = Invalid ;
  }
  m_suit = s ;

  m_points = p;
}

// toString
// Returns a string description of the CrunoReverse Card
string CrunoReverse::toString()
{
  ostringstream oss;
  
  oss << "Reverse";

  switch (m_suit)
    {
    case Clubs:
      oss << " of Clubs";
      break;
    case Diamonds:
      oss << " of Diamonds";
      break;
    case Hearts:
      oss << " of Hearts";
      break;
    case Spades:
      oss << " of Spades";
      break;
    default:
      oss << " of INVALID SUIT\n";
      break;
    }

  return oss.str();
}

// playCard
// Sets suit and action
void CrunoReverse::playCard(Game *gptr, Player *pptr)
{
  Card::playCard(gptr,pptr);

  CrunoGame *cgptr;
  cgptr = dynamic_cast<CrunoGame *>(gptr);

  //Add to the number of times reversed was played
  cgptr->timesReversed(1);
}

