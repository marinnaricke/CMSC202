#include <iostream>
#include "Complex.h"
using namespace std;

int main() {

  // To test your code, you must
  // - create at least three Complex numbers using
  //   the non-default constructor.
  Complex c1(3.4,5.6);
  Complex c2(6.5,2.3);
  Complex c3(5.4,10.3);
  
  // - Use the Multiply() function to compute the
  //   product of two Complex numbers; output the
  //   product using the ToString() function.
  Complex newComplex1 = c1.Multiply(c2);
  cout << newComplex1.ToString() << endl;

  // - Use the Multiply function to compute the 
  //   product of a Complex number and a double; 
  //   output the product using the ToString()
  //   function.
  Complex newComplex2 = c1.Multiply(2.2);
  cout << newComplex2.ToString() << endl;

  return 0;
}
  
