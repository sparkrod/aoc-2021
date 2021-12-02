#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main () {
  std::string line;
  std::ifstream myfile ("input.txt");
  if (myfile.is_open())
  {
    int i = 0, accum = 0;
    double lastsum = (double)INT_MAX;
    double currsum = 0;
    bool started = false;
    std::vector<double> numvec;
    while ( getline (myfile,line) )
    {
      numvec.push_back(strtod(line.c_str(), NULL));
      if (i > 1) {
        currsum = numvec[i] + numvec[i-1] + numvec[i-2];
        if (currsum > lastsum) {
          accum++;
          std::cout << " (increased) total: " << accum;
        }
        else {
          std::cout << ((started) ? " (no increase)" : " (N/A - No previous measurement)");
        }
        std::cout << '\n';
        lastsum = currsum;
        started = true;
      }
      i++;
    }
    myfile.close();
  }

  else std::cout << "Unable to open file"; 

  return 0;
}
