#include "stdafx.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

void knapsack(int listLength, int expectedSum, int *a, int *memo, int curSum, int& closestSum)
{
   if (curSum > expectedSum) // overshoot
      return;
   if (memo[curSum] != 0) // already visited
      return;
   memo[curSum] = 1;
   if (curSum > closestSum)
      closestSum = curSum;
   for (int k = 0; k < listLength; ++k) {
      knapsack(listLength, expectedSum, a, memo, curSum + a[k], closestSum);
   }
}

//int main() {
//   int numTestCases;
//   std::cin >> numTestCases;
//   for (int k = 0; k < numTestCases; ++k) {
//      int listLength, expectedSum;
//      std::cin >> listLength;
//      std::cin >> expectedSum;
//      int *a = new int[listLength];
//      for (int l = 0; l < listLength; ++l) {
//         std::cin >> a[l];
//      }
//      int *memo = new int[expectedSum + 1];
//      for (int l = 0; l < expectedSum + 1; ++l) {
//         memo[l] = 0;
//      }
//      int closestSum = 0;
//
//      knapsack(listLength, expectedSum, a, memo, 0, closestSum);
//
//      std::cout << closestSum << std::endl;
//
//      delete[] memo;
//      delete[] a;
//   }
//   return 0;
//}
