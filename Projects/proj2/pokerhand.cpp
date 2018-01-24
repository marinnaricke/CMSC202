/* File:    pokerhand.cpp
   Project: CMSC 202 Project 2, Spring 2016
   Author:  Marinna Ricketts-Uy
   Date:    3/10/16
   Section: 17
   E-mail:  pd12778@umbc.edu
   
   Implementation of PokerHand Class
   See pokerhand.h for documentation
*/


#include <iostream>
using namespace std;

#include "pokerhand.h"

// Default Constructor
PokerHand::PokerHand () 
{
  m_valid = false;
  m_rank = NoRank;
  
  m_lastCardPoints = 0;
  m_firstPairPoints = 0;
  m_secondPairPoints = 0;
  m_tripletPoints = 0;
  m_quadrupletPoints = 0;
}

// Alternate Constructor
PokerHand::PokerHand (Card c0, Card c1, Card c2, Card c3, Card c4) 
{
  // Store cards
  m_cards[0] = c0;
  m_cards[1] = c1;
  m_cards[2] = c2;
  m_cards[3] = c3;
  m_cards[4] = c4;


  // We have cards.
  // Note: this assumes c0, ..., c4 are valid
  //
  m_valid = true;
  m_rank = NoRank;

  // Default values for "additional information"
  //
  m_lastCardPoints = 0;
  m_firstPairPoints = 0;
  m_secondPairPoints = 0;
  m_tripletPoints = 0;
  m_quadrupletPoints = 0;

  // Don't forget to sort
  //
  sort();
  
  // IF YOU WANT THE ALTERNATE CONSTRUCTOR
  // TO DO MORE, PLACE THE CODE AFTER THIS
  // LINE:
  // --------------------------------------
}

// cmp
//  Compare the host hand versus otherHand
//  according to the rules of poker
//
//  Returns a negative number (<0)
//  if host hand loses to the otherHand
//  
//  Returns a positive number (>0)
//  if the host hand beats the otherHand
//
//  Returns zero if it's a tie
int PokerHand::cmp(PokerHand &otherHand)
{
  if (getRank() < otherHand.getRank())
    {
      return LOSE;
    }
  else if (getRank() > otherHand.getRank())
    {
      return WIN;
    }
  else if (getRank() == otherHand.getRank())
    {
      if (isRoyalFlush())
	{
	  return TIE;
	}
      else if (isStraightFlush() || isStraight())
	{
	  return compareCards(4,otherHand);
	}
      else if (isFourOfAKind())
	{
	  if (m_quadrupletPoints > otherHand.GetQuadruplet())
	    {
	      return WIN;
	    }
	  else if (m_quadrupletPoints == otherHand.GetQuadruplet())
	    {
	      if (m_lastCardPoints > otherHand.GetLastCard())
		{
		  return WIN;
		}
	      else if (m_lastCardPoints < otherHand.GetLastCard())
		{
		  return LOSE;
		}
	      else
		{
		  return TIE;
		}
	    }
	}
      else if (isFullHouse())
	{
	  if (m_tripletPoints > otherHand.GetTriplet())
	    {
	      return WIN;
	    }
	  else if (m_tripletPoints == otherHand.GetTriplet())
	    {
	      if(m_firstPairPoints > otherHand.GetFirstPair())
		{
		  return WIN;
		}
	      else if (m_firstPairPoints < otherHand.GetFirstPair())
		{
		  return LOSE;
		}
	      else
		{
		  return TIE;
		}
	    }
	}
      else if (isFlush() || isHighCard())
	{
	  compareCards(4,otherHand);
	}
      else if (isThreeOfAKind())
	{
	  if (m_tripletPoints > otherHand.GetTriplet())
	    {
	      return WIN;
	    }
	  else if (m_tripletPoints == otherHand.GetTriplet())
	    {
	      return compareCards(4,otherHand);
	    }
	  else
	    {
	      return LOSE;
	    }
	}
      else if (isTwoPair())
	{
	  if (m_secondPairPoints > otherHand.GetSecondPair())
	    {
	      return WIN;
	    }
	  else if (m_secondPairPoints == otherHand.GetSecondPair())
	    {
	      if (m_firstPairPoints > otherHand.GetFirstPair())
		{
		  return WIN;
		}
	      else if (m_firstPairPoints == otherHand.GetFirstPair())
		{
		  if (m_lastCardPoints > otherHand.GetLastCard())
		    {
		      return WIN;
		    }
		  else if (m_lastCardPoints < otherHand.GetLastCard())
		    {
		      return LOSE;
		    }
		  else 
		    {
		      return TIE;
		    }
		}
	      else 
		{
		  return LOSE;
		}
	    }
	  else 
	    {
	      return LOSE;
	    }
	}
      else if (isOnePair())
	{
	  if (m_firstPairPoints > otherHand.GetFirstPair())
	    {
	      return WIN;
	    }
	  else if (m_firstPairPoints == otherHand.GetFirstPair())
	    {
	      return compareCards(4,otherHand);
	    }
	  else
	    {
	      return LOSE;
	    }
	}
    }
  return 0;
}

