/* File:    pokerhand.h
   Project: CMSC 202 Project 2, Spring 2016
   Author:  Marinna Ricketts-Uy
   Date:    3/10/16
   Section: 17
   E-mail:  pd12778@umbc.edu

   Class definition of PokerHand Class

   *** YOU MAY ADD PRIVATE HELPER FUNCTIONS ***
   *** DO NOT CHANGE OTHER PARTS OF THIS FILE ***
*/

#ifndef _POKERHAND_H_
#define _POKERHAND_H_

#include "card.h"

class PokerHand 
{

 public:

  // Avoiding magic numbers.
  // Note: must use PokerHand::FIVE outside member functions.
  //
  static const int FIVE = 5 ;
  static const int WIN = 1;
  static const int LOSE = -1;
  static const int TIE = 0;


  // All possible ranks in poker in an enumeration type.
  //
  // A rank of NoRank indicates that the hand is not valid
  // or that the hand has not been evaluated.
  //
  // Note: outside member functions must use refer to this type
  // PokerHand::pRank and use constants PokerHand::RoyalFlush ...
  //
  typedef enum { NoRank, HighCard, OnePair, TwoPair, ThreeOfAKind,
		 Straight, Flush, FullHouse, FourOfAKind, StraightFlush,
		 RoyalFlush } pRank ;


  // Default constructor.
  //
  // We allow a blank PokerHand to be created.
  // However, the default constructor should make sure
  // that m_valid is false and m_rank is NoRank.
  //
  PokerHand() ;


  // Alternate constructor.
  //
  // The alternate constructor should store the FIVE cards
  // given as parameters in the m_cards[] array.
  // It should also immediately evaluate the hand, determine
  // its rank and compute the additonal information (see below).
  //
  // Note: this constructor does not check for validity between
  // cards. For example, the hand created might have two Queen
  // of Hearts.
  //
  PokerHand(Card c0, Card c1, Card c2, Card c3, Card c4) ;

  // Name: cmp
  // PreCondition: otherHand is a sorted array with card objects
  // PostCondition: Returns an integer value (WIN = 1, LOSE = -1, TIE = 0)
  int cmp(PokerHand &otherHand) ;


  // Name: printRank
  // PreCondition: No precondition
  // PostCondition: Prints out the rank to standard output
  void printRank() ;


  // Name: printCards
  // PreCondition: No precondition
  // PostCondition: Prints out the FIVE cards to standard output
  //  one per line
  void printCards() ;


  // Name: getRank
  // PreCondition: No precondition
  // PostCondition: Returns the rank of the hand
  pRank getRank() ;


  // The following "isRank()" functions should all:
  // 1. Assume that the hand is already sorted.
  // 2. If true, store the rank in m_rank.
  // 3. If true, store the "additional information" 
  //    for that rank,
  // 4. Use the rank if m_rank, if available.


  // Name: isRoyalFlush
  // PreCondition: m_cards is a sorted array
  // PostCondition: Returns true if m_cards is a RoyalFlush and
  //  sets the rank to RoyalFlush
  bool isRoyalFlush() ;

   
  // Name: isStraightFlush
  // PreCondition: m_cards is a sorted array
  // PostCondition: Returns true if m_cards is a RoyalFlush and
  //  sets the rank to StraightFlush
  bool isStraightFlush() ;

 
  // Name: isFourOfAKind
  // PreCondition: m_cards is a sorted array
  // PostCondition: Returns true if m_cards is a FourOfAKind,
  //  sets m_quadrupletPoints and m_lastCardPoints,
  //  and sets the rank to FourOfAKind
  bool isFourOfAKind() ;


  // Name: isFullHouse
  // PreCondition: m_cards is a sorted array
  // PostCondition: Returns true if m_cards is a FullHouse,
  //  sets m_tripletPoints and m_firstPairPoints,
  //  and sets the rank to FullHouse               
  bool isFullHouse() ;


  // Name: isFlush
  // PreCondition: m_cards is a sorted array
  // PostCondition: Returns true if m_cards is a Flush,
  //  and sets the rank to Flush
  bool isFlush() ;


  // Name: isStraight
  // PreCondition: m_cards is a sorted array
  // PostCondition: Returns true if m_cards is a Straight,
  //  and sets the rank to Straight
  bool isStraight() ;


