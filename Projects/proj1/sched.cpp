// File:    sched.cpp
// Project: CMSC 202 Project 1, Spring 2016
// Author:  Marinna Ricketts-Uy
// Date:    2/23/16
// Section: 17
// E-mail:  pd12778@umbc.edu
//
// This program is an activity-scheduling program. The program schedules the 
// maximum number of events that a lecture hall can have for a given day
// depending on the start and end times of each event.

#include <iostream>
#include <iomanip>
#include <string>
#include "sched.h"

using namespace std;

// FUNCTION PROTOTYPES -- DO NOT CHANGE!

/* sort() - sorts an array of float returning sorted indices
   On return, indx[] is an array of indices such that data[indx[0]],
   data[indx[1]], ..., data[indx[len-1]] is data[] in ascending order.

 Parameters
   data[] - float array of data to be ordered
   indx[] - int array, same length as data[], to hold indices
   len - int specifying the length of data[] and indx[]
*/
void sort(float data[], int indx[], int len);

/* sched() - schedules events given start and end times, and indx[] from sort
   Returns number of events scheduled; on return, scheduled[] contains
   indices of scheduled events (e.g. startTime[scheduled[0]] is the start
   time of the first secheduled event).

 Parameters
   startTime[] - float array of event start times
   endTime[] - float array of event end times
   indx[] - array of indices that ordered the end times
   scheduled[] - int array to hold indices of scheduled events
   len - int specifying the length of the arrays

 Returns
   int value specifying number of events scheduled
*/

int sched(float startTime[], float endTime[], int indx[], int scheduled[], int len);

/* printEvent() - prints an event to the console
   Converts float start and end times to hh:mm format and prints times
   along with description. E.g. Study Session from 12.5 to 13.25 should
   print as "12:30 to 13:15 Study Session"

 Parameters
   startTime - float event start time
   endTime - float event end time
   description - string event description
*/

void printEvent(float startTime, float endTime, string description);

// MAIN PROGRAM - DO NOT CHANGE!

int main() 
{
  
  int indx[NUM_EVENTS];            // Array of indices of the end times
  int scheduledEvents[NUM_EVENTS]; // Array of indices of scheduled events
  int numSched;                    // Number of events scheduled

  // Sort by event ending times
  sort(endTime, indx, NUM_EVENTS);
  
  // Call greedy scheduling algorithm
  numSched = sched(startTime, endTime, indx, scheduledEvents, NUM_EVENTS);

  // Display scheduled events
  for (int i = 0; i < numSched; i++)
  
  {
    
    printEvent(startTime[scheduledEvents[i]], endTime[scheduledEvents[i]],
	       description[scheduledEvents[i]]);

  }

  return 0;
}

// sort
// Given the arrays, data and indx, and length of the arrays, returns void

void sort(float data[], int indx[], int len)
{

  int temp;
  
  // Fill the array from 0 to 9
  for (int i = 0; i < len; i++)
  
  {
    indx[i] = i;

  }

  // Sort end times from data[] in ascending order
  // Apply changes to indx[]
  for (int i = 0; i < len; i++)
  
  {
    for (int j = 0; j < len; j++)
    
    {

      if (data[indx[i]] < data[indx[j]])
      
      {	
	
	temp = indx[i];
	indx[i] = indx[j];
	indx[j] = temp;

      }
    }
  }
}

// sched
// Given startTime array, endTime array, indx array, scheduled array, 
// and length of the arrays, returns number of events scheduled

int sched(float startTime[], float endTime[], int indx[], int scheduled[], int len)
{
  
  int amountSched  = 1;         // Variable for number of events scheduled
  int currentSched = indx[0];   // Variable for first element in indx array
  
  scheduled[0] = currentSched; 

  // Check every element of the array
  for (int i = 1; i < len; i++)

  {
      // Add element to scheduled array
      if(startTime[indx[i]] >= endTime[currentSched])

      {
	
	scheduled[amountSched] = indx[i];
	currentSched = scheduled[amountSched];
	amountSched += 1;

      }
  }

  return amountSched;

}

// printEvent
// Given a float startTime, float endTime, and a string description,
// prints out each scheduled event, returns void

void printEvent(float startTime, float endTime, string description)
{

  int startHour = static_cast<int>(startTime);   // Hour for the start time
  int startMin  = (startTime - startHour) * MIN; // Minutes for the start time
  int endHour   = static_cast<int>(endTime);     // Hour for the end time
  int endMin    = (endTime - endHour) * MIN;     // Minutes for the end time
  
  cout.fill('0'); // Set fill character to 0
  cout << setw(2) << startHour << ":" << setw(2) << startMin << " - "
       << setw(2) << endHour << ":" << setw(2) << endMin << " "
       << description << endl;

}

