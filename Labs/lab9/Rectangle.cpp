
#include <iostream>
using namespace std;

#include "Rectangle.h"
#include "Shape.h"

Rectangle::Rectangle(int length, int width)
{
  m_length = length;
  m_width = width;
}

Rectangle::~Rectangle()
{
  cout << "The rectangle destructor was called." << endl;
}

int Rectangle::GetArea() const
{
  int area;

  area = m_length * m_width;
  
  return area;
} 

void Rectangle::Draw() const
{
  cout << "Drawing a rectangle...." << endl;
}