  // Name: isThreeOfAKind
  // PreCondition: m_cards is a sorted array
  // PostCondition: Returns true if m_cards is a ThreeOfAKind,
  //  sets m_tripletPoints and sets the rank to ThreeOfAKind
  bool isThreeOfAKind() ;


  // Name: isTwoPair
  // PreCondition: m_cards is a sorted array
  // PostCondition: Returns true if m_cards is a TwoPair,
  //  sets m_firstPairPoints, m_secondPairPoints, and m_lastCardPoints,
  //  and sets the rank to TwoPair
  bool isTwoPair() ;


  // Name: isOnePair
  // PreCondition: m_cards is a sorted array
  // PostCondition: Returns true if m_cards is a OnePair,
  //  sets m_firstPairPoints, and sets the rank to OnePair
  bool isOnePair() ;


  // Name: isHighCard
  // PreCondition: m_cards is a sorted array
  // PostCondition: Returns true if m_cards is a HighCard,
  //  and sets the rank to HighCard
  bool isHighCard() ;
 
private:

  Card m_cards[FIVE] ;   // holds the FIVE cards in this poker hand
  bool m_valid ;         // false if no cards assigned
  pRank m_rank ;         // stored rank


  // The data members below hold some additional information 
  // for this hand that must be computed by evaluate().
  // This information makes it possible to compare two
  // hands when the ranks are equal. For example, if both
  // hands are Two Pair, use m_firstPairPoints to see which
  // hand has higher points for the top pair. If that's a tie,
  // check m_secondPairPoints. If that is also a tie, then
  // use m_lastCardPoints.
  //


  // For Two Pair and Four of a Kind, the point value of the 
  // last card
  //
  Card::cPoints m_lastCardPoints ;    


  // For One Pair, the point value of the pair.   
  // For Two Pair, the point value of the higher pair.
  // For Full House, the point value of the pair.
  //
  Card::cPoints m_firstPairPoints ;


  // For Two Pair, the point value of the lower pair.
  //
  Card::cPoints m_secondPairPoints ;


  // For Full House and Three of a Kind, the point value
  // of the triple.
  //
  Card::cPoints m_tripletPoints ;


  // For Four of a Kind, the point value of the four.
  //
  Card::cPoints m_quadrupletPoints ;


  // Name: sort
  // PreCondition: m_cards array contains FIVE card objects
  // PostCondition: The m_cards array is sorted
  //  in ascending order by the point value of each card
  void sort() ;


  // Some helper functions
  // These helper functions assume that the
  // hand is already sorted.

  // Name: isAllOneSuit
  // PreCondition: m_cards is a sorted array
  // PostCondition: Returns true if the cards in the hand
  //  have the same suit
  bool isAllOneSuit() ;


  // Name: isSequence
  // PreCondition: m_cards is a sorted array
  // PostCondition: Returns true if the cards in m_cards
  //  are in sequential order
  bool isSequence() ;

  //End of helper functions

  // -----------------------------------------
  // IF YOU WANT TO ADD MORE HELPER FUNCTIONS,
  // PUT THEIR DECLARATIONS AFTER THIS LINE.
  // -----------------------------------------

  // Name: compareCards
  // PreCondition: Index is greater than -1, both arrays are sorted
  // PostCondition: Returns an integer value (WIN = 1, LOSE = -1, TIE = 0)
  int compareCards(int index,PokerHand &otherHand);

  // Name: GetLastCard
  // PreCondition: No precondition
  // PostCondtition: Returns the points of the remaining card
  Card::cPoints GetLastCard();

  // Name: GetFirstPair
  // PreCondition: No precondition
  // PostCondition: Returns the points of a pair
  Card::cPoints GetFirstPair();
  
  // Name: GetSecondPair
  // PreCondition: No precondition
  // PostCondition: Returns the points of a pair (higher pair)
  Card::cPoints GetSecondPair();

  // Name: GetTriplet
  // PreCondition: No precondition
  // PostCondition: Returns the points of three equal cards
  Card::cPoints GetTriplet();

  // Name: GetQuadruplet
  // PreCondition: No precondition
  // PostCondition: Returns the points of four equal cards
  Card::cPoints GetQuadruplet();

} ;


#endif
