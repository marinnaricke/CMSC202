
#include <iostream>
using namespace std;

#include "Shape.h"

Shape::~Shape()
{
// no code
}

void Shape::Draw() const
{
  // Write code here such that we can identify Shape's Draw is invoked
  cout << "Inside of Shape's Draw Function" << endl;
}
