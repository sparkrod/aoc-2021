// reading a text file
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>


int main () {
  std::string line;
  std::ifstream myfile ("input.txt");
  if (myfile.is_open())
  {
    int accum = 0;
    double lastnumber = (double)INT_MAX;
    double currnumber = 0;
    bool started = false;
    
    while ( getline (myfile,line) )
    {
      currnumber = strtod(line.c_str(), NULL);
      
      if (currnumber > lastnumber) {
        accum++;
        std::cout << " (increased) total: " << accum;
      }
      else {
        std::cout << ((started) ? " (no increase)" : " (N/A - No previous measurement)");
      }
      std::cout << '\n';
      lastnumber = currnumber;   
      started = true;
    }
    myfile.close();
  }

  else std::cout << "Unable to open file"; 

  return 0;
}
