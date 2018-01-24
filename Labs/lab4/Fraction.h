//File: Fraction.h

class Fraction {
 public:

  //----------- Constructors ---------

  //Default constructor
  Fraction();

  //Second constructor
  Fraction(int numerator, int denominator);

  //--------- Functions -------------

  //Name: Output
  void Output();

  //Name: Reciprocal
  Fraction Reciprocal();

 private:

  // Class Variables
  int m_numerator;
  int m_denominator;
};  
  
  
  
