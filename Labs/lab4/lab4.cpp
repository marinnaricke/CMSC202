//File: lab4.cpp

#include "Fraction.h"

#include <iostream>
using namespace std;

int main()
{
  int numerator;
  int denominator;

  //Create 3 fractions:
  // - Read the first fraction from the keyboard using cin.
  cout << "Please enter a numerator: " << endl;
  cin >> numerator;
  cout << "Please enter a denominator: " << endl;
  cin >> denominator;

  // Find the reciprocal of this fraction and print it to the screen.
  cout << "\nThe Original of the first fraction:" << endl;
  Fraction frac(numerator, denominator);
  frac.Output();
  cout << "\nThe Reciprocal of the first fraction:" << endl;
  Fraction newFrac = frac.Reciprocal();
  newFrac.Output();

  // - The second fraction will be created with default values. You
  // should also print this to the screen.
  cout << "\nFraction created with the default values:" << endl;
  Fraction frac2;
  frac2.Output();

  // - Attempt to create a fraction with a denominator of zero, which
  // should print an error
  cout << "\nAttempting to create a fraction with a denominator of zero:" << endl;
  Fraction frac3(numerator, 0);

  return 0;
}
