#include <vector>
#include <iostream>
#include <string>

using namespace std;

class StackEmpty
{
public:

  StackEmpty(string message)
  {
    m_message = message;
  }

  string GetMessage()
  {
    return m_message;
  }

private:
  string m_message;

};

class StackFull
{
public:

  StackFull(string message, int argument)
  {
    m_message = message;
    m_argument = argument;
  }

  string GetMessage()
  {
    return m_message;
  }

  int GetValue()
  {
    return m_argument;
  }

private:
    string m_message;
    int m_argument;

};


class InvalidSize
{
public:

  InvalidSize(string message)
  {
    m_message = message;
  }

  string GetMessage()
  {
    return m_message;
  }

private:
  string m_message;

};

class IntStack
{
public:
  // MaxSize should be an unsigned int, but for the sake of example...
  IntStack(int MaxSize)
  {
    if(MaxSize < 0)
      {
	throw InvalidSize("Cannot create a negative size stack");
	
      }
		
    data.resize(MaxSize);
    cur_index = 0;
  }

  void push(int new_data)
  {
    if(cur_index == data.size())
      {
	throw StackFull("Push to full stack", cur_index);
      }
    else
      {
	data.at(cur_index) = new_data;
	cur_index++;
      }
  }

  int pop()
  {
    if(cur_index == 0)
      {
	throw StackEmpty("Pop from empty stack");
      }
    else
      {
	// pop off the int and return it
	cur_index--;
	return data.at(cur_index);
      }
  }

private:
  vector<int> data;
  unsigned int cur_index;
};

int main()
{
  // Testing Constructor
  try 
    {
      IntStack c_test(-10);

      c_test.push(3);
      c_test.push(4);
      c_test.pop();
      c_test.pop();
    }
  catch (InvalidSize e)
    {
      cerr << e.GetMessage() << endl;
    }	
	
  // Testing push
  try
    {
      IntStack push_test(5);
	
      for(unsigned int i = 0; i < 7; i++) {
	push_test.push(i);
      }
    }
  catch (StackFull e)
    {
      cerr << e.GetMessage() << ", value = " << e.GetValue() << endl;
    }	
	
  // Testing pop
  try
    {
      IntStack pop_test(2);
	
      pop_test.push(1);
      pop_test.push(2);
      pop_test.pop();
      pop_test.pop();
      pop_test.pop();
    }
  catch (StackEmpty e)
    {
      cerr << e.GetMessage() << endl;
    }
	
  cout << "Completed!" << endl;
}
