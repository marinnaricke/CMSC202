/* File: CrunoGame.cpp
   Project: CMSC 202 Project 4, Spring 2016
   Author: Marinna Ricketts-Uy
   Date: 4/21/16
   Section: 17
   E-mail: pd12778@umbc.edu
*/

#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

#include "CrunoSkip.h"
#include "CrunoReverse.h"
#include "CrunoDraw2.h"
#include "Cruno8.h"
#include "CrunoGame.h"

// Default Constructor
// Sets action and Calls Game constructor
CrunoGame::CrunoGame()
{
  Game::Game();
}

// initialize
// Checks number of players and add cards to the game
void CrunoGame::initialize(int numPlayers)
{
  m_suit = 0;
  m_points = 0;
  m_currentPlayer = 0;
  m_timesReversed = 0;
  
  // can't play by yourself
  //
  if (numPlayers < 2)
    {
      cerr << "Insufficient players\n";
      exit(1);
    }

  // not enough cards to make it fun for >10
  //
  if (numPlayers > 10)
    {
      cerr << "Too many players\n";
      exit(1);
    }

  m_numPlayers = 0; // no players added yet.

  // allocate space for max requested
  //
  m_maxPlayers = numPlayers;
  m_players = new Player *[numPlayers];

  m_winner = m_maxPlayers + 1; // not a real player

  // usually use just one deck
  int decks = 1;
  m_maxCards = 76; // added 24 because of action cards
  
  if (numPlayers > 5)
    {
      // use two decks
      decks = 2;
      m_maxCards = 152; // two 76 card decks
    }

  // allocate space for discard pile
  m_discard = new Card *[m_maxCards];
  m_numDiscard = 0;

  // allocate space for stock pile
  m_stock = new Card *[m_maxCards];

  int i = 0; // next available slot in m_stock[]
  int a;

  for (int d = 0; d < decks ; d++) // # of decks
    {

      // iterate over suits
      for (unsigned int s = Card::Clubs; s <= Card::Spades; s++)
	{
	  // iterate over points values
	  for (unsigned int p = 2; p <= Card::Ace; p++)
	    {
	      if (p == 8)
		{
		  m_stock[i] = new Cruno8(s,p); // insert Cruno8 card
		}
	      else 
		{
		  m_stock[i] = new Card(s,p); // insert new Card
		}
	      i++;
	    }
	  
	  // Add the action cards, 2 per suit
	  //
	  for (a = 0; a < PER_SUIT; a++)
	    {
	      // insert CrunoSkip card
	      m_stock[i] = new CrunoSkip(s, CrunoSkip::SKIP); 
	      i++;
	    }
	  
	  for (a = 0; a < PER_SUIT; a++)
	    {
	      // insert CrunoReverse card
	      m_stock[i] = new CrunoReverse(s, CrunoReverse::REVERSE); 
	      i++;
	    } 
	  
	  for (a = 0; a < PER_SUIT; a++)
	    {
	      // insert CrunoDraw2 card
	      m_stock[i] = new CrunoDraw2(s, CrunoDraw2::DRAW_2); 
	      i++;
	    }
	}
    }

  // remember how many cards we added
  m_numStock = m_maxCards;

  // Still haven't started (need to have players added)
  m_started = false;
  m_over = false;
}

// timesReversed
// keeps track of how many times a skip card was played
void CrunoGame::timesReversed(int num)
{
  m_timesReversed = m_timesReversed + num;
}

// nextPlayer
// 
unsigned int CrunoGame::nextPlayer()
{
  // If the number of times a CrunoReverse card was played is even
  // then the direction of player is clockwise. 
  if (m_timesReversed % 2 == 0)
    {
      // If the current card that was just played was a CrunoSkip,
      // the next player loses their turn
      if (m_points == CrunoSkip::SKIP)
	{
	  m_currentPlayer = (m_currentPlayer + 1) % m_numPlayers;
	  m_currentPlayer = (m_currentPlayer + 1) % m_numPlayers;
	  return m_currentPlayer;
	}
      else
	{
	  m_currentPlayer = (m_currentPlayer + 1) % m_numPlayers;
	  return m_currentPlayer;
	}
    }
  else
    {
      // Reverses the direction to be counter-clockwise
      m_currentPlayer = (m_currentPlayer - 1) % m_numPlayers;
      return m_currentPlayer;
    }
}

// playerAfter
//
unsigned int CrunoGame::playerAfter(unsigned int thisPlayer)
{
  // Similar to nextPlayer, direction is clockwise if divisible by 2
  if (m_timesReversed % 2 == 0)
    {
      return (thisPlayer + 1) % m_numPlayers;
    }
  else
    {
      return (thisPlayer - 1) % m_numPlayers;
    }

}

// dealOneCard
// when the stock runs out, shuffle the discard pile to make
// a new stock (except the last card played remains in the discard pile
Card * CrunoGame::dealOneCard()
{
  Card *cptr, *temp;
  unsigned int s, p;
  int j;

  if (m_numStock < 1)
    {
      if (m_numDiscard < 1)
	{
	  m_over = true;
	  return NULL;
	}
      else 
	{
	  //testing
	  cout << "Shuffling the discard pile and " \
	       << "creating a new stock pile: " << endl;
	  
	  m_stock = new Card *[m_numDiscard - 2];
	  m_numStock = m_numDiscard - 2;

	  for (unsigned int i = 0; i < (m_numDiscard - 2); i++)
	    {
	      
	      s = m_discard[i]->getSuit();
	      p = m_discard[i]->getPoints();

	      if (p == CrunoDraw2::DRAW_2)
		{
		  m_stock[i] = new CrunoDraw2(s,CrunoDraw2::DRAW_2);
		}
	      else if (p == CrunoSkip::SKIP)
		{
		  m_stock[i] = new CrunoSkip(s,CrunoSkip::SKIP);
		}
	      else if (p == CrunoReverse::REVERSE)
		{
		  m_stock[i] = new CrunoReverse(s,CrunoReverse::REVERSE);
		}
	      else 
		{
		  m_stock[i] = new Card(s,p);
		}
	    }

	  // Set discard pile to last played card
	  temp = m_discard[m_numDiscard - 1];
	  m_discard = new Card*[m_maxCards];
	  m_discard[0] = temp;

	  //Shuffle stock pile
	  for (unsigned int i = 0; i < m_numStock; i++)
	    {
	      Card *tempC;
	      
	      j = rand() % m_numStock;
	      tempC = m_stock[i];
	      m_stock[i] = m_stock[j];
	      m_stock[j] = tempC;
	    }

	  m_numStock--;
	  cptr = m_stock[m_numStock];
	  m_stock[m_numStock] = NULL;

	  return cptr; 
	}
    }
  else
    {
      m_numStock--;
      cptr = m_stock[m_numStock];
      m_stock[m_numStock] = NULL;

      return cptr;
    }
}

// getPlayer
// Returns a Player pointer
Player * CrunoGame::getPlayer(unsigned int p)
{
  return m_players[p];
}
