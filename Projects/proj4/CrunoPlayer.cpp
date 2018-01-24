/* File: CrunoPlayer.cpp
   Project: CMSC 202 Project 4, Spring 2016
   Author: Marinna Ricketts-Uy
   Date: 4/21/16
   Section: 17
   E-mail: pd12778@umbc.edu
*/

#include <iostream>
using namespace std;

#include "CrunoPlayer.h"
#include "card.h"
#include "game.h"

// Constructor
// Calls Player constructor
CrunoPlayer::CrunoPlayer(Game *gptr, unsigned int numCards): Player(gptr, numCards)
{
  // empty constructor
}

// playOneCard
// main game playing strategy goes here
Card *CrunoPlayer::playOneCard(bool &lastCard, bool &oneCardLeft)
{
  unsigned int c, s;
  Card *cptr, *temp;

  //find first card that is playable
  
  c = 0;          //index into array of Card pointers
  cptr = NULL;    //haven't found a playable card yet

  while(1)
    {
      if (c >= m_numCards) break; // hit end of array
      
      // Uses the suit that appears the most in player's hand
      s = pickSuit();

      // If the card is the favored suit and is playable
      if (m_cards[c]->getSuit() == s)
	{
	  
	  // If the card is playable
	  if (m_cards[c]->playable(m_game)) // found playable card
	    {
	      cptr = m_cards[c]; // remember the card

	      m_numCards--;                        //one less card
	      m_cards[c] = m_cards[m_numCards];    // replace with last card
	      m_cards[m_numCards] = NULL;         // just to be safe

	      if (m_numCards == 1) oneCardLeft = true; // say "Uno"?
	      if (m_numCards == 0) lastCard = true;    // did we win?
	      break;
	    }
	}

      // If the card is playable 
      else if (m_cards[c]->playable(m_game)) // found playable card
	{
	  cptr = m_cards[c]; // remember the card

	  m_numCards--;                        //one less card  
	  m_cards[c] = m_cards[m_numCards];    // replace with last card
	  m_cards[m_numCards] = NULL;         // just to be safe

	  if (m_numCards == 1) oneCardLeft = true; // say "Uno"?
	  if (m_numCards == 0) lastCard = true;    // did we win?
	  break;
	}
      c++;
    }

  return cptr;
}

// getNumClubs
// Returns number of clubs in host player's hand
int CrunoPlayer::getNumClubs()
{
  for (unsigned int c = 0; c < m_numCards; c++)
    {
      if (m_cards[c]->getSuit() == 1)
	{
	  m_numClubs += 1;
	}
    }
  
  return m_numClubs;
}

// getNumSpades
// Returns number of spades in host player's hand
int CrunoPlayer::getNumSpades()
{
  for (unsigned int c = 0; c < m_numCards; c++)
    {
      if (m_cards[c]->getSuit() == 4)
	{
	  m_numSpades += 1;
	}
    }

  return m_numSpades;
}

// getNumHearts
// Returns number of spades in host player's hand
int CrunoPlayer::getNumHearts()
{
  for (unsigned int c = 0; c < m_numCards; c++)
    {
      if (m_cards[c]->getSuit() == 3)
	{
	  m_numHearts += 1;
	}
    }

  return m_numHearts;
}

// getNumDiamonds
// Returns number of diamonds in host player's hand
int CrunoPlayer::getNumDiamonds()
{
  for (unsigned int c = 0; c < m_numCards; c++)
    {
      if (m_cards[c]->getSuit() == 2)
	{
	  m_numDiamonds += 1;
	}
    }
  
  return m_numDiamonds;
}

// pickSuit
// Picks the suit based on the favored suit in host player's hand 
unsigned int CrunoPlayer::pickSuit()
{
  if (getNumClubs() > getNumHearts() 
      && getNumClubs() > getNumDiamonds() 
      && getNumClubs() > getNumSpades())
    {
      return Card::Clubs;
    }
  else if (getNumHearts() > getNumClubs() 
	   && getNumHearts() > getNumDiamonds()
	   && getNumHearts() > getNumSpades())
    {
      return Card::Hearts;
    }
  else if (getNumDiamonds() > getNumHearts()
	   && getNumDiamonds() > getNumClubs()
	   && getNumDiamonds() > getNumSpades())
    {
      return Card::Diamonds;
    }
  else
    {
      return Card::Spades;
    }
}

// gameOverPenalty
// Compute penalty for having cards in hand when the game ends.
// In this implementation, 10 J Q K A cost 10 points.
// Other cards, including Special CrunoCards, are penalized at their
// regular values. 
int CrunoPlayer::gameOverPenalty()
{
  int sum = 0;

  for (unsigned int c = 0 ; c < m_numCards ; c++) 
    {
      if (m_cards[c]->getPoints() < 10) 
	{
	  sum += m_cards[c]->getPoints() ;
	}
      else if (m_cards[c]->getPoints() == 15 || m_cards[c]->getPoints() == 16 ||
	       m_cards[c]->getPoints() == 17)
	{
	  sum += 20;
	}    
      else 
	{
	  sum += 10 ;
	}
    }

  return sum;
}
