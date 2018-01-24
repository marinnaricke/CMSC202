/* File:    mytest.cpp
   Project: CMSC 202 Project 5, Spring 2016
   Author:  Marinna Ricketts-Uy
   Date:    5/5/16
   Section: 17
   E-mail:  pd12778@umbc.edu

*/

#include <iostream>
using namespace std;

#include "sorted.h"

int main()
{
  sorted<int> x;
  
  sorted<int>::const_iterator itr;
  sorted<int>::rand_iterator rnditr;

  // **** Testing the const_iterator functions ****

  // ** Testing the insert function **
  cout << "Testing the insert function\n" << endl;
  
  // insert some values into x
  for (int i = 0; i < 10; i++)
    {
      x.insert( (i*i) % 23);
    }

  // ** Testing that the elements print in ascending order
  cout << "Testing that the elements print in ascending order\n" << endl;
  
  // sorted stores items in ascending order
  cout << "Items in x: ";
  for (itr = x.begin(); itr != x.end(); itr++)
    {
      cout << *itr << " ";
    }
  cout << endl << endl;

  // Checking the current capacity and size
  cout << "capacity of x is " << x.capacity() << endl;
  cout << "size of x is " << x.size() << endl << endl;

  // ** Testing that the erase function works **
  cout << "Testing that the erase function works\n" << endl;

  // erase() a couple items from x and print the result;
  // notice that erasing the item at index 2 changes
  // the value at index 7
  cout << "Now we will erase() some items in x..." << endl;
  int i = 0;
  for (itr = x.begin(); itr != x.end(); )
    {
      if (i == 2 || i == 4 || i == 7)
	{
	  itr = x.erase(itr);
	}
      else
	{
	  itr++;
	}
      i++;
    }

  // Again, checking if the elements are in ascending order

  cout << "Items in x: ";
  for (itr = x.begin(); itr != x.end(); itr++)
    {
      cout << *itr << " ";
    }
  cout << endl << endl;

  cout << "capacity of x is " << x.capacity() << endl;
  cout << "size of x is " << x.size() << endl << endl;

  cout << "Insert a few more items in x (21, -3, 9)..." << endl;
  
  x.insert(21);
  x.insert(-3);
  x.insert(9);
  x.insert(4);
  x.insert(-10);

  // Again, checking if the elements are in ascending order
  //  after inserting those elements

  cout << "Items in x: ";
  for (itr = x.begin(); itr != x.end(); itr++)
    {
      cout << *itr << " ";
    }
  cout << endl << endl;


  // **** Testing the rand_iterator functions ****

  // ** Testing if the elements print in a random order **

  cout << "Items in x using rand_iterator: ";
  for (rnditr = x.rndbegin(); rnditr != x.rndend(); rnditr++)
    {
      cout << *rnditr << " ";
    }
  cout << endl << endl;

  // ** Testing if the elements pring in a random order given a seed **

  cout << "Items in x using rand_iterator with seed 12345: ";
  for (rnditr = x.rndbegin(12345); rnditr != x.rndend(); rnditr++)
    cout << *rnditr << " ";
  cout << endl << endl;

  // Creating a new sorted<T> object of strings

  cout << "Create a 'playlist' of Kacey Musgraves songs..." << endl;

  sorted<string> kaceySongs;

  kaceySongs.insert("Follow Your Arrow");
  kaceySongs.insert("Merry Go 'Round");
  kaceySongs.insert("Biscuits");
  kaceySongs.insert("Blowin' Smoke");
  kaceySongs.insert("Family Is Family");
  kaceySongs.insert("Late to the Party");
  kaceySongs.insert("Keep It To Yourself");
  kaceySongs.insert("High Time");
  kaceySongs.insert("Cup of Tea");

  sorted<string>::const_iterator songitr;
  sorted<string>::rand_iterator rndsongitr;

  cout << endl;
  cout << "My Kacey Musgraves songs:" << endl;
  for ( songitr = kaceySongs.begin(); songitr != kaceySongs.end(); songitr++ )
    cout << "  " << *songitr << endl;

  cout << endl;

  // ** Testing that the songs print in a random order **

  cout << "My Kacey Musgraves songs shuffled:" << endl;
  for ( rndsongitr = kaceySongs.rndbegin(); rndsongitr != kaceySongs.rndend(); rndsongitr++ )
  cout << "  " << *rndsongitr << endl;
  cout << endl;

  // ** Testing  assignment operator **

  //sorted<string> test(kaceySongs);
  sorted<string> test;

  test = kaceySongs; 

  cout << "Testing operator= by creating a copy and then deleting "
       << "one item from copy..." << endl;

  // Delete a song from test; test and songs should be different
  songitr = test.begin();
  songitr++;
  songitr++;
  songitr++;
  test.erase(songitr);

  cout << endl;
  cout << "My Kacey Musgraves songs:" << endl;
  for ( songitr = kaceySongs.begin(); songitr != kaceySongs.end(); songitr++ )
    cout << "  " << *songitr << endl;

  cout << endl;
  cout << "My Kacey Musgraves songs (copy with 'Family Is Family' deleted):" << endl;
  for ( songitr = test.begin(); songitr != test.end(); songitr++ )
    cout << "  " << *songitr << endl;

  // ** Testing the exception class **
  cout << "\nTesting the exception class" << endl;

  // Testing that an error gets thrown because the size
  // of the sorted<T> object is changed and the permutation
  // is no longer valid
  cout << "Try inserting an item while usiing the rand_iterator: " << endl;

  try
    {
      // ** which should result in an error from exception class

      i = 0;
      for (rndsongitr = kaceySongs.rndbegin(); rndsongitr != kaceySongs.rndend(); )
	{
	  if ( i == 2)
	    {
	      kaceySongs.insert("Back on the Map");
	    }
	  else
	    {
	      rndsongitr++;
	    }
	  i++;
	}      
    }
  catch (iterator_ex e)
    {
      cerr << e.what() << endl;
    }

  // Testing that an error gets thrown because the size
  // of the sorted<T> object is changed and the permutation
  // is no longer valid
  cout << "\nErasing an item and then trying to use the rand_iterator: " << endl;

  try
    {
      sorted<string> errorTest;

      errorTest = kaceySongs; 

      songitr = errorTest.begin();
      rndsongitr = errorTest.rndbegin();
      songitr++;
      songitr++;
      songitr++;
      
      // Delete a song from errorTest
      errorTest.erase(songitr);
      
      // Try to increment the rand_iterator
      rndsongitr++;
    }
  catch (iterator_ex e)
    {
      cerr << e.what() << endl;
    }

  return 0;
}
