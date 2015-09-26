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

//int main()
//{
//   int numTestCases;
//   std::cin >> numTestCases;
//   for (int k = 0; k < numTestCases; ++k) {
//      int numbricks;
//      std::cin >> numbricks;
//      int *bricks = new int[numbricks];
//      int *sumofallbricksuptilk = new int[numbricks];
//      for (int l = numbricks - 1; l >= 0; --l) {
//         std::cin >> bricks[l];
//      }
//      for (int l = 0; l < numbricks; ++l) {
//         if (l == 0)
//            sumofallbricksuptilk[l] = bricks[l];
//         else
//            sumofallbricksuptilk[l] = sumofallbricksuptilk[l - 1] + bricks[l];
//      }
//
//      int *maxsumuptilbrickk = new int[numbricks]; // if there's only k + 1 bricks. how many can the first player get when played optimally?
//
//      if (numbricks >= 1) maxsumuptilbrickk[0] = bricks[0];
//      if (numbricks >= 2) maxsumuptilbrickk[1] = bricks[0] + bricks[1];
//      if (numbricks >= 3) maxsumuptilbrickk[2] = bricks[0] + bricks[1] + bricks[2];
//
//      for (int l = 3; l < numbricks; ++l) {
//         int take1 = sumofallbricksuptilk[l - 1] - maxsumuptilbrickk[l - 1] + bricks[l];
//         int take2 = sumofallbricksuptilk[l - 2] - maxsumuptilbrickk[l - 2] + bricks[l] + bricks[l - 1];
//         int take3 = sumofallbricksuptilk[l - 3] - maxsumuptilbrickk[l - 3] + bricks[l] + bricks[l - 1] + bricks[l - 2];
//         int maxsum = std::max(take1, take2);
//         maxsum = std::max(maxsum, take3);
//         maxsumuptilbrickk[l] = maxsum;;
//      }
//
//      std::cout << maxsumuptilbrickk[numbricks - 1] << std::endl;
//
//      delete[] maxsumuptilbrickk;
//      delete[] bricks;
//   }
//
//   return 0;
//}
