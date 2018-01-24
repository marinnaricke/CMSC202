#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
 public:
  virtual int getArea() const = 0;
  virtual void draw() const;
};

#endif
