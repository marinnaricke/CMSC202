/* File: CrunoDraw2.cpp
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
#include "CrunoDraw2.h"

// Default Constructor
// Sets the initial values
CrunoDraw2::CrunoDraw2(): Card()
{
  // empty constructor
}

// Alternate Constructor
// Sets the suit and points of card
CrunoDraw2::CrunoDraw2(unsigned int s, unsigned int p)
{  
  if (s > Spades) {   // sanity check
    s = Invalid ;
  }
  m_suit = s ;
  m_points = p;
}

// toString
// Returns a string description of the card
string CrunoDraw2::toString()
{
  ostringstream oss;

  oss << "Draw2";

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
// Card does what it needs to do
void CrunoDraw2::playCard(Game *gptr, Player * pptr)
{
  Player *pptr1;      
  Card *cptr1, *cptr2;
  unsigned int p, q;   

  // Sets the current suit and current points
  Card::playCard(gptr,pptr);

  CrunoGame *cgptr;
  cgptr = dynamic_cast<CrunoGame *>(gptr);

  //The next player must draw two cards from the stock  
  p = cgptr->currentPlayer();
  q = cgptr->playerAfter(p);
  pptr1 = cgptr->getPlayer(q);

  cptr1 = cgptr->dealOneCard();
  cptr2 = cgptr->dealOneCard();

  cout << "----------------------------\n" << endl;
  cout << "Player " << q << " must draw 2 cards" << endl;
  pptr1->takeCard(cptr1);
  cout << "Player " << q << " draws a card: " << cptr1->toString() << endl;
  pptr1->takeCard(cptr2);
  cout << "Player " << q << " draws a card: " << cptr2->toString() << endl;
}
