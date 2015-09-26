#include "stdafx.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <sstream>
#include <iostream>
#include <istream>
#include <ostream>
#include <iterator>

#define NUM_BITS_PER_BYTE 8

void processStrings(std::string str1, std::string str2, const int s, int &l, int lsofar)
{
   // update important info
   ++l;

   // check to return
   if (str1.empty() || str2.empty()) {
      return;
   }

   // memo update or return

   // recurse
   //processStrings(str1.substr())
}

int main()
{
   int numTestCases;
   std::cin >> numTestCases;
   for (int k = 0; k < numTestCases; ++k) {
      int s;
      std::cin >> s;

      std::string line;
      std::getline(std::cin, line);

      // construct a stream from the string
      std::stringstream strline(line);

      // use stream iterators to copy the stream to the vector as whitespace separated strings
      std::istream_iterator<std::string> it(strline);
      std::istream_iterator<std::string> end;
      std::vector<std::string> results(it, end);

      std::string str1 = results.front();
      std::string str2 = results.back();

      int l;
      processStrings(str1, str2, s, l, 0);
      std::cout << l << std::endl;
   }

   return 0;
}
