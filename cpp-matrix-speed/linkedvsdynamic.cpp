#include <cmath>
#include <iostream>
#include <vector>

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
  double result = 0;
    for (double n : l)
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
  fill(myList);
  clock.tock();
  std::cout << "N=" << size
            << " mem: " << std::round(bytes / 1024 / 1024 * 100) / 100 << "mb"
            << " Mflops/s: " << std::round(flops / secs / 1000000)
            << " mem: " << std::round(bytes / secs / 1024 / 1024) << "mb/s"
            << " took " << secs << "s"
            << " runs: " << runs << " r=" << r << std::endl;
            
  int    runs = 1000000 / size;
  double r    = 1.0;
  for (int i = 0; i < runs; ++i)
    r += frob(mat);
  

  const double secs  = clock.duration().count() / 1000.0 / runs;
  const double bytes = 1.0 * sizeof(double) * size * size;
  const double flops = 3.0 * size * size;

  std::cout << "N=" << size
            << " mem: " << std::round(bytes / 1024 / 1024 * 100) / 100 << "mb"
            << " Mflops/s: " << std::round(flops / secs / 1000000)
            << " mem: " << std::round(bytes / secs / 1024 / 1024) << "mb/s"
            << " took " << secs << "s"
            << " runs: " << runs << " r=" << r << std::endl;
}

int
main()
{
  std::cout << "Using linked list, here are the result";
  test_linked();
  return 1;
}
