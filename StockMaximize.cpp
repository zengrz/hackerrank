#include "stdafx.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>

#define NUM_BITS_PER_BYTE 8

// maxprofit can only be known at the end
void findmaxprofit(int *shareprices, int numdays, int curday, int curprofit, long &maxprofit, int curnumshares, int *memo)
{
   // update important info
   if (maxprofit <= curprofit)
      maxprofit = curprofit;

   // check to return
   if (curday == numdays)
      return;

   // update memo
   if (curday > 0 && curnumshares == 0 && memo[curday] > curprofit)
      return;
   else
      memo[curday] = curprofit;

   // recurse
   int shareprice = shareprices[curday];
   findmaxprofit(shareprices, numdays, curday + 1, curprofit - shareprice, maxprofit, curnumshares + 1, memo); // buy a share
   if (curnumshares > 0) findmaxprofit(shareprices, numdays, curday + 1, curprofit + shareprice * curnumshares, maxprofit, 0, memo); // sell all shares
   findmaxprofit(shareprices, numdays, curday + 1, curprofit, maxprofit, curnumshares, memo); // not do anything

}

int findmaxpriceidx(int *shareprices, int numdays, int startday)
{
   int maxprice = shareprices[startday];
   int maxidx = startday;
   for (int k = startday + 1; k < numdays; ++k) {
      if (maxprice < shareprices[k]) {
         maxprice = shareprices[k];
         maxidx = k;
      }
   }
   return maxidx;
}

// maxprofit can only be known at the end
void findmaxprofit2(int *shareprices, int numdays, int curstartday, int curpofit, long &maxprofit)
{
   // update important info
   if (maxprofit <= curpofit)
      maxprofit = curpofit;

   // check to return
   if (curstartday == numdays)
      return;

   // recurse
   int maxday = findmaxpriceidx(shareprices, numdays, curstartday);

   if (maxday != curstartday) { // else not do anything
      int cost = 0;
      for (int k = curstartday; k < maxday; ++k) { // buy 1 share every day uptil that point
         cost += shareprices[k];
      }
      int numsharesbought = maxday - curstartday;
      int profit = shareprices[maxday] * numsharesbought - cost;

      curpofit += profit;
   }

   findmaxprofit2(shareprices, numdays, maxday + 1, curpofit, maxprofit);
}

//int main()
//{
//   int numTestCases;
//   std::cin >> numTestCases;
//   for (int k = 0; k < numTestCases; ++k) {
//      int numdays;
//      std::cin >> numdays;
//      int *shareprices = new int[numdays];
//      for (int l = 0; l < numdays; ++l) {
//         std::cin >> shareprices[l];
//      }
//      int *memo = new int[numdays]; // kth element contains the 
//      for (int k = 0; k < numdays; ++k) {
//         memo[k] = 1 << sizeof(int)*NUM_BITS_PER_BYTE - 1;
//      }
//
//
//      long maxprofit = 0;
//      findmaxprofit(shareprices, numdays, 0, 0, maxprofit, 0, memo);
//      //findmaxprofit2(shareprices, numdays, 0, 0, maxprofit);
//
//      std::cout << maxprofit << std::endl;
//
//      delete[] memo;
//      delete[] shareprices;
//   }
//
//   return 0;
//}
