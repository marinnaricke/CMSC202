#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Shape.h"

class Triangle : public Shape
{
 public:
  Triangle( );
  Triangle( int base, int height );

  int getArea() const;
  void draw() const;

 private:
  int m_base;
  int m_height;
};

#endif
