
#include <iostream>
using namespace std;

#include "Triangle.h"
#include "Shape.h"

Triangle::Triangle(int length = 0, int height = 0)
{
  m_length = length;
  m_height = height;
}

Triangle::~Triangle() 
{
  cout << "The triangle destructor was called." << endl;
}

int Triangle::GetArea() const 
{
  int area;
  
  area = (0.5) * (m_length) * (m_height);

  return area;
}

void Triangle::Draw() const
{
  cout << "Drawing a triangle...." << endl;
}
