#include <iostream>
#include "hello_util.h"

using namespace std;

void hello( ) {
  cout << "Hello, world!" << endl;
}

void hello( string message ) {
  cout << "Hello, world!  I have a message for you:" << endl;
  cout << message << endl;
}
