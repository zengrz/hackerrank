#include "stdafx.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

// think about how to use the memo, then think about how to update
void MaxSubArrayCont(int listLength, int *a, int *memo, int &maxSum)
{
   for (int l = 0; l < listLength; ++l) {
      if (memo[l] > a[l]) // just use the prev result
         continue;
      int curSum;
      for (int o = l; o < listLength; ++o) {
         if (o == l)
            curSum = a[l];
         else
            curSum += a[o];
         if (maxSum < curSum)
            maxSum = curSum;
         if (memo[o] < curSum)
            memo[o] = curSum;
      }
   }
}

void MaxSubArrayDisc(int listLength, int *a, int currIdx, int prevSum, int &maxSum, int *memo)
{
   if (currIdx >= listLength)
      return;

   int currSum = prevSum + a[currIdx];

   if (memo[currIdx] > currSum)
      return;
   memo[currIdx] = currSum;

   if (currSum > prevSum) {
      if (currSum > maxSum)
         maxSum = currSum;
      MaxSubArrayDisc(listLength, a, currIdx + 1, currSum, maxSum, memo);
   }
   else
   {
      if (prevSum > maxSum)
         maxSum = prevSum;
      MaxSubArrayDisc(listLength, a, currIdx + 1, prevSum, maxSum, memo);
   }
}

//int main()
//{
//   int numTestCases;
//   std::cin >> numTestCases;
//   for (int k = 0; k < numTestCases; ++k) {
//      int listLength;
//      std::cin >> listLength;
//      int *a = new int[listLength];
//      for (int l = 0; l < listLength; ++l) {
//         std::cin >> a[l];
//      }
//
//      int maxSum1 = 1 << sizeof(int) * 8 - 1;
//      int *memo1 = new int[listLength + 1];
//      for (int l = 0; l < listLength; ++l) {
//         memo1[l] =  1 << sizeof(int) * 8 - 1;
//      }
//      MaxSubArrayCont(listLength, a, memo1, maxSum1);
//      delete[] memo1;
//      std::cout << maxSum1 << " ";
//
//      int maxSum2 = 1 << sizeof(int) * 8 - 1;
//      int *memo2 = new int[listLength + 1];
//      for (int l = 0; l < listLength; ++l) {
//         memo2[l] = 1 << sizeof(int) * 8 - 1;
//      }
//      memo2[0] = a[0];
//      MaxSubArrayDisc(listLength, a, 1, a[0], maxSum2, memo2);
//      delete[] memo2;
//      std::cout << maxSum2 << std::endl;
//
//      delete[] a;
//   }
//   return 0;
//}
