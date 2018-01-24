//File: Fraction.cpp

#include "Fraction.h"
#include <iostream>

using namespace std;

const int DEFAULT_NUMER = 1;
const int DEFAULT_DENOM = 1;
//----------- Constructors -------------

//Default Constructor
Fraction::Fraction()
{
  m_numerator = DEFAULT_NUMER;
  m_denominator = DEFAULT_DENOM;
}

Fraction::Fraction(int numerator, int denominator)
{
  m_numerator = numerator;
  
  if (denominator != 0)
    {
       m_denominator = denominator;
    }
  else
    {
      cout << "Error, denominator not allowed" << endl;
    }
}

//------------ Functions --------------

// Output
void Fraction::Output()
{
  cout << m_numerator << "/" << m_denominator << endl;
}

// Reciprocal
Fraction Fraction::Reciprocal()
{
  Fraction recip(m_denominator,m_numerator);
  return recip;
}
