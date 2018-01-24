#include "Rectangle.h"
#include "Shape.h"
#include <iostream>

using namespace std;

Rectangle::Rectangle( ) : m_length(0), m_width(0) {}

Rectangle::Rectangle( int length, int width ) 
  : m_length(length), m_width(width) {}

int Rectangle::getArea( ) const {
  return m_length * m_width; 
}

void Rectangle::draw( ) const {
  cout << "Drawing a rectangle..." << endl; 
}

