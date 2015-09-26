#include "stdafx.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

//int main()
//{
//   int desiredSum;
//   std::cin >> desiredSum;
//   int numCoins;
//   std::cin >> numCoins;
//   int *coins = new int[numCoins];
//   for (int k = 0; k < numCoins; ++k) {
//      std::cin >> coins[k];
//   }
//
//   int **memo = new int*[desiredSum + 1];
//   for (int k = 0; k < desiredSum + 1; ++k) {
//      memo[k] = new int[numCoins];
//   }
//
//   // init memo
//   for (int k = 0; k < numCoins; ++k) {
//      memo[0][k] = 1; // if desiredSum is 0, there's only 1 way to get it
//   }
//
//   // building the memo
//   for (int k = 1; k < desiredSum + 1; ++k) {
//      for (int l = 0; l < numCoins; ++l) {
//         int leftIdx = l - 1;
//         int downIdx = k - coins[l];
//         int leftContribution = 0;
//         int downContribution = 0;
//
//         if (leftIdx >= 0)
//            leftContribution = memo[k][leftIdx];
//
//         if (downIdx >= 0)
//            downContribution = memo[downIdx][l];
//
//         memo[k][l] = leftContribution + downContribution;
//      }
//   }
//
//   std::cout << memo[desiredSum][numCoins - 1] << std::endl;
//
//   // cleanup
//   for (int k = 0; k < desiredSum + 1; ++k) {
//      delete[] memo[k];
//   }
//   delete[] memo;
//   delete[] coins;
//
//   return 0;
//}
