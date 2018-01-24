#include<iostream>
using namespace std;

#include "Shape.h"
#include "Rectangle.h"
#include "Triangle.h"

int main()
{

  Shape *shapePtr;	       // Base class pointer 
  Rectangle aRectangle(5,4);  // creating a rectangle object
  Triangle aTriangle(4,4);    // creating a triangle object

  // Write code to perform dynamic binding here

  shapePtr = &aRectangle;
  cout << "Area for Rectangle: " << shapePtr->GetArea() << endl;
  shapePtr->Draw();

  shapePtr = &aTriangle;
  cout << "Area for Triangle: " << shapePtr->GetArea() << endl;
  shapePtr->Draw();
  
  return 0;
}