// printRank
//  Prints out the rank to standard output
void PokerHand::printRank()
{
  getRank();

  switch(m_rank)
    {
    case 1:
      cout << "High Card" << endl;
      break;
    case 2:
      cout << "One Pair" << endl;
      break;
    case 3:
      cout << "Two Pair" << endl;
      break;
    case 4:
      cout << "Three Of A Kind" << endl;
      break;
    case 5:
      cout << "Straight" << endl;
      break;
    case 6:
      cout << "Flush" << endl;
      break;
    case 7:
      cout << "Full House" << endl;
      break;
    case 8:
      cout << "Four Of A Kind" << endl;
      break;
    case 9:
      cout << "Straight Flush" << endl;
      break;
    case 10:
      cout << "Royal Flush" << endl;
      break;
    default:
      cout << "No Rank" << endl;
      break;
      }
   
}

// printCards
//  Prints out the FIVE cards to standard output
//  one card per line.
void PokerHand::printCards()
{
  for (int i = 0; i < FIVE; i++)
    {
      m_cards[i].print();
    }
}

// getRank
//  Return the rank of this hand
//  If hand is not valid, should return NoRank
//  Should use rank stored in m_rank, if available
PokerHand::pRank PokerHand::getRank()
{
  isRoyalFlush();
  isStraightFlush();
  isFourOfAKind();
  isFullHouse();
  isFlush();
  isStraight();
  isThreeOfAKind();
  isTwoPair();
  isOnePair();
  isHighCard();

  // if one of the cards are invalid, hand has no rank
  if (m_cards[0].points() == 0 || m_cards[1].points() == 0 ||
      m_cards[2].points() == 0 || m_cards[3].points() == 0 ||
      m_cards[4].points() == 0)
    {
      m_rank = NoRank;
    }

  return m_rank;
}

// isRoyalFlush
//  Returns true if the hand is a Royal Flush
bool PokerHand::isRoyalFlush()
{
  if (isAllOneSuit())
    {
      if(m_cards[0].points() == 10 &&
	 m_cards[1].points() == 11 &&
	 m_cards[2].points() == 12 &&
	 m_cards[3].points() == 13 &&
	 m_cards[4].points() == 14)
	{
	  m_rank = RoyalFlush;
	  return true;
	}
    }
  return false;
}

// isStraighFlush
//  Returns true if the hand is a Straight Flush
bool PokerHand::isStraightFlush()
{
  if (isAllOneSuit())
     {
       if(isSequence() == true)
	 {
	   if(m_cards[0].points() != 10 &&
	      m_cards[1].points() != 11 &&
	      m_cards[2].points() != 12 &&
	      m_cards[3].points() != 13 &&
	      m_cards[4].points() != 14) 
	     {
	       m_rank = StraightFlush;
	       return true;
	     }
	 }
     }
  return false;
}

// isFourOfAKind
//  Returns true if the hand is Four of a Kind
//  Sets m_quadrupletPoints and m_lastCardPoints
bool PokerHand::isFourOfAKind()
{
  // if pattern is 1-4
  if (m_cards[0].points() != m_cards[1].points() &&
      m_cards[1].points() == m_cards[2].points() &&
      m_cards[2].points() == m_cards[3].points() &&
      m_cards[3].points() == m_cards[4].points())
    {
      // Sets the points for the pair of four
      m_quadrupletPoints = m_cards[4].points();
      
      // Sets the points for the remaining card
      m_lastCardPoints = m_cards[0].points();
      m_rank = FourOfAKind;
      return true;
    }
  // if pattern is 4-1
  else if (m_cards[0].points() == m_cards[1].points() &&
	   m_cards[1].points() == m_cards[2].points() &&
	   m_cards[2].points() == m_cards[3].points() &&
	   m_cards[3].points() != m_cards[4].points())
    {
      m_quadrupletPoints = m_cards[0].points();
      m_lastCardPoints = m_cards[4].points();
      m_rank = FourOfAKind;
      return true;
    }
  return false;
 
}

