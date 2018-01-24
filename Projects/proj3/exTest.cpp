#include <iostream>
using namespace std;

#include "Train.h"

int main()
{
  Train* train1 = new Train();

  train1->addCar(TrainCar::Locomotive);
  //train1->addCar(TrainCar::Locomotive);
  //train1->addCar(TrainCar::BusinessClass);
  train1->addCar(TrainCar::CoachClass);
  //train1->addCar(TrainCar::SleepingCar);
  //train1->addCar(TrainCar::DiningCar);
  train1->addCar(TrainCar::SnackCar);
  train1->addCar(TrainCar::SnackCar);

  cout << *train1 << endl;

  cout << "REMOVING SNACKCAR" << endl;
  train1->removeCar(TrainCar::SnackCar);
  cout << *train1 << endl;
  delete train1;
  train1 = NULL;

  return 0;
}
