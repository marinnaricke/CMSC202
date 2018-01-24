/* File:    card.cpp
   Project: CMSC 202 Project 2, Spring 2016
   Author:  Marinna Ricketts-Uy
   Date:    3/10/16
   Section: 17
   E-mail:  pd12778@umbc.edu

   Implementation of Card member functions.
   See card.h for documentation
*/

#include <iostream>
#include "card.h"

using namespace std ;


// Default constructor - marks card as invalid
Card::Card() 
{
  m_suit = Invalid;
  m_points = 0;
}

// Alternate constructor - to make sure only meaningful values
//  are stored in a card
Card::Card(cSuit s, cPoints p) 
{
  if ( p > 1 && p <= 14)
    {
      m_suit = s;
      m_points = p;
    }
  else
    {
      m_suit = Invalid;
      m_points = 0;
    }
}

// points
//  Returns the value of the card
Card::cPoints Card::points() 
{
  return m_points;
}

// suit
//  Returns the suit of the card
Card::cSuit Card::suit() 
{
  return m_suit;
}

// print
//  Prints a description of the host Card to standard output
void Card::print() 
{

   if (m_points == 11)
    {
      if (m_suit == 1)
	{
	  cout << "Jack of Clubs" << endl;
	}
      else if (m_suit == 2)
	{
	  cout << "Jack of Diamonds" << endl;
	}
      else if (m_suit == 3)
	{
	  cout << "Jack of Hearts" << endl;
	}
      else
	{
	  cout << "Jack of Spades" << endl;
	} 
    }
  else if (m_points == 12)
    {
       if (m_suit == 1)
	{
	  cout << "Queen of Clubs" << endl;
	}
      else if (m_suit == 2)
	{
	  cout << "Queen of Diamonds" << endl;
	}
      else if (m_suit == 3)
	{
	  cout << "Queen of Hearts" << endl;
	}
      else
	{
	  cout << "Queen of Spades" << endl;
	} 
    }
  else if (m_points == 13)
    {
       if (m_suit == 1)
	{
	  cout << "King of Clubs" << endl;
	}
      else if (m_suit == 2)
	{
	  cout << "King of Diamonds" << endl;
	}
      else if (m_suit == 3)
	{
	  cout << "King of Hearts" << endl;
	}
      else
	{
	  cout << "King of Spades" << endl;
	} 
    }
  else if (m_points == 14)
    {
      if (m_suit == 1)
	{
	  cout << "Ace of Clubs" << endl;
	}
      else if (m_suit == 2)
	{
	  cout << "Ace of Diamonds" << endl;
	}
      else if (m_suit == 3)
	{
	  cout << "Ace of Hearts" << endl;
	}
      else
	{
	  cout << "Ace of Spades" << endl;
	}
    }
  else if (m_points == 0)
    {
      cout << m_points << " of Invalid" << endl;
    }
  else
    {
      if (m_suit == 1)
	{
	  cout << m_points << " of Clubs" << endl;
	}
      else if (m_suit == 2)
	{
	  cout << m_points << " of Diamonds" << endl;
	}
      else if (m_suit == 3)
	{
	  cout << m_points << " of Hearts" << endl;
	}
      else
	{
	  cout << m_points << " of Spades" << endl;
	}
    }
}
