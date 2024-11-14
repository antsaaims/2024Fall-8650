#include <cmath>
#include <iostream>
#include <vector>
#include <list>
#include "timer.h"
// Fill a linked list
void
fill_linked(std::list<double> &myList)
{
  for (int i = 0; i < 1000000; ++i)
    {
      myList.push_back(i);
    }
}

// compute the the sum of all entries by looping over them
double
sum_entries_linked(std::list<double> &myList)
{
  double result = 0.0;
    for (double n : myList)
      result += n;
  return result;
}

void
test_linked()
{
  std::list<double> myList;
  // Filling and timin
  Timer<> clock; // Timer is defined in timer.h in the same folder
  // Let's time it:
  clock.tick();
  fill_linked(myList);
  clock.tock();
  const double secs  = clock.duration().count() / 1000.0; //the timer gives milliseconds

  std::cout << "Filling the linked list,  took " << secs << "s.\n";
  //Getting the sum of all entries
  clock.tick();
  int    runs = 100;
  double r    = 0.0;
  for (int i = 0; i < runs; ++i)
    r += sum_entries_linked(myList);
  clock.tock();
  double sec2  = clock.duration().count() / 1000.0 / runs;
  std::cout << "Compute the sum of all entries of a linked list by looping over them took " << sec2 << "s.\n";
}
//Now for std::vector
void
fill_vector(std::vector<double> &myVect)
{
  for (int i = 0; i < 1000000; ++i)
    {
      myVect.push_back(i);
    }
}

// compute the the sum of all entries by looping over them
double
sum_entries_vector(std::vector<double> &myVect)
{
  double result = 0.0;
    for (double n : myVect)
      result += n;
  return result;
}

void
test_vector()
{
  std::vector<double> myVect;
  // Filling and timin
  Timer<> clock; // Timer is defined in timer.h in the same folder
  // Let's time it:
  clock.tick();
  fill_vector(myVect);
  clock.tock();
  const double sec  = clock.duration().count() / 1000.0; //the timer gives milliseconds

  std::cout << "Filling the std::vector,  took " << sec << "s.\n";
  //Getting the sum of all entries
  clock.tick();
  int    runs = 100;
  double r    = 0.0;
  for (int i = 0; i < runs; ++i)
    r += sum_entries_vector(myVect);
  clock.tock();
  double secs  = clock.duration().count() / 1000.0 / runs;
  std::cout << "Compute the sum of all entries of the std:vector by looping over them took " << secs << "s.\n";
}
int
main()
{
  test_linked();
  test_vector();
  return 1;
}