// isFullHouse
//  Returns true if the hand is a Full House
//  Sets m_tripletPoints and m_firstPairPoints
bool PokerHand::isFullHouse()
{
  // if pattern is 3-2
  if (m_cards[0].points() == m_cards[1].points() &&
      m_cards[1].points() == m_cards[2].points() &&
      m_cards[2].points() != m_cards[3].points() &&
      m_cards[3].points() == m_cards[4].points())
    {
      // Sets the points for the pair of three
      m_tripletPoints = m_cards[2].points();

      // Sets the points for the pair of two 
      m_firstPairPoints = m_cards[4].points();
      m_rank = FullHouse;
      return true;
    }
  // if pattern is 2-3
  else if (m_cards[0].points() == m_cards[1].points() &&
	   m_cards[1].points() != m_cards[2].points() &&
	   m_cards[2].points() == m_cards[3].points() &&
	   m_cards[3].points() == m_cards[4].points())
    {
      m_tripletPoints = m_cards[4].points();
      m_firstPairPoints = m_cards[1].points();
      m_rank = FullHouse;
      return true;
    }      
  return false;
}

// isFlush
//  Returns true if the hand is a Flush
bool PokerHand::isFlush()
{
  if (isAllOneSuit())
    {
      if (isSequence() == false)
	{
	  m_rank = Flush;
	  return true;
	}
    }
  return false;
}

// isStraight
//  Returns true if the hand is a Straight
bool PokerHand::isStraight()
{
  if (isSequence())
    {
      if (isAllOneSuit() == false)
	{
	  m_rank = Straight;
	  return true;
	}
    }
  return false;
}

// isThreeOfAKind
//  Returns true if the hand is Three of a Kind
//  Sets m_tripletPoints
bool PokerHand::isThreeOfAKind()
{
  // if pattern is 3-1-1
  if (m_cards[0].points() == m_cards[1].points() &&
      m_cards[1].points() == m_cards[2].points() &&
      m_cards[2].points() != m_cards[3].points() &&
      m_cards[3].points() != m_cards[4].points())
    {
      // Sets the points for the pair of three
      m_tripletPoints = m_cards[2].points();
      m_rank = ThreeOfAKind;
      return true;
    }
  // if pattern is 1-1-3
  else if (m_cards[0].points() != m_cards[1].points() &&
	   m_cards[1].points() != m_cards[2].points() &&
	   m_cards[2].points() == m_cards[3].points() &&
	   m_cards[3].points() == m_cards[4].points())
    {
      m_tripletPoints = m_cards[4].points();
      m_rank = ThreeOfAKind;
      return true;
    }
  // if pattern is 1-3-1
  else if (m_cards[0].points() != m_cards[1].points() &&
	   m_cards[1].points() == m_cards[2].points() &&
	   m_cards[2].points() == m_cards[3].points() &&
	   m_cards[3].points() != m_cards[4].points())
    {
      m_tripletPoints = m_cards[3].points();
      m_rank = ThreeOfAKind;
      return true;
    }
  return false;
}

// isTwoPair
//  Returns true is the hand is a Two Pair
//  Sets m_firstPairPoints, m_secondPairPoints and
//  m_lastCardPoints
bool PokerHand::isTwoPair()
{
  // if pattern is 2-2-1
  if (m_cards[0].points() == m_cards[1].points() &&
      m_cards[1].points() != m_cards[2].points() &&
      m_cards[2].points() == m_cards[3].points() &&
      m_cards[3].points() != m_cards[4].points())
    {
      // Sets the points for the lower pair of two
      m_firstPairPoints = m_cards[1].points();

      // Sets the points for the higher pair of two
      m_secondPairPoints = m_cards[3].points();

      // Sets the points for the remaining card
      m_lastCardPoints = m_cards[4].points();
      m_rank = TwoPair;
      return true;
    }
  // if pattern is 1-2-2
  else if (m_cards[0].points() != m_cards[1].points() &&
	   m_cards[1].points() == m_cards[2].points() &&
	   m_cards[2].points() != m_cards[3].points() &&
	   m_cards[3].points() == m_cards[4].points())
    {
      m_firstPairPoints = m_cards[2].points();
      m_secondPairPoints = m_cards[4].points();
      m_lastCardPoints = m_cards[0].points();
      m_rank = TwoPair;
      return true;
    }
  // if pattern is 2-1-2
  else if (m_cards[0].points() == m_cards[1].points() &&
	   m_cards[1].points() != m_cards[2].points() &&
	   m_cards[2].points() != m_cards[3].points() &&
	   m_cards[3].points() == m_cards[4].points())
    {
      m_firstPairPoints = m_cards[1].points();
      m_secondPairPoints = m_cards[4].points();
      m_lastCardPoints = m_cards[2].points();
      m_rank = TwoPair;
      return true;
    }
  return false;
}

