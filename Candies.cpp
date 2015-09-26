#include "stdafx.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

// seed the first child and let it propagate

bool recurGiveCandies(int *ratings, int *candies, int curChildIdx, int numCandies, int numChildren)
{
   int prevRating = ratings[curChildIdx - 1];
   int curRating = ratings[curChildIdx];
   int nextRating = ratings[curChildIdx + 1];

   int prevCandies = candies[curChildIdx - 1];

   if (curChildIdx > 0) {
      if (prevRating > curRating && prevCandies <= numCandies)
         return false;
   }
   candies[curChildIdx] = numCandies;
   if (curChildIdx == numChildren - 1)
      return true;
   if (nextRating > curRating) {
      int k = 1;
      while (true) {
         if (recurGiveCandies(ratings, candies, curChildIdx + 1, numCandies + k, numChildren))
            return true;
         ++k;
      }
      return true;
   }
   else if (nextRating == curRating) {
      int k = 1;
      while (true) {
         if (recurGiveCandies(ratings, candies, curChildIdx + 1, k, numChildren))
            return true;
         ++k;
      }
   }
   else {
      for (int k = 1; k < numCandies; ++k) {
         if (recurGiveCandies(ratings, candies, curChildIdx + 1, k, numChildren))
            return true;
      }
      return recurGiveCandies(ratings, candies, curChildIdx, numCandies + 1, numChildren);
   }
}

//int main()
//{
//   int numChildren;
//   std::cin >> numChildren;
//   int *ratings = new int[numChildren];
//   for (int k = 0; k < numChildren; ++k) {
//      std::cin >> ratings[k];
//   }
//
//   int *candies = new int[numChildren];
//   for (int k = 0; k < numChildren; ++k) {
//      candies[k] = 0;
//   }
//
//   candies[0] = 1;
//   recurGiveCandies(ratings, candies, 0, 1, numChildren);
//
//   int sum = 0;
//   for (int k = 0; k < numChildren; k++) {
//      sum += candies[k];
//      //std::cout << candies[k] << " ";
//   }
//   //std::cout << std::endl;
//
//   std::cout << sum << std::endl;
//
//   delete[] candies;
//   delete[] ratings;
//
//   return 0;
//}
