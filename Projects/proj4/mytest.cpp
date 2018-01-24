/* File: mytest.cpp
   Project: CMSC 202 Project 4, Spring 2016
   Author: Marinna Ricketts-Uy
   Date: 4/21/16
   Section: 17
   E-mail: pd12778@umbc.edu
*/

#include <iostream>
using namespace std;

#include "game.h"
#include "card.h"
#include "CrunoGame.h"
#include "Cruno8.h"
#include "CrunoSkip.h"
#include "CrunoReverse.h"
#include "CrunoDraw2.h"
#include "player.h"
#include "CrunoPlayer.h"

int main()
{

  //***** Tests the Game with 6 players *****
  Game *gptr1 = new CrunoGame();

  gptr1->initialize(6);

  int n = gptr1->getNumCards();
  Player *pptr1 = new CrunoPlayer(gptr1, n);
  Player *pptr2 = new CrunoPlayer(gptr1, n);
  Player *pptr3 = new CrunoPlayer(gptr1, n);
  Player *pptr4 = new CrunoPlayer(gptr1, n);
  Player *pptr5 = new CrunoPlayer(gptr1, n);
  Player *pptr6 = new CrunoPlayer(gptr1, n);

  gptr1->addPlayer(pptr1);
  gptr1->addPlayer(pptr2);
  gptr1->addPlayer(pptr3);
  gptr1->addPlayer(pptr4);
  gptr1->addPlayer(pptr5);
  gptr1->addPlayer(pptr6);

  gptr1->startGame(8132987);

  delete gptr1;

  /*
  Game *gptr = new CrunoGame();

  gptr->initialize(3); //test with three players

  int n = gptr->getNumCards();

  // for testing purposes
  //cout << "The number of cards in stockpile: " << n << endl;

  Player *pptr1 = new CrunoPlayer(gptr,n);
  Player *pptr2 = new CrunoPlayer(gptr,n);
  Player *pptr3 = new CrunoPlayer(gptr,n);

  //Have to add players before starting the game
  gptr->addPlayer(pptr1);
  gptr->addPlayer(pptr2);
  gptr->addPlayer(pptr3);

  //Diamonds
  Card *cptr1 = new Card(2,6);
  Card *cptr2 = new Card(2,5);

  //Clubs
  Card *cptr3 = new Cruno8(1,8);

  pptr1->takeCard(cptr1);
  pptr1->takeCard(cptr2);

  cout << "Player 0 hand: " << endl;
  pptr1->dump();

  //***** TESTING CRUNO8 CARD ******
  cout << "\nTesting CRUNO8 Card" << endl;
  cout << "----------------------------\n" ;
  //Lets say player 0 gets dealt a Cruno8
  pptr1->takeCard(cptr3);

  cout << "Player 0 takes a " << cptr3->toString() << endl; 

  //Now the Player uses the Cruno8 card
  cptr3->playCard(gptr,pptr1);
  
  cout << "Suit choosen for Cruno8 should be Diamonds or 2" << endl;
  cout << "So now the current suit is " << gptr->currentSuit() << endl;
  cout << "----------------------------\n" ;
  //********************
  
  //**** TESTING CRUNODRAW2 CARD *****
  cout << "\nTesting CRUNODRAW2 Card" << endl;
  cout << "----------------------------\n" ;
  // Lets say player 0 gets dealt a CrunoDraw2 of Clubs
  Card *cptr4 = new CrunoDraw2(1, CrunoDraw2::DRAW_2);
  pptr1->takeCard(cptr4);
  cout << "Player 0 takes a " << cptr4->toString() << endl;

  // Since the currentSuit is Diamonds and there is no currentAction
  // The card CrunoDraw2 with suit Clubs should not be playable
  cout << "This should print out 0" << endl;
  cout << "Prints out: " << cptr4->playable(gptr) << endl;

  // Then lets say Player 0 gets dealt a CrunoDraw2 of Diamonds
  Card *cptr5 = new CrunoDraw2(2, CrunoDraw2::DRAW_2);
  pptr1->takeCard(cptr5);
  cout << "Player 0 takes a " << cptr5->toString() << endl;

  // Since the currentSuit is Diamonds, should be playable
  cout << "This should print out 1" << endl;
  cout << "Prints out: " << cptr5->playable(gptr) << endl;
  
  // Now we are playing the card, CrunoDraw2 of Diamonds
  cout << "Player 0 plays the Draw2 card" << endl;
  cptr5->playCard(gptr,pptr1);
  
  cout << "This is now what Player 1 has in their hand" << endl;
  pptr2->dump();
  cout << "----------------------------\n" ;
  //********************

  //***** TESTING CRUNOSKIP ******  
  cout << "\nTesting CRUNOSKIP Card" << endl;
  cout << "----------------------------\n" ;
  Card * cptr6 = new CrunoSkip(2, CrunoSkip::SKIP);

  cout << "The current player is: " << gptr->currentPlayer() << endl;
  pptr1->takeCard(cptr6);

  cout << "Player 0 plays the skip card." << endl;
  cptr6->playCard(gptr,pptr1);

  cout << "The next player to play will be: " << gptr->nextPlayer() << endl;
  cout << "----------------------------\n" ;
  //*******************

  //***** TESTING CRUNOREVERSE *****
  cout << "\nTesting CRUNOREVERSE Card" << endl;
  cout << "----------------------------\n" ;

  Card *cptr7 = new CrunoReverse(2, CrunoReverse::REVERSE);
  
  cout << "The current player is: " << gptr->currentPlayer() << endl;
  pptr3->takeCard(cptr7);

  cout << "Player 2 plays the reverse card. " << endl;
  cptr7->playCard(gptr,pptr3);

  cout << "The next player to play will be: " << gptr->nextPlayer() << endl;
  cout << "----------------------------\n" ;
  //********************

  delete gptr;
  */
  return 0;
}
