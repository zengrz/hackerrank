#include "stdafx.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

//(i) She can give one chocolate to every colleague other than chosen one.
//(ii) She can give two chocolates to every colleague other than chosen one.
//(iii) She can give five chocolates to every colleague other than chosen one.

// equivalent to

//(i) She can take away one chocolate from the chosen one.
//(ii) She can take away two chocolates from the chosen one.
//(iii) She can take away five chocolates from the chosen one.

void GiveChocolates(int *chocolates, int numCointerns, int deniedIdx, int numChocolates)
{
   chocolates[deniedIdx] -= numChocolates;
}

bool AllEqual(int *chocolates, int numCointerns)
{
   for (int k = 1; k < numCointerns; ++k) {
      if (chocolates[k] != chocolates[k - 1])
         return false;
   }
   return true;
}

void StartDistributingChocolates(int *chocolates, int numCointerns)
{

}

//int main()
//{
//   int numTestCases;
//   std::cin >> numTestCases;
//   for (int k = 0; k < numTestCases; ++k) {
//      int numCointerns;
//      std::cin >> numCointerns;
//      int *chocolates = new int[numCointerns];
//
//      for (int l = 0; l < numCointerns; ++l) {
//         std::cin >> chocolates[l];
//      }
//
//      StartDistributingChocolates(chocolates, numCointerns);
//      delete[] chocolates;
//   }
//
//   return 0;
//}
