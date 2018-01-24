/* File: CrunoSkip.cpp
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
#include "CrunoSkip.h"

// Default Constructor
// Sets initial values
CrunoSkip::CrunoSkip(): Card()
{
  // empty constructor
}

// Alternate Constructor
// Sets the suits and the points
CrunoSkip::CrunoSkip(unsigned int s, unsigned int p)
{  
  if (s > Spades) {   // sanity check
    s = Invalid ;
  }
  m_suit = s ;
  m_points = p;
}

// toString
// Returns a string description of the CrunoSkip card
string CrunoSkip::toString()
{
  ostringstream oss;

  oss << "Skip";

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
      oss << "of INVALID SUIT\n";
      break;
    }

  return oss.str();
}

// playCard
// Sets the current suit and current points
void CrunoSkip::playCard(Game *gptr,Player *pptr)
{
  Card::playCard(gptr,pptr);
}



