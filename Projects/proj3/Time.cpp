// File:    Time.cpp
// Project: CMSC 202 Project 3, Spring 2016
// Author:  Marinna Ricketts-Uy
// Date:    3/31/16
// Section: 17
// E-mail:  pd12778@umbc.edu
//
// This file is used to store, compare, and output times on a 24-hour clock.

#include <iostream>
#include <iomanip>
using namespace std;

#include "Time.h"

// Default Constructor
Time::Time()
{
  m_hours = 0;
  m_minutes = 0;
}

// Non-Default Constructor
Time::Time(int hours, int minutes)
{
  // Checking for validity
  if (hours >= 1 && hours <= MAX_HOURS &&
      minutes >= 0 && minutes <= 59)
    {
      m_hours = hours;
      m_minutes = minutes;
    }
  else
    {
      m_hours = 0;
      m_minutes = 0;
    }
}

// operator<<
// Overloaded insertion operator to print out the time object 
ostream& operator<<(ostream &outStream, const Time& time)
{
  // zero-padding
  outStream.fill('0');
  outStream << setw(2) << time.m_hours << ":" << setw(2) << time.m_minutes;
  
  return outStream;
}

// operator+
// Overloaded operator+ to add minutes to a time object
Time operator+(const Time& time,int num)
{
  int hours;
  int minutes;

  minutes = time.m_minutes + num;
  hours = time.m_hours;

  while (minutes >= MAX_MINS)
    {
      minutes -= MAX_MINS;
      hours += 1;
    }

  // Time cant go past 24:59, 25:00 for example is changed to 1:00
  if (hours > MAX_HOURS)
    {
      hours -= MAX_HOURS;
    }
  
  return Time(hours,minutes);
}

// operator<
// Overloaded operator< to check if a time is less than another time
bool operator<(const Time& time1,const Time& time2)
{
  if (time1.m_hours < time2.m_hours)
    {
      return true;
    }
  else if (time1.m_minutes < time2.m_minutes)
    {
      return true;
    }
  else 
    {
      return false;
    }
}
