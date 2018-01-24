// File:    Time.h
// Project: CMSC 202 Project 3, Spring 2016
// Author:  Marinna Ricketts-Uy
// Date:    3/31/16
// Section: 17
// E-mail:  pd12778@umbc.edu
//
// This file is used to represent train departure times, to do simple
// arithmetic with times, and to output times in a nice format

#ifndef TIME_H
#define TIME_H

#include <iostream>
using namespace std;

const int MAX_MINS        = 60; // amount of minutes in an hour
const int MAX_HOURS = 24; // amount of hours in a day


class Time 
{
  public:
  
  // Default constructor
  Time();

  // Non-default contructor
  Time( int hours, int minutes);

  // Name: operator<<
  // PreCondition:  time is an object with hours and minutes
  // PostCondition: Correctly prints the time object
  friend ostream& operator<<(ostream &outStream, const Time& time);

  // Name: operator+
  // PreCondition:  time is an object with hours and minutes
  // PostCondition: Returns a new Time object with the added minutes
  friend Time operator+ (const Time& time,int num);
  
  // Name: operator<
  // PreCondition:  time1 and time2 are time objects with hours and minutes
  // PostCondition: Returns true or false depending on if time1 < time2
  friend bool operator<(const Time& time1,const Time& time2);

  private:
  
  int m_hours; 
  int m_minutes;

};

#endif