// isOnePair
//  Returns true if the hand is a One Pair
//  Sets m_firstPairPoints
bool PokerHand::isOnePair()
{
  // if pattern is 2-1-1-1
  if (m_cards[0].points() == m_cards[1].points() &&
      m_cards[1].points() != m_cards[2].points() &&
      m_cards[2].points() != m_cards[3].points() &&
      m_cards[3].points() != m_cards[4].points())
    {
      // Sets the points for the pair of two
      m_firstPairPoints = m_cards[1].points();
      m_rank = OnePair;
      return true;
    }
  // if pattern is 1-1-1-2
  else if (m_cards[0].points() != m_cards[1].points() &&
	   m_cards[1].points() != m_cards[2].points() &&
	   m_cards[2].points() != m_cards[3].points() &&
	   m_cards[3].points() == m_cards[4].points())
    {
      m_firstPairPoints = m_cards[4].points();
      m_rank = OnePair;
      return true;
    }
  // if pattern is 1-2-1-1
  else if (m_cards[0].points() != m_cards[1].points() &&
	   m_cards[1].points() == m_cards[2].points() &&
	   m_cards[2].points() != m_cards[3].points() &&
	   m_cards[3].points() != m_cards[4].points())
    {
      m_firstPairPoints = m_cards[2].points();
      m_rank = OnePair;
      return true;
    }
  // if pattern is 1-1-2-1
  else if (m_cards[0].points() != m_cards[1].points() &&
	   m_cards[1].points() != m_cards[2].points() &&
	   m_cards[2].points() == m_cards[3].points() &&
	   m_cards[3].points() != m_cards[4].points())
    {
      m_firstPairPoints = m_cards[3].points();
      m_rank = OnePair;
      return true;
    }
  return false;
}

// isHighCard
//  Returns true if the hand is High Card
//  Means it isn't anything else
bool PokerHand::isHighCard()
{
  if(isRoyalFlush() == false && isStraightFlush() == false &&
     isFourOfAKind() == false && isFullHouse() == false &&
     isFlush() == false && isStraight() == false &&
     isThreeOfAKind() == false && isTwoPair() == false && 
     isOnePair() == false)
    {
      m_rank = HighCard;
      return true;
    }
  return false;
}

// sort
//  Sort the hand by point value
//  The cards' suits are not considered in the sort
void PokerHand::sort()
{
  Card temp;

  // Sorts the card hand in ascending order
  for (int i = 0; i < FIVE; i++)
    {
      for (int j = 0; j < FIVE; j++)
	{
	  if (m_cards[i].points() < m_cards[j].points())
	    {
	      temp = m_cards[i];
	      m_cards[i] = m_cards[j];
	      m_cards[j] = temp;
	    }
	}
    }
}

// isAllOneSuit
//  Returns true if the cards in the hand
//  have the same suit
bool PokerHand::isAllOneSuit()
{
  if (m_cards[0].suit() == m_cards[1].suit() &&
      m_cards[1].suit() == m_cards[2].suit() &&
      m_cards[2].suit() == m_cards[3].suit() &&
      m_cards[3].suit() == m_cards[4].suit())
    {
      return true;
    }
  return false;
}

// isSequence
//  Returns true if the hand is five
//  cards in an sequence
bool PokerHand::isSequence()
{
  if ( (m_cards[0].points() + 1) == m_cards[1].points() &&
       (m_cards[1].points() + 1) == m_cards[2].points() &&
       (m_cards[2].points() + 1) == m_cards[3].points() &&
       (m_cards[3].points() + 1) == m_cards[4].points())
    {
      return true;
    }
  return false;
}

// compareCards
//  Compares each card in descending order from given index
//  Returns 1,-1, or 0
int PokerHand::compareCards(int index, PokerHand &otherHand)
{
  int counter = 0;
  // three different outcomes (WIN,LOSE, or TIE)
  int outcome;
 
  // Compares the points value of two cards, if the point values are
  //  equal then it checks the next cards down.
  while (index != -1)
    {
      if (m_cards[index].points() > otherHand.m_cards[index].points())
	{
	  outcome = WIN;
	  index = -1;
	}
      else if (m_cards[index].points() < otherHand.m_cards[index].points())
	{
	  outcome = LOSE;
	  index = -1;
	}
      else
	{
	  counter = counter + 1;
	  index = index - 1;
	}
    }

  if (counter == 5)
    {
      outcome = TIE;
    }

  return outcome;
}  


// GetLastCard
//  Returns the point value of the last card
Card::cPoints PokerHand::GetLastCard()
{
  return m_lastCardPoints;
}

// GetFirstPair
//  Returns the point value of the first pair
Card::cPoints PokerHand::GetFirstPair()
{
  return m_firstPairPoints;
}

// GetSecondPair
//  Returns the point value of the second pair
Card::cPoints PokerHand::GetSecondPair()
{
  return m_secondPairPoints;
}

// GetTriplet
//  Returns the point value of the three pair
Card::cPoints PokerHand::GetTriplet()
{
  return m_tripletPoints;
}

// GetQuadruplet
//  Returns the point value of the four pair
Card::cPoints PokerHand::GetQuadruplet()
{
  return m_quadrupletPoints;
}

