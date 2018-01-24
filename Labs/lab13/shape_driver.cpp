#include<iostream>
#include "Shape.h"
#include "Rectangle.h"
#include "Triangle.h"

using namespace std;

int main()
{

  Shape *shapePtr;	                   // Base class pointer 
  Rectangle* recPtr = new Rectangle(5,4);  // creating a rectangle object
  Triangle* triPtr = new Triangle(4,4);    // creating a triangle object

  shapePtr = recPtr;
  cout << "The shape's area is " << shapePtr->getArea() << endl;
  shapePtr->draw();
  delete shapePtr;

  cout << endl;

  shapePtr = triPtr;
  cout << "The shape's area is " << shapePtr->getArea() << endl;
  shapePtr->draw();
  delete shapePtr;

  return 0;
}

