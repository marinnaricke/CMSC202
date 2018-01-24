#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"

class Rectangle : public Shape
{
 public:
  Rectangle( );
  Rectangle( int length, int width );
  
  int getArea( ) const;
  void draw( ) const;
  
 private:
  int m_length;
  int m_width;
};

#endif
