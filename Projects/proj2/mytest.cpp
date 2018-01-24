/* File:    mytest.cpp
   Project: CMSC 202 Project 2, Spring 2016
   Author:  Marinna Ricketts-Uy
   Date:    3/10/16
   Section: 17
   E-mail:  pd12778@umbc.edu

   This file tests the working parts of my project. 
   This file uses both the Card class and PokerHand class
*/

#include <iostream>
using namespace std;

#include "pokerhand.h"
#include "card.h"

int main()
{
  // Picking 5 cards for host hand
  Card c0(Card::Spades, 0);
  Card c1(Card::Spades, 7);
  Card c2(Card::Hearts, 6);
  Card c3(Card::Hearts, 5);
  Card c4(Card::Spades, 4);
  
  // Picking 5 cards for otherHand
  Card d0(Card::Hearts, 0);
  Card d1(Card::Diamonds, 7);
  Card d2(Card::Clubs, 6);
  Card d3(Card::Clubs, 5);
  Card d4(Card::Hearts, 4);
  
  // --------- Creating the PokerHand or the m_cards array ----------
  PokerHand myHand(c0,c1,c2,c3,c4);
  PokerHand yourHand(d0,d1,d2,d3,d4);

  // -------- Print Cards ----------
  cout << "\nHere are the cards I chose: " << endl;
  myHand.printCards();
  cout << endl;

  cout << "Here are the cards that you chose: " << endl;
  yourHand.printCards();

  // -------- Print the ranks of each hand ---------- 
  // The printRank function uses the getRank() function
  // The getRank() function uses all of the boolean isRank() functions
  cout << "\nMy hand is a ";
  myHand.printRank();
  cout << endl;

  cout << "Your hand is a ";
  yourHand.printRank();
  cout << endl;

  // ------- Comparing host hand and otherHand -------
  cout << "The outcome is: " << endl;
  if (myHand.cmp(yourHand) > 0)
    {
      cout << "My hand beats yours. HAHA! \n";
    }
  else if (myHand.cmp(yourHand) < 0)
    {
      cout << "Your hand beats mine. :( \n";
    }
  else
    {
      cout << "Our hands are tied. WE BOTH WIN!\n";
    }

  return 0;
}

