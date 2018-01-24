#include "Triangle.h"
#include "Shape.h"
#include <iostream>

using namespace std;

Triangle::Triangle( ) : m_base(0), m_height(0) {}

Triangle::Triangle( int base, int height )
  : m_base(base), m_height(height) {}

int Triangle::getArea() const {
  int bh = m_base * m_height;
  if ( bh & 1 ) {
    cerr << "Error: Triangle::getArea(): area is not an integer value." 
	 << endl;
    return 0;
  } else {
    return bh / 2;
  }
}

void Triangle::draw() const {
  cout << "Drawing a triangle..." << endl;
}
